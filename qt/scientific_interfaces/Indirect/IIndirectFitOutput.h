// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2020 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include "DllConfig.h"
#include "Indextypes.h"
#include "IndirectFitOutput.h"

#include "MantidAPI/IAlgorithm.h"

namespace MantidQt {
namespace CustomInterfaces {
namespace IDA {
/*
    IIndirectFitData - Specifies an interface for updating, querying and
   accessing the raw data in IndirectFitAnalysisTabs
*/
class MANTIDQT_INDIRECT_DLL IIndirectFitOutput {
public:
  virtual bool isSpectrumFit(FitDomainIndex index) const = 0;

  virtual std::unordered_map<std::string, ParameterValue> virtual getParameters(
      FitDomainIndex index) const = 0;

  virtual boost::optional<ResultLocationNew>
  getResultLocation(FitDomainIndex index) const = 0;
  virtual std::vector<std::string> getResultParameterNames() const = 0;
  virtual Mantid::API::WorkspaceGroup_sptr getLastResultWorkspace() const = 0;
  virtual Mantid::API::WorkspaceGroup_sptr getLastResultGroup() const = 0;

  virtual void clear() = 0;

  virtual void
  addOutput(const Mantid::API::WorkspaceGroup_sptr &resultGroup,
            Mantid::API::ITableWorkspace_sptr parameterTable,
            const Mantid::API::WorkspaceGroup_sptr &resultWorkspace) = 0;
};

} // namespace IDA
} // namespace CustomInterfaces
} // namespace MantidQt