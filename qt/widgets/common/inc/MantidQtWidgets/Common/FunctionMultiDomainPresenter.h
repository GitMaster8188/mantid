// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2018 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +
#ifndef MANTIDWIDGETS_FUNCTIONMULTIDOMAINPRESENTER_H_
#define MANTIDWIDGETS_FUNCTIONMULTIDOMAINPRESENTER_H__

#include "DllOption.h"

#include "MantidAPI/IFunction_fwd.h"
#include "MantidQtWidgets/Common/FunctionModel.h"

#include <memory>

namespace MantidQt {
namespace MantidWidgets {

class MultiDomainFunctionModel;
class IFunctionView;

using namespace Mantid::API;

class EXPORT_OPT_MANTIDQT_COMMON FunctionMultiDomainPresenter {
public:
  FunctionMultiDomainPresenter(IFunctionView *view);
  void clear();
  void setFunction(IFunction_sptr fun);
  void setFunctionString(const QString &funStr);
  QString getFunctionString();
  IFunction_sptr getFunction() const;
  IFunction_sptr getFitFunction() const;
  IFunction_sptr getFunctionByIndex(const QString &index);
  void setParameter(const QString &paramName, double value);
  void setParamError(const QString &paramName, double value);
  double getParameter(const QString &paramName);
  void updateParameters(const IFunction &fun);
private:
  IFunctionView *m_view;
  std::unique_ptr<MultiDomainFunctionModel> m_model;
public:
  IFunctionView *view() const {return m_view;}
};

} // namespace MantidWidgets
} // namespace MantidQt

#endif // MANTIDWIDGETS_FUNCTIONMULTIDOMAINPRESENTER_H_