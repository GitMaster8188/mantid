// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2020 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +
#ifndef REFLMPLCPPTESTGLOBALINITIALIZATION_H
#define REFLMPLCPPTESTGLOBALINITIALIZATION_H

#include "MantidPythonInterface/core/Testing/PythonInterpreterGlobalFixture.h"

//------------------------------------------------------------------------------
// Static definitions
//
// We rely on cxxtest only including this file once so that the following
// statements do not cause multiple-definition errors.
//------------------------------------------------------------------------------
static PythonInterpreterGlobalFixture PYTHON_INTERPRETER;

#endif // REFLMPLCPPTESTGLOBALINITIALIZATION_H
