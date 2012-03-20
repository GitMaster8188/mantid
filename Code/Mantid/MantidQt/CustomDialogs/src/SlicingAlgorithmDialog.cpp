#include "MantidQtCustomDialogs/SlicingAlgorithmDialog.h"
#include "MantidAPI/AnalysisDataService.h"
#include "MantidAPI/IMDEventWorkspace.h"
#include "MantidAPI/AlgorithmManager.h"

using namespace Mantid::API;
using namespace Mantid::Geometry;

namespace MantidQt
{
  namespace CustomDialogs
  {
    DECLARE_DIALOG(SliceMDDialog);
    DECLARE_DIALOG(BinMDDialog);

    /**
    Constructor
    @param parent : parent widget
    */
    SlicingAlgorithmDialog::SlicingAlgorithmDialog(QWidget* parent) : AlgorithmDialog(parent)
    {
    }

    /// Set up the dialog layout
    void SlicingAlgorithmDialog::initLayout()
    {
      ui.setupUi(this);
      this->setWindowTitle(m_algName);

      connect(ui.workspace_selector,SIGNAL(activated(int)),this ,SLOT(onWorkspaceChanged()));
      connect(ui.controls, SIGNAL(accepted()), this, SLOT(accept()));
      connect(ui.controls, SIGNAL(rejected()), this, SLOT(reject()));
      connect(ui.ck_axis_aligned, SIGNAL(clicked(bool)), this, SLOT(onAxisAlignedChanged(bool)));

      ui.workspace_selector->setValidatingAlgorithm(m_algName);
      connect(ui.workspace_selector, SIGNAL(clicked()), this, SLOT(createMDWorkspaceClicked()));
      ui.workspace_selector->clear();
      typedef std::set<std::string> WorkspaceNames;
      WorkspaceNames names = AnalysisDataService::Instance().getObjectNames();
      WorkspaceNames::iterator it = names.begin();
      while(it != names.end())
      {
        IMDEventWorkspace_sptr ws = boost::dynamic_pointer_cast<IMDEventWorkspace>(AnalysisDataService::Instance().retrieve(*it));
        if(ws)
        {
          ui.workspace_selector->addItem((*it).c_str());
        }
        ++it;
      }

      buildDimensionInputs();
    }

    /// Destructor
    SlicingAlgorithmDialog::~SlicingAlgorithmDialog()
    {
    }

    /**
     Create a formatted string for the dimension input based on an existing dimension.
     @param dim : dimension to format to string.
    */
    QString formattedAlignedDimensionInput(Mantid::Geometry::IMDDimension_const_sptr dim)
    {
      QString min, max, nbins, result;
      QString name(dim->getName().c_str());
      min.setNum(dim->getMinimum());
      max.setNum(dim->getMaximum());
      nbins.setNum(dim->getNBins());
      result.append(name).append(",").append(min).append(",").append(max).append(",").append(nbins);
      return result;
    }

    /**
     Create a formatted string for the dimension input based on an existing dimension.
     @param dim : dimension to format to string.
    */
    QString formatNonAlignedDimensionInput(Mantid::Geometry::IMDDimension_const_sptr)
    {
      //Deliberately return an empty string here, because it's not obveious how the basis vectors could be automatically formed.
      return QString("");
    }
    
    /**
    Clears the layout of any qwidget
    @param layout : layout to clean
    */
    void SlicingAlgorithmDialog::cleanLayoutOfDimensions(QLayout* layout)
    {
      size_t itemCount = layout->count();
      for(size_t i = 0; i < itemCount; ++i)
      {
        QLayoutItem* pLayoutItem = layout->itemAt(i);
        QWidget* pWidget = pLayoutItem->widget();
        if (pWidget != NULL)
        {
          pWidget->setHidden(true);
          this->layout()->removeItem(pLayoutItem);
        }
      }
    }

    /**
    Find existing dimension widgets and get rid of them from the layout.
    */
    void SlicingAlgorithmDialog::clearExistingDimensions()
    {
      QLayout* alignedLayout = this->ui.axis_aligned_layout->layout();
      QLayout* nonAlignedLayout = this->ui.non_axis_aligned_layout->layout();

      cleanLayoutOfDimensions(alignedLayout);
      cleanLayoutOfDimensions(nonAlignedLayout);
    }

    /**
    Determine if the inputs should be in an axis aligned form.
    @return : True if axis aligned
    */
    bool SlicingAlgorithmDialog::doAxisAligned() const
    {
      return ui.ck_axis_aligned->isChecked();
    }

    /**
    Gets the provided input workspace name
    @return name of the input workspace
    */
    QString SlicingAlgorithmDialog::getInputWorkspaceName() const
    {
      return ui.workspace_selector->currentText();
    }

    /**
    Gets the provided output workspace name
    @return name of the output workspace
    */
    QString SlicingAlgorithmDialog::getOutputWorkspaceName() const
    {
      return ui.txt_output->text();
    }

    /*
    Decide and command the type of dimension inputs to provide.
    */
    void SlicingAlgorithmDialog::buildDimensionInputs()
    {
      clearExistingDimensions();
      const bool axisAligned = doAxisAligned();
      ui.non_axis_aligned_layout->setEnabled(!axisAligned);
      if(axisAligned)
      {
        buildDimensionInputs("AlignedDim", this->ui.axis_aligned_layout->layout(), formattedAlignedDimensionInput);
      }
      else
      {
        buildDimensionInputs("BasisVector", this->ui.non_axis_aligned_layout->layout(), formatNonAlignedDimensionInput);
      }
    }

    /**
    Build dimensions from the currently selected input workspace. Also fills
    the inputs with default values.
    @param propertyPrefix: The prefix for the property in the algorithm, i.e. AxisAligned.
    @param owningLayout: The layout that will take ownership of the widgets once generated.
    @param format: function pointer to the formatting function
    */
    void SlicingAlgorithmDialog::buildDimensionInputs(const QString& propertyPrefix, QLayout* owningLayout, QString(*format)(IMDDimension_const_sptr) )
    {
      const QString& txt = getInputWorkspaceName();
      if(!txt.isEmpty())
      {
        IMDWorkspace_sptr ws = boost::dynamic_pointer_cast<IMDWorkspace>(AnalysisDataService::Instance().retrieve(txt.toStdString()));
        size_t nDimensions = ws->getNumDims();
        for(size_t index = 0; index < nDimensions; ++index)
        {
          Mantid::Geometry::IMDDimension_const_sptr dim = ws->getDimension(index);
          
          // Create a widget to contain the dimension components.
          QHBoxLayout* layout = new QHBoxLayout;
          QWidget* w = new QWidget;
          w->setLayout(layout);

          // Configure the label 
          QString propertyName =  propertyPrefix.copy().append(QString().number(index));
          QLabel* dimensionLabel = new QLabel(propertyName);
          dimensionLabel->setToolTip(this->getAlgorithmProperty(propertyName)->documentation().c_str());
          
          // Configure the default input.
          QString dimensioninfo = format(dim);
          QLineEdit* txtDimension = new QLineEdit(dimensioninfo);

          // Add components to the layout.
          layout->addWidget(dimensionLabel);
          layout->addWidget(txtDimension);

          owningLayout->addWidget(w);
        }
      }
    }

    /// Event handler for the workspace changed event.
    void SlicingAlgorithmDialog::onWorkspaceChanged()
    {
      buildDimensionInputs();
    }

    /// Event handler for the axis changed event.
    void SlicingAlgorithmDialog::onAxisAlignedChanged(bool)
    {
      buildDimensionInputs();
    }

    PropertyDimensionMap SlicingAlgorithmDialog::extractDimensionInputs() const
    {
      PropertyDimensionMap result;
      QLayout* propertyLayout = NULL;
      if(doAxisAligned())
      {
        propertyLayout = ui.axis_aligned_layout->layout();
      }
      else
      {
        propertyLayout = ui.non_axis_aligned_layout->layout();
      }

      size_t layoutsize = propertyLayout->count();
      for(size_t i = 0; i < layoutsize; ++i)
      {
        QLayoutItem* item = propertyLayout->itemAt(i);
        QWidget* widget = item->widget();
        if(widget)
        {
          QLabel* propertyLabel = dynamic_cast<QLabel*>(widget->layout()->itemAt(0)->widget());
          QLineEdit* propertyValue = dynamic_cast<QLineEdit*>(widget->layout()->itemAt(1)->widget());
          result.insert(propertyLabel->text(), propertyValue->text());
        }
      }
      return result;
    }

    /// Accept dialog event handler
    void SlicingAlgorithmDialog::accept()
    {
      this->m_algorithm->setPropertyValue("InputWorkspace", getInputWorkspaceName().toStdString());
      this->m_algorithm->setPropertyValue("OutputWorkspace", getOutputWorkspaceName().toStdString());
      this->m_algorithm->setProperty("AxisAligned", doAxisAligned());
      if(doAxisAligned())
      {
        PropertyDimensionMap map = extractDimensionInputs();
        PropertyDimensionMap::const_iterator it = map.constBegin();
        while(it != map.constEnd())
        {
          this->m_algorithm->setProperty(it.key().toStdString(), it.value().toStdString());
          ++it;
        }
      }

      this->m_algorithm->execute();

      this->close();
    }

  }
}