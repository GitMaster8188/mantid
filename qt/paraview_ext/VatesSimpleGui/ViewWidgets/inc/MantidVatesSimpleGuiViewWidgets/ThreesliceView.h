// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2011 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include "MantidVatesSimpleGuiViewWidgets/ViewBase.h"
#include "MantidVatesSimpleGuiViewWidgets/WidgetDllOption.h"
#include "ui_ThreesliceView.h"

#include <QPointer>
#include <QWidget>

class pqRenderView;

namespace Mantid {
namespace Vates {
namespace SimpleGui {

class RebinnedSourcesManager;
/**
 *
 This class creates four views of the given dataset. There are three 2D views
 for the three orthogonal Cartesian planes and one 3D view of the dataset
 showing the planes.

 @author Michael Reuter
 @date 24/05/2011
 */
class EXPORT_OPT_MANTIDVATES_SIMPLEGUI_VIEWWIDGETS ThreeSliceView
    : public ViewBase {
  Q_OBJECT

public:
  /**
   * Default constructor.
   * @param parent the parent widget for the threeslice view
   * @param rebinnedSourcesManager Pointer to a RebinnedSourcesManager
   * @param createRenderProxy :: Whether to create a render proxy for this view
   */
  ThreeSliceView(QWidget *parent = nullptr,
                 RebinnedSourcesManager *rebinnedSourcesManager = nullptr,
                 bool createRenderProxy = true);
  /// Default destructor.
  ~ThreeSliceView() override;
  /**
   * ViewBase::destroyView
   */
  void destroyView() override;
  /**
   * ViewBase::getView
   */
  pqRenderView *getView() override;
  /**
   * ViewBase::render
   */
  void render() override;
  /**
   * ViewBase::renderAll
   */
  void renderAll() override;
  /// ViewBase::resetCamera()
  void resetCamera() override;
  /**
   * ViewBase::resetDisplay()
   */
  void resetDisplay() override;

  /// @see ViewBase::setView
  void setView(pqRenderView *view) override;
  /// @see ViewBase::getViewType
  ModeControlWidget::Views getViewType() override;

private:
  Q_DISABLE_COPY(ThreeSliceView)

  /// Helper function that creates all three Cartesian orthogonal slices.
  void makeThreeSlice();

  QPointer<pqRenderView> m_mainView; ///< The 3D view

  Ui::ThreeSliceView m_ui; ///< The three slice view's UI form
};
} // namespace SimpleGui
} // namespace Vates
} // namespace Mantid
