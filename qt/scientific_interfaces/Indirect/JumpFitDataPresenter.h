// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2015 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +
#ifndef MANTIDQTCUSTOMINTERFACESIDA_JUMPFITDATAPRESENTER_H_
#define MANTIDQTCUSTOMINTERFACESIDA_JUMPFITDATAPRESENTER_H_

#include "IFQFitObserver.h"
#include "IndirectFitDataPresenter.h"
#include "IndirectFunctionBrowser/FQTemplateBrowser.h"
#include "JumpFitAddWorkspaceDialog.h"
#include "JumpFitModel.h"
#include "Notifier.h"

#include <QComboBox>
#include <QSpacerItem>

namespace MantidQt {
namespace CustomInterfaces {
namespace IDA {

class MANTIDQT_INDIRECT_DLL JumpFitDataPresenter
    : public IndirectFitDataPresenter {
  Q_OBJECT
public:
  JumpFitDataPresenter(JumpFitModel *model, IIndirectFitDataView *view,
                       QComboBox *cbParameterType, QComboBox *cbParameter,
                       QLabel *lbParameterType, QLabel *lbParameter,
                       IFQFitObserver *fQTemplateBrowser);

private slots:
  void hideParameterComboBoxes();
  void showParameterComboBoxes();
  void updateAvailableParameters();
  void updateAvailableParameterTypes();
  void updateAvailableParameters(const QString &type);
  void updateParameterSelectionEnabled();
  void setParameterLabel(const QString &parameter);
  void dialogParameterTypeUpdated(JumpFitAddWorkspaceDialog *dialog,
                                  const std::string &type);
  void setDialogParameterNames(JumpFitAddWorkspaceDialog *dialog,
                               const std::string &workspace);
  void setActiveParameterType(const std::string &type);
  void updateActiveDataIndex();
  void setSingleModelSpectrum(int index);
  void handleParameterTypeChanged(const QString &parameter);
  void handleSpectrumSelectionChanged(int parameterIndex);
  void handleMultipleInputSelected();
  void handleSingleInputSelected();

signals:
  void spectrumChanged(WorkspaceIndex);

protected slots:
  void handleSampleLoaded(const QString &) override;

private:
  void setAvailableParameters(const std::vector<std::string> &parameters);
  void addDataToModel(IAddWorkspaceDialog const *dialog) override;
  void closeDialog() override;
  std::unique_ptr<IAddWorkspaceDialog>
  getAddWorkspaceDialog(QWidget *parent) const override;
  void updateParameterOptions(JumpFitAddWorkspaceDialog *dialog);
  void updateParameterTypes(JumpFitAddWorkspaceDialog *dialog);
  std::vector<std::string> getParameterTypes(TableDatasetIndex dataIndex) const;
  void addWorkspace(IndirectFittingModel *model, const std::string &name);
  void setModelSpectrum(int index);

  void setMultiInputResolutionFBSuffixes(IAddWorkspaceDialog *dialog) override;
  void setMultiInputResolutionWSSuffixes(IAddWorkspaceDialog *dialog) override;

  std::string m_activeParameterType;
  TableDatasetIndex m_dataIndex;

  QComboBox *m_cbParameterType;
  QComboBox *m_cbParameter;
  QLabel *m_lbParameterType;
  QLabel *m_lbParameter;
  JumpFitModel *m_jumpModel;
  Notifier<IFQFitObserver> m_notifier;
};

} // namespace IDA
} // namespace CustomInterfaces
} // namespace MantidQt

#endif /* MANTIDQTCUSTOMINTERFACESIDA_JUMPFITDATAPRESENTER_H_ */
