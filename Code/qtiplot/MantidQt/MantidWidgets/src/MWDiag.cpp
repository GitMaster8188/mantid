#include "MantidQtMantidWidgets/MWDiag.h"
#include "MantidQtMantidWidgets/MWDiagCalcs.h"
#include "MantidQtAPI/AlgorithmInputHistory.h"
#include "MantidAPI/FrameworkManager.h"
#include "MantidKernel/Exception.h"
#include <QSignalMapper>
#include <QFileInfo>
#include <QFileDialog>
#include <QDir>
#include <QStringList>
#include <QMessageBox>
#include <vector>
#include <string>

using namespace Mantid::Kernel;
using namespace MantidQt::API;
using namespace MantidQt::MantidWidgets;

// default parameters writen to in the GUI
static const bool G_NO_SOLIDS = false;
static const char G_HIGH_ABSOLUTE[5] = "1e10";
static const char G_LOW_ABSOLUTE[2] = "0";
static const char G_SIGNIFIC_TEST[4] = "3.3";
static const char G_HIGH_MEDIAN[4] = "3.0";
static const char G_LOW_MEDIAN[4] = "0.1";
static const char G_VARIATION[4] = "1.1";
static const bool G_CHECK_BACK = true;
static const char G_BACK_CRITERIA[4] = "5.0";
static const double G_START_WINDOW_TOF = 18000;
static const double G_END_WINDOW_TOF = 19500;
static const bool G_NO_ZERO_BG = true;

MWDiag::MWDiag(QWidget *parent, QString prevSettingsGr, const QComboBox * const instru):
  m_dispDialog(NULL), m_instru(instru), m_WBVChanged(false),
  m_TOFChanged(false), m_sTOFAutoVal(-1), m_eTOFAutoVal(-1)
{
  // allows saving and loading the values the user entered on to the form
  m_prevSets.beginGroup(prevSettingsGr);
  
  m_designWidg.setupUi(this);
  insertFileWidgs();
  loadDefaults();
  setupToolTips();
  connectSignals(parent);
  setUpValidators();
}
void MWDiag::insertFileWidgs()
{
  // we create and place some new widgets on the form using it's grid layout
  QLayout *mapLayout = m_designWidg.gbVariation->layout();
  QGridLayout *mapLay = qobject_cast<QGridLayout*>(mapLayout); 
  // this requires that the form was setup with a grid layout
  if ( ! mapLay )
  { // if you see the following exception check that the group box gbExperiment has a grid layout
    throw Exception::NullPointerException("Problem with the layout in MWDiag", "mapLay");
  }
  
  m_WBV2 = new MWRunFile(this, m_prevSets.group()+"/WBV2", m_instru, "WhiteBeamVan 2",
    "The name of a white beam vanadium run from the same instrument as the first");
  mapLay->addWidget(m_WBV2, 0, 0, 1, 4);
}
/// loads default values into each control using either the previous value used when the form was run or the default value for that control
void MWDiag::loadDefaults()
{  
  m_designWidg.leIFile->setText(
    m_prevSets.value("input mask", "").toString());
  m_designWidg.leSignificance->setText(
    m_prevSets.value("significance", G_SIGNIFIC_TEST).toString());
  m_designWidg.ckAngles->setChecked(
    m_prevSets.value("no solid", G_NO_SOLIDS).toBool());

  m_designWidg.leHighAbs->setText(
    m_prevSets.value("high abs", G_HIGH_ABSOLUTE).toString());
  m_designWidg.leLowAbs->setText(
    m_prevSets.value("low abs", G_LOW_ABSOLUTE).toString());
  m_designWidg.leHighMed->setText(
    m_prevSets.value("high median", G_HIGH_MEDIAN).toString());
  m_designWidg.leLowMed->setText(
    m_prevSets.value("low median", G_LOW_MEDIAN).toString());

  m_designWidg.leVariation->setText(
    m_prevSets.value("variation", G_VARIATION).toString());

  m_designWidg.ckDoBack->setChecked(
    m_prevSets.value("test background", G_CHECK_BACK).toBool());
  m_designWidg.leAcceptance->setText(
    m_prevSets.value("back criteria", G_BACK_CRITERIA).toString());
  m_designWidg.ckZeroCounts->setChecked(
    m_prevSets.value("no zero background", G_NO_ZERO_BG).toBool());
  m_designWidg.leStartTime->setText(
    m_prevSets.value("TOF start", G_START_WINDOW_TOF).toString());
  m_designWidg.leEndTime->setText(
    m_prevSets.value("TOF end", G_END_WINDOW_TOF).toString());
}
/// loads default values into each control using either the previous value used when the form was run or the default value for that control
void MWDiag::saveDefaults()
{
  m_prevSets.setValue("input mask", m_designWidg.leIFile->text());
  m_prevSets.setValue("significance", m_designWidg.leSignificance->text());
  m_prevSets.setValue("no solid", m_designWidg.ckAngles->isChecked());
  
  m_prevSets.setValue("high abs", m_designWidg.leHighAbs->text());
  m_prevSets.setValue("low abs", m_designWidg.leLowAbs->text());
  m_prevSets.setValue("high median", m_designWidg.leHighMed->text());
  m_prevSets.setValue("low median", m_designWidg.leLowMed->text());
  
  m_prevSets.setValue("variation", m_designWidg.leVariation->text());
  
  m_prevSets.setValue("test background", m_designWidg.ckDoBack->isChecked());
  m_prevSets.setValue("back criteria", m_designWidg.leAcceptance->text());
  m_prevSets.setValue("no zero background",
    m_designWidg.ckZeroCounts->isChecked());
  m_prevSets.setValue("TOF start", m_designWidg.leStartTime->text());
  m_prevSets.setValue("TOF end", m_designWidg.leEndTime->text());
}
/// runs setToolTip() on each of the controls on the form  
void MWDiag::setupToolTips()
{  
  QString iFileToolTip = "A file containing a list of spectra numbers which we aleady know should be masked";
  m_designWidg.lbIFile->setToolTip(iFileToolTip);
  m_designWidg.leIFile->setToolTip(iFileToolTip);
  m_designWidg.pbIFile->setToolTip(iFileToolTip);
  
  QString oFileToolTip =
    "The name of a file to write the spectra numbers of those that fail a test";
  m_designWidg.lbOFile->setToolTip(oFileToolTip);
  m_designWidg.leOFile->setToolTip(oFileToolTip);
  m_designWidg.pbOFile->setToolTip(oFileToolTip);
  
  QString significanceToolTip =
    "Spectra with integrated counts within this number of standard deviations from\n"
    "the median will not be labelled bad (sets property SignificanceTest when\n"
    "MedianDetectorTest is run)";
  m_designWidg.leSignificance->setToolTip(significanceToolTip);
  m_designWidg.lbSignificance->setToolTip(significanceToolTip);
//-------------------------------------------------------------------------------------------------
  QString WBV1ToolTip =
    "The name of a white beam vanadium run from the instrument of interest";
  m_designWidg.lbWBV1->setToolTip(WBV1ToolTip);
  m_designWidg.leWBV1->setToolTip(WBV1ToolTip);
  m_designWidg.pbWBV1->setToolTip(WBV1ToolTip);

  QString highAbsSetTool =
    "Reject any spectrum that contains more than this number of counts in total\n"
    "(sets property HighThreshold when FindDetectorsOutsideLimits is run)";
  m_designWidg.leHighAbs->setToolTip(highAbsSetTool);
  m_designWidg.lbHighAbs->setToolTip(highAbsSetTool);
  
  QString lowAbsSetTool =
    "Reject any spectrum that contains less than this number of counts in total\n"
    "(sets property LowThreshold when FindDetectorsOutsideLimits is run)";
  m_designWidg.leLowAbs->setToolTip(lowAbsSetTool);
  m_designWidg.lbLowAbs->setToolTip(lowAbsSetTool);

  QString highMedToolTip =
    "Reject any spectrum whose total number of counts is more than this number of\n"
    "times the median total for spectra (sets property HighThreshold when\n"
    "MedianDetectorTest is run)";
  m_designWidg.leHighMed->setToolTip(highMedToolTip);
  m_designWidg.lbHighMed->setToolTip(highMedToolTip);

  QString lowMedToolTip =
    "Reject any spectrum whose total number of counts is less than this number of\n"
    "times the median total for spectra (sets property LowThreshold when\n"
    "MedianDetectorTest is run)";
  m_designWidg.leLowMed->setToolTip(lowMedToolTip);
  m_designWidg.lbLowMed->setToolTip(lowMedToolTip);

  QString variationToolTip = 
    "When comparing equilivient spectra in the two white beam vanadiums reject any\n"
    "whose the total number of counts varies by more than this multiple of the\n"
    "medain variation (sets property Variation when DetectorEfficiencyVariation is\n"
    "is run)";
  m_designWidg.leVariation->setToolTip(variationToolTip);
  m_designWidg.lbVariation->setToolTip(variationToolTip);

  QString acceptToolTip =
    "Spectra whose total number of counts in the background region is this number\n"
    "of times the median number of counts would be marked bad (sets property\n"
    "HighThreshold when MedianDetectorTest is run)";
  m_designWidg.lbAcceptance->setToolTip(acceptToolTip);
  m_designWidg.leAcceptance->setToolTip(acceptToolTip);

  QString startTToolTip =
    "An x-value in the bin marking the start of the background region, the\n"
    "selection is exclusive (RangeLower in MedianDetectorTest)";
  m_designWidg.lbStartTime->setToolTip(startTToolTip);
  m_designWidg.leStartTime->setToolTip(startTToolTip);
  QString endTToolTip =
    "An x-value in the bin marking the the background region's end, the selection\n"
    "is exclusive (RangeUpper in MedianDetectorTest)";
  m_designWidg.lbEndTime->setToolTip(endTToolTip);
  m_designWidg.leEndTime->setToolTip(endTToolTip);
  m_designWidg.ckZeroCounts->setToolTip(
    "Check this and spectra with zero counts in the background region will be"
    "considered bad");
}
void MWDiag::connectSignals(const QWidget * const parentInterface)
{// connect all the open file buttons to an open file dialog connected to it's line edit box
  QSignalMapper *signalMapper = new QSignalMapper(this);
  signalMapper->setMapping(m_designWidg.pbIFile, QString("InputFile"));
  signalMapper->setMapping(m_designWidg.pbOFile, QString("OutputFile"));
  signalMapper->setMapping(m_designWidg.pbWBV1, QString("WBVanadium1"));
  connect(m_designWidg.pbIFile, SIGNAL(clicked()), signalMapper, SLOT(map()));
  connect(m_designWidg.pbOFile, SIGNAL(clicked()), signalMapper, SLOT(map()));
  connect(m_designWidg.pbWBV1, SIGNAL(clicked()), signalMapper, SLOT(map()));
  
  connect(signalMapper, SIGNAL(mapped(const QString &)),
         this, SLOT(browseClicked(const QString &)));

  // signals connected to the interface that this form is on
  if ( parentInterface != NULL )
  {
    connect(this, SIGNAL(runAsPythonScript(const QString&)),
            parentInterface, SIGNAL(runAsPythonScript(const QString&)));

	// controls that copy the text from other controls
    connect(m_designWidg.leWBV1, SIGNAL(editingFinished()), this, SLOT(WBVUpd()));
    connect(parentInterface, SIGNAL(MWDiag_updateWBV(const QString&)), this, SLOT(updateWBV(const QString&)));
    connect(parentInterface, SIGNAL(MWDiag_updateTOFs(const double &, const double &)),
	        this, SLOT(updateTOFs(const double &, const double &)));
    connect(m_designWidg.leStartTime, SIGNAL(editingFinished()), this, SLOT(TOFUpd()));
    connect(m_designWidg.leEndTime, SIGNAL(editingFinished()), this, SLOT(TOFUpd()));

    connect(parentInterface, SIGNAL(MWDiag_sendRuns(const std::vector<std::string> &)),
	  this, SLOT(specifyRuns(const std::vector<std::string> &)));
  }
}
void MWDiag::setUpValidators()
{
  m_validators.clear();

  setupValidator(m_designWidg.valErr);
  m_validators[m_designWidg.leSignificance] = m_designWidg.valErr;
  setupValidator(m_designWidg.valInmsk);
  m_validators[m_designWidg.leIFile] = m_designWidg.valInmsk;


  m_validators[m_designWidg.leHighAbs] = newStar(m_designWidg.gbIndividual, 2,1);
  m_validators[m_designWidg.leLowAbs] = newStar(m_designWidg.gbIndividual, 1, 5);
  m_validators[m_designWidg.leHighMed] = newStar(m_designWidg.gbIndividual, 2,1);
  m_validators[m_designWidg.leLowMed] = newStar(m_designWidg.gbIndividual, 2, 5);

  m_validators[m_designWidg.leVariation] = newStar(m_designWidg.gbVariation,2,1);

  m_validators[m_designWidg.leAcceptance] = newStar(m_designWidg.gbBackTest,0,3);
  m_validators[m_designWidg.leStartTime] = newStar(m_designWidg.gbBackTest, 1,1);
  m_validators[m_designWidg.leEndTime] = newStar(m_designWidg.gbBackTest, 1, 5);

  hideValidators();
}
//this function will be replaced a function in a widget
void MWDiag::browseClicked(const QString &buttonDis)
{
  QLineEdit *editBox;
  QStringList extensions;
  bool toSave = false;
  if ( buttonDis == "InputFile")
  {
    editBox = m_designWidg.leIFile;
  }
  if ( buttonDis == "OutputFile")
  {
    editBox = m_designWidg.leOFile;
    extensions << "msk";
    toSave = true;
  }
  if ( buttonDis == "WBVanadium1")
  {
    editBox = m_designWidg.leWBV1;
	extensions << "raw" << "RAW" << "NXS" << "nxs";
  }

  QString filepath = openFileDialog(toSave, extensions);
  if( filepath.isEmpty() ) return;
  editBox->setText(filepath);
  
  if ( buttonDis == "WBVanadium1")
  {
    WBVUpd();
  }
}
/** create, setup and show a dialog box that reports the number of bad
* detectors.
*/
void MWDiag::raiseDialog()
{// uses new to create the form but the form should have setAttribute(Qt::WA_DeleteOnClose) and so the memory will be freed
  m_dispDialog = new DiagResults(this);
  m_dispDialog->show();
  connect(m_dispDialog, SIGNAL(died()), this, SLOT(noDispDialog()));
}
/** checks that the results dialog box hasn't been closed before asking it to display
*  data
*  @param display the results from running an individual test
*  @throw NullPointer if the dialog box had already been closed
*/
void MWDiag::notifyDialog(const DiagResults::TestSummary &display)
{
  if ( ! m_dispDialog )
  {
    throw Exception::NullPointerException("MWDiag::notifyDialog", "m_dispDialog");
  }
  m_dispDialog->notifyDialog(display);
}
/** close the results window, if there is one open
*/
void MWDiag::closeDialog()
{
  if (m_dispDialog)
  {
    m_dispDialog->close();
  }
}
// ??STEVES?? move this function to the file widget?
QString MWDiag::openFileDialog(const bool save, const QStringList &exts)
{
  QString filter;
  if ( !exts.empty() )
  {
    filter = "Files (";
    for ( int i = 0; i < exts.size(); i ++ )
    {
      filter.append("*." + exts[i] + " ");
    }
    filter.trimmed();
    filter.append(")");
  }
  filter.append(";;All Files (*.*)");

  QString filename;
  if( save )
  {
    filename = QFileDialog::getSaveFileName(this, "Save file",
	  m_prevSets.value("save file dir", "").toString(), filter);
	if( ! filename.isEmpty() )
	{
	  m_prevSets.setValue("save file dir", QFileInfo(filename).absoluteDir().path());
	}
  }
  else
  {
    filename = QFileDialog::getOpenFileName(this, "Open file",
	  m_prevSets.value("load file dir", "").toString(), filter);
	if( ! filename.isEmpty() )
	{
	  m_prevSets.setValue("load file dir", QFileInfo(filename).absoluteDir().path());
	}
  }
  return filename;
} 
/**raise the window containing the results summary, run the Python scripts that
*  have been created and, optionally on success, save the values on the form 
*  @param saveSettings if the Python executes successfully and this parameter is true the settings are saved
*  @return this method catches many exceptions and a description of the any problem found is returned here
*/
QString MWDiag::run(const QString &outWS, const bool saveSettings)
{
  // close any result window that is still there from a previous run, there might be nothing
  closeDialog();
  hideValidators();
  // prepare to remove any intermediate workspaces used only during the calculations
  std::vector<std::string> tempOutputWS;

  // these objects read the user settings in the GUI on construction
  whiteBeam1 firstTest(this, m_designWidg);
  
  QString prob1 = firstTest.checkNoErrors(m_validators);
  
  // the two tests below are optional, dependent on the information supplied by the user
  boost::shared_ptr<whiteBeam2> optional1;
  QString prob2 = possibleSecondTest(optional1);
  boost::shared_ptr<backTest> optional2;
  QString prob3 = possibleThirdTest(optional2);
  
  // stars have already been placed next to any problem input, if were errors return a description of the first error
  if ( ! prob1.isEmpty() )
  {
    return "In detector test:\n" + prob1;
  }
  if ( ! prob2.isEmpty() )
  {
    return "In detector test:\n" + prob2;
  }
  if ( ! prob3.isEmpty() )
  {
    return "In detector test:\n" + prob3;
  }

  // the input is good bring up the status window
  raiseDialog();
  // run things that are dependent on the dialog box being present, it is deleted whenever the user closes it!
  try 
  {
    DiagResults::TestSummary sumFirst = singleWhiteBeamTest(firstTest);

    // the final test contains the definitive data, we'll only know which test was the last at the end, we'll keep on updating this pointer
    DiagResults::TestSummary *finalTest = &sumFirst;
    // must have the same scope as finalTest above, these structures are used to report progress and pass results from one test to another
    DiagResults::TestSummary sumOption1("");
    DiagResults::TestSummary sumOption2("");
	tempOutputWS.push_back(sumFirst.inputWS.toStdString());

    if ( optional1.use_count() > 0 )
    {
      sumOption1 = whiteBeamCompTest(sumFirst, optional1);
	  finalTest = &sumOption1;
	  tempOutputWS.push_back(sumOption1.inputWS.toStdString());
    }

    if ( optional2.use_count() > 0 )
    {
      sumOption2 = backGroundTest(sumFirst, sumOption1, optional2);
	  finalTest = &sumOption2;
	}
	
  //  the test are complete display and save output
	if ( ! outWS.isEmpty() )
    {
      renameWorkspace(finalTest->outputWS, outWS);
	  finalTest->outputWS = outWS;
    }
    notifyDialog(*finalTest);
  }
  catch ( Exception::NullPointerException )
  {// the diag has died, probably the user closed it
    prob1 = "Dialog box died";
  }
  catch (std::runtime_error &e)
  {
    prob1 = QString("Exception \"") + QString(e.what()) + QString("\" encountered running detector diagnostic tests");
	QMessageBox::critical(this, "", prob1);
    return prob1;
  }

  // clean up tempory workspaces that were used in the calculations
  std::vector<std::string>::const_iterator it = tempOutputWS.begin();
  for ( ; it !=  tempOutputWS.end(); ++it )
  {
    Mantid::API::FrameworkManager::Instance().deleteWorkspace(*it);
  }
 
  if (prob1.isEmpty() && saveSettings)
  {// avoids saving user settings that caused errors
    saveDefaults();
  }
  
  // if this method has continued running to this point it's likely taht problem=""
  return prob1;
}
/** Pointers the passed pointer to an object will contain all the Python script for
*  the two white beam vanadium detector test
*  @param whiteBeamComp will be pointered to a valid whiteBeam2 object
*  @return any errors or an empty string for no error
*/
QString MWDiag::possibleSecondTest(boost::shared_ptr<whiteBeam2> &whiteBeamComp)
{  
  if ( ! m_WBV2->getFileName().isEmpty() )
  {// the user has supplied an input file for the second test so fill the shared_ptr with the script
    whiteBeamComp.reset(
	  new whiteBeam2(this, m_designWidg, m_WBV2->getFileName()));
	//report any problems trying to construct it, likely to be problems with the values suggested by the user
    return whiteBeamComp->checkNoErrors(m_validators);
  }
  return "";
}
/** Pointers the passed pointer to an object will contain all the Python script for
*  the detector test based on background values
*  @param backCheck will be pointered to a valid backTest object
*  @return any errors or an empty string for no error
*/
QString MWDiag::possibleThirdTest(boost::shared_ptr<backTest> &backCheck)
{
  if (m_designWidg.ckDoBack->isChecked())
  { //generate a Python script
    backCheck.reset(new backTest(this, m_designWidg, m_monoFiles));
	//report any problems trying to construct it, likely to be problems with the values suggested by the user
	return backCheck->checkNoErrors(m_validators);
  }
  return "";
}
/** Executes the Python script constructed for the first white beam vanadium test
*  @param python this object contains a script constructed for this test
*  @return summary data of the test results
*  @throw invalid_argument if an exception was thrown during execution of the Python
*/
DiagResults::TestSummary MWDiag::singleWhiteBeamTest(whiteBeam1 &python)
{
  DiagResults::TestSummary results("First white beam test");
  // report to the dialog what's happening
  results.status = "Analysing white beam vanadium 1";
  notifyDialog(results);
  
  // use this code to see the script   QMessageBox::critical(this, this->windowTitle(), firstTest.python());
  QString error = results.pythonResults(python.run());
  notifyDialog(results);
  
  if ( ! error.isEmpty() )
  {
    throw std::invalid_argument(error.toStdString());
  }
  return results;
}
/** Adds data from the first test to the script that was built up for the white beam comparison test
*  and executes the comparison test
*  @param firstTest the results from a single white beam vanadium test
*  @param python this object contains a script constructed for this test
*  @return summary data of the test results
*  @throw invalid_argument if an exception was thrown during execution of the Python
*/
DiagResults::TestSummary MWDiag::whiteBeamCompTest(const DiagResults::TestSummary firstTest, boost::shared_ptr<whiteBeam2> &python)
{
  DiagResults::TestSummary results("Second white beam test");
  results.status = "Analysing white beam vanadium 2 and comparing";
  notifyDialog(results);

  // adds the output workspace from the first test to the current script
  python->incPrevious(firstTest);
  //uncomment out to check the script QMessageBox::critical(this, this->windowTitle(), python->python());
  QString error = results.pythonResults(python->run());
  notifyDialog(results);

  if ( ! error.isEmpty() )
  {
    throw std::invalid_argument(error.toStdString());
  }
  return results;
}
/** Adds data from the first test and second tests (the second test results can be default if there was no test to the
*  script built for the background test and execute the script
*  @param firstTest the results from a single white beam vanadium test
*  @param secondTest the results from a white beam comparison test, if this is a default results summary then no second test data is used
*  @param python this object contains a script constructed for this test
*  @return summary data of the test results
*  @throw invalid_argument if an exception was thrown during execution of the Python
*/
DiagResults::TestSummary MWDiag::backGroundTest(const DiagResults::TestSummary &firstTest, const DiagResults::TestSummary &secondTest, boost::shared_ptr<backTest>& python)
{
  DiagResults::TestSummary results("Background test");
  results.status = "Analysing the background regions of experimental runs";
  notifyDialog(results);
  
  python->incFirstTest(firstTest); 
  if ( secondTest.status != "Error" )
  {
    python->incSecondTest(secondTest);
  }
  else
  {
    python->noSecondTest();
  }

  QString error = results.pythonResults(python->run());// uncomment out this to see the script    QMessageBox::critical(this, this->windowTitle(), python->python());
  notifyDialog(results);

  if ( ! error.isEmpty() )
  {
    throw std::invalid_argument(error.toStdString());
  }
  return results;
}
/** Called when the user selects a white beam vanadium run on a different form, it copies
*  the filename over
*  @param WBVSuggestion the user selected white beam vanadium filename
*/
void MWDiag::updateWBV(const QString &WBVSuggestion)
{// if the user added their own value don't change it
  m_WBVAutoVal = WBVSuggestion;
  if ( ! m_WBVChanged ) 
  {
    m_designWidg.leWBV1->setText(m_WBVAutoVal);
  }
}
/** Called when the user identifies the background region in a different form, it copies the values over
*  @param start the TOF value of the start of the background region
*  @param end the TOF value of the end of the background region
*/
void MWDiag::updateTOFs(const double &start, const double &end)
{// if the user added their own value don't change it
  m_sTOFAutoVal = start;
  m_eTOFAutoVal = end;
  if ( ! m_TOFChanged ) 
  {
    m_designWidg.leStartTime->setText(QString::number(start));
	m_designWidg.leEndTime->setText(QString::number(end));
  }
}
/** This slot sets m_monoFiles based on the array that is
*  passed to it
*  @param runFileNames names of the files that will be used in the background test
*/
void MWDiag::specifyRuns(const std::vector<std::string> &runFileNames)
{
  m_monoFiles = runFileNames;
}
/// note if the user has changed the white beam vanadium file away from its default, this will stop the setting from being replaced by the default
void MWDiag::WBVUpd()
{// if the user had already altered the contents of the box it has been noted that the save name is under user control so do nothing
  if (m_WBVChanged) return;
  m_WBVChanged = m_designWidg.leWBV1->text() != m_WBVAutoVal;
}
/// note if the user has changed either of the time of flight values from their defaults, this will stop the setting from being replaced by the default
void MWDiag::TOFUpd()
{// if the user had already altered the contents of the box it has been noted that the save name is under user control so do nothing
  if (m_TOFChanged) return;
  m_TOFChanged = (m_designWidg.leStartTime->text().toDouble() != m_sTOFAutoVal)
    || (m_designWidg.leEndTime->text().toDouble() != m_eTOFAutoVal);
}