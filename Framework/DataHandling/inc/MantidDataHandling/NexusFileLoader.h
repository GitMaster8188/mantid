// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2013 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include "MantidAPI/IFileLoader.h"
#include "MantidKernel/NexusDescriptor.h"
#include "MantidKernel/System.h"

namespace Mantid {
namespace API {

class DLLExport NexusFileLoader : public IFileLoader<NexusDescriptor> {
public:
  void exec() override;
  void createChildAlgorithm(const std::string &name,
                            const double startProgress = -1.,
                            const double endProgress = -1.,
                            const bool enableLogging = true,
                            const int &version = -1) override;
  setFileInfo() override;
};
} // namespace API
} // namespace Mantid
