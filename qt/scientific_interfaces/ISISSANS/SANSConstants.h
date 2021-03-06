// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2018 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include <QString>

namespace MantidQt {
namespace CustomInterfaces {

class SANSConstants {
public:
  SANSConstants();
  ~SANSConstants();

  // Python related
  static QString getPythonSuccessKeyword();
  static QString getPythonEmptyKeyword();
  static QString getPythonTrueKeyword();
  static QString getPythonFalseKeyword();

  static QString getQResolutionH1ToolTipText();
  static QString getQResolutionH2ToolTipText();
  static QString getQResolutionA1ToolTipText();
  static QString getQResolutionA2ToolTipText();

  // Input related
  static double getMaxDoubleValue();
  static int getMaxIntValue();
  static int getDecimals();
};
} // namespace CustomInterfaces
} // namespace MantidQt
