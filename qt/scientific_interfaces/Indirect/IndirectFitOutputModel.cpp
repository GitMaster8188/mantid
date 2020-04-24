// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2020 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once
#include <memory>

#include "DllConfig.h"
#include "Indextypes.h"
#include "IndirectFitOutputModel.h"
#include "MantidAPI/IAlgorithm.h"
#include "MantidAPI/WorkspaceGroup.h"

namespace MantidQt {
namespace CustomInterfaces {
namespace IDA {

IndirectFitOutputModel::IndirectFitOutputModel(){};

bool IndirectFitOutputModel::isSpectrumFit(FitDomainIndex index) const {
  return true;
}

std::unordered_map<std::string, ParameterValue>
IndirectFitOutputModel::getParameters(FitDomainIndex index) const {
  return std::unordered_map<std::string, ParameterValue>();
}

boost::optional<ResultLocationNew>
IndirectFitOutputModel::getResultLocation(FitDomainIndex index) const {
  return boost::none;
}

std::vector<std::string>
IndirectFitOutputModel::getResultParameterNames() const {
  return std::vector<std::string>();
}
Mantid::API::WorkspaceGroup_sptr
IndirectFitOutputModel::getLastResultWorkspace() const {
  return std::make_shared<Mantid::API::WorkspaceGroup>();
}
Mantid::API::WorkspaceGroup_sptr
IndirectFitOutputModel::getLastResultGroup() const {
  return std::make_shared<Mantid::API::WorkspaceGroup>();
}

void IndirectFitOutputModel::clear() {}

void IndirectFitOutputModel::addOutput(
    const Mantid::API::WorkspaceGroup_sptr &resultGroup,
    Mantid::API::ITableWorkspace_sptr parameterTable,
    const Mantid::API::WorkspaceGroup_sptr &resultWorkspace) {}
} // namespace IDA
} // namespace CustomInterfaces
} // namespace MantidQt
