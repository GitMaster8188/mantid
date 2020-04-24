// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2020 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include "DllConfig.h"
#include "IIndirectFitOutput.h"
#include "Indextypes.h"
#include "MantidAPI/IAlgorithm.h"

namespace MantidQt {
namespace CustomInterfaces {
namespace IDA {
/*
    IIndirectFitData - Specifies an interface for updating, querying and
   accessing the raw data in IndirectFitAnalysisTabs
*/
class MANTIDQT_INDIRECT_DLL IndirectFitOutputModel : public IIndirectFitOutput {
public:
  IndirectFitOutputModel();
  bool isSpectrumFit(FitDomainIndex index) const override;

  std::unordered_map<std::string, ParameterValue>
  getParameters(FitDomainIndex index) const override;

  boost::optional<ResultLocationNew>
  getResultLocation(FitDomainIndex index) const override;
  std::vector<std::string> getResultParameterNames() const override;
  Mantid::API::WorkspaceGroup_sptr getLastResultWorkspace() const override;
  Mantid::API::WorkspaceGroup_sptr getLastResultGroup() const override;

  void clear() override;
  void
  addOutput(const Mantid::API::WorkspaceGroup_sptr &resultGroup,
            Mantid::API::ITableWorkspace_sptr parameterTable,
            const Mantid::API::WorkspaceGroup_sptr &resultWorkspace) override;

private:
  std::weak_ptr<Mantid::API::WorkspaceGroup> m_resultGroup;
  std::weak_ptr<Mantid::API::WorkspaceGroup> m_resultWorkspace;
  std::vector<std::unordered_map<std::string, ParameterValue>> m_parameters;
};

} // namespace IDA
} // namespace CustomInterfaces
} // namespace MantidQt