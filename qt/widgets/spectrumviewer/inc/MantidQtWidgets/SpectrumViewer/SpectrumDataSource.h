// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2012 ISIS Rutherford Appleton Laboratory UKRI,
//   NScD Oak Ridge National Laboratory, European Spallation Source,
//   Institut Laue - Langevin & CSNS, Institute of High Energy Physics, CAS
// SPDX - License - Identifier: GPL - 3.0 +
#pragma once

#include "MantidAPI/Workspace_fwd.h"
#include "MantidQtWidgets/SpectrumViewer/DataArray.h"
#include "MantidQtWidgets/SpectrumViewer/DllOptionSV.h"
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

/**
    @class SpectrumDataSource

    This class is an abstract base class for classes that can provide
    data to be displayed in an SpectrumView data viewer.

    @author Dennis Mikkelson
    @date   2012-04-03
 */

namespace MantidQt {
namespace SpectrumView {

class EXPORT_OPT_MANTIDQT_SPECTRUMVIEWER SpectrumDataSource {
public:
  /// Construct data source with specified total range and data size
  SpectrumDataSource(double totalXmin, double totalXmax, double totalYmin,
                     double totalYmax, size_t totalRows, size_t totalCols);

  virtual ~SpectrumDataSource();

  virtual bool hasData(const std::string &wsName,
                       const std::shared_ptr<Mantid::API::Workspace> &ws) = 0;

  /// Get the smallest 'x' value covered by the data
  virtual double getXMin();

  /// Get the largest 'x' value covered by the data
  virtual double getXMax();

  /// Get the smallest 'y' value covered by the data
  virtual double getYMin();

  /// Get the largest 'y' value covered by the data
  virtual double getYMax();

  /// Get the total number of rows of data
  virtual size_t getNRows();

  /// Get the total number of columns of data
  virtual size_t getNCols();

  /// Clamp x to the interval of x-values covered by this DataSource
  virtual void restrictX(double &x);

  /// Clamp y to the interval of y-values covered by this DataSource
  virtual void restrictY(double &y);

  /// Clamp row to a valid row number for this DataSource
  virtual void restrictRow(int &row);

  /// Clamp col to a valid column number for this dataSource
  virtual void restrictCol(int &col);

  /// Get a DataArray roughly spaning the specified rectangle.  NOTE: The
  /// actual size and number of steps returned in the DataArray will be
  /// adjusted to match the underlying data.
  virtual DataArray_const_sptr getDataArray(double xMin, double xMax,
                                            double yMin, double yMax,
                                            size_t nRows, size_t nCols,
                                            bool isLogX) = 0;

  /// Convenience method to get data covering the full range at max resolution
  virtual DataArray_const_sptr getDataArray(bool is_log_x);

  /// Get list of pairs of strings with info about the data at location x, y
  virtual std::vector<std::string> getInfoList(double x, double y) = 0;

protected:
  double m_totalXMin;
  double m_totalXMax;
  double m_totalYMin;
  double m_totalYMax;
  size_t m_totalRows;
  size_t m_totalCols;
};

using SpectrumDataSource_sptr = std::shared_ptr<SpectrumDataSource>;
using SpectrumDataSource_const_sptr = std::shared_ptr<const SpectrumDataSource>;

} // namespace SpectrumView
} // namespace MantidQt
