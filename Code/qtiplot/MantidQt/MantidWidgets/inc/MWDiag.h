#ifndef MANTIDQTCUSTOMINTERFACES_MWDIAG_H_
#define MANTIDQTCUSTOMINTERFACES_MWDIAG_H_

#include "MantidQtMantidWidgets/ui_MWDiag.h"
#include "MantidQtMantidWidgets/MWDiagCalcs.h"
#include "MantidQtMantidWidgets/DiagResults.h"
#include "MantidQtMantidWidgets/MWRunFiles.h"
#include "MantidQtMantidWidgets/MantidWidget.h"
#include "WidgetDllOption.h"
#include <QSettings>
#include <QStringList>
#include <QComboBox>
#include "boost/shared_ptr.hpp"

namespace MantidQt
{
  namespace MantidWidgets
  {
	class EXPORT_OPT_MANTIDQT_MANTIDWIDGETS MWDiag : public MantidWidget
    {
      Q_OBJECT

    public:
      /// there has to be a default constructor but you can call it with a pointer to the thing that will take ownership of it
      MWDiag(QWidget *parent = NULL, QString prevSettingsGr = "CustomWidgets/Diag", const QComboBox * const instru = NULL);
	  QString run(const QString &outWS = "", const bool saveSettings = true);
	  signals:
	    void runAsPythonScript(const QString&);
    private:
      /// The form generated by Qt Designer
      Ui::MWDiag m_designWidg;
	  /// check if ==NULL before use, set to point to the results dialog box is deleted when it's closed!
      DiagResults *m_dispDialog;
	  /// points to the control with the user selected instrument
	  const QComboBox * const m_instru;
	  /// points to the RunFile object used to specify the white beam vanadium file
	  MWRunFile *m_WBV2;
	  /// stores if the contents of the first white beam vanadium box have been filled in by the user or not, if not the contents are open to auto-fillin
	  bool m_WBVChanged;
	  /// true if either of the TOF windows have been changed by the user, otherwise false
	  bool m_TOFChanged;
	  /// name of the white beam vanadium file that was last passed through the updateWBV() signal or empty if no value was passed
	  QString m_WBVAutoVal;
	  /// time of flight value for the start of the background window that was set through the update??? or -1 if no value was sent through
	  double m_sTOFAutoVal;
	  /// time of flight value for the end of the background window that was set through the update??? or -1 if no value was sent through
	  double m_eTOFAutoVal;
      /// the name of the output workspace that contains many of the results from these tests
	  QString m_outputWS;
	  /// the run files that will be loaded to do the background test
	  std::vector<std::string> m_monoFiles;
      /// the values on the form the last time it was SUCCESSFULLY run accessed through this object
	  QSettings m_prevSets;

	  void raiseDialog();
      void notifyDialog(const DiagResults::TestSummary &display);
	  void closeDialog();

	  // move the following to the widget
	  QString openFileDialog(const bool save, const QStringList &exts);

	  void loadDefaults();
	  void insertFileWidgs();
	  void saveDefaults();
	  void setupToolTips();
      void connectSignals(const QWidget * const parentInterface);
	  void setUpValidators();
	  QString possibleSecondTest(boost::shared_ptr<whiteBeam2> &whiteBeamComp);
	  QString possibleThirdTest(boost::shared_ptr<backTest> &backCheck);
      DiagResults::TestSummary singleWhiteBeamTest(whiteBeam1 &python);
	  DiagResults::TestSummary whiteBeamCompTest(const DiagResults::TestSummary firstTest, boost::shared_ptr<whiteBeam2> &python);
	  DiagResults::TestSummary backGroundTest(const DiagResults::TestSummary &firstTest, const DiagResults::TestSummary &secondTest, boost::shared_ptr<backTest>& thisTest);
	private slots:
	  void browseClicked(const QString &buttonDis);
	  void updateWBV(const QString &WBVSuggestion);
	  void updateTOFs(const double &start, const double &end);
	  void specifyRuns(const std::vector<std::string> &);
	  void WBVUpd();
	  void TOFUpd();
	  void noDispDialog() {m_dispDialog = NULL;}
	};
  }
}

#endif //MANTIDQTCUSTOMINTERFACES_MWDIAG_H_
