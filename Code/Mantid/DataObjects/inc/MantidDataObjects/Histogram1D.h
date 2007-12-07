#ifndef MANTID_DATAOBJECTS_HISTOGRAM1D_H_
#define MANTID_DATAOBJECTS_HISTOGRAM1D_H_

#include <boost/shared_ptr.hpp>
#include <vector>
#include "MantidKernel/System.h"
#include "MantidKernel/RefControl.h"

namespace Mantid
{
namespace DataObjects
{
/*!
	1D histogram implementation.

    \class Histogram1D Histogram1D.h
    \author Laurent C Chapon, ISIS, RAL
    \date 26/09/2007  
    
  Copyright &copy; 2007 STFC Rutherford Appleton Laboratories

  This file is part of Mantid.
 	
  Mantid is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.
  
  Mantid is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  
  File change history is stored at: <https://svn.mantidproject.org/mantid/trunk/Code/Mantid>

*/

class DLLExport Histogram1D
{
public:

  /// Data Store: NOTE:: CHANGED TO BREAK THE WRONG USEAGE OF SHARED_PTR 

  typedef RefControl<std::vector<double> > RCtype;    
  
 private:

  RCtype refX;   ///< RefCounted X
  RCtype refY;   ///< RefCounted Y
  RCtype refE;   ///< RefCounted E

public:
  /// Data Store: NOTE:: CHANGED TO BREAK THE WRONG USEAGE OF SHARED_PTR 

  Histogram1D();
  Histogram1D(const Histogram1D&);
  Histogram1D& operator=(const Histogram1D&);
  virtual ~Histogram1D();

  /// Sets the x data.
  void setX(const std::vector<double>& X) {  refX.access()=X; }
  /// Sets the data.
  void setData(const std::vector<double>& Y) {  refY.access()=Y; };
    /// Sets the data and errors
  void setData(const std::vector<double>& Y,const std::vector<double> E) 
    {  refY.access()=Y; refE.access()=E; }

      /// Sets the x data.
  void setX(const RCtype& X) { refX=X; }
    /// Sets the data.
  void setData(const RCtype& Y) { refY=Y; }
    /// Sets the data.
  void setData(const RCtype& Y, const RCtype& E) { refY=Y; refE=E;}

  /// Sets the x data
  void setX(const RCtype::ptr_type& X) { refX=X; }
  /// Sets the data.
  void setData(const RCtype::ptr_type& Y) { refY=Y; }
  /// Sets the data and errors
  void setData(const RCtype::ptr_type& Y, const RCtype::ptr_type& E) { refY=Y; refE=E;}

  // Get the array data
  /// Returns the x data const
  virtual const std::vector<double>& dataX() const { return *refX; }  
  /// Returns the y data const
  virtual const std::vector<double>& dataY() const { return *refY; }
  /// Returns the error data const
  virtual const std::vector<double>& dataE() const { return *refE; }

  ///Returns the x data
  virtual std::vector<double>& dataX() { return refX.access(); }
  ///Returns the y data
  virtual std::vector<double>& dataY() { return refY.access(); }
  ///Returns the error data
  virtual std::vector<double>& dataE() { return refE.access(); }

  ///Clear the x data
  std::vector<double>& emptyX() { refX.access().clear(); return refX.access(); }
    ///Clear the y data
  std::vector<double>& emptyY() { refY.access().clear(); return refY.access(); }
    ///Clear the error data
  std::vector<double>& emptyE() { refE.access().clear(); return refE.access(); }

  int nxbin() const { return refX->size(); }         ///< Return the number of X bins
  int nybin() const { return refY->size(); }         ///< Return the number of data bin (Y or YE)
  virtual int size() const { return refY->size(); }          ///< get pseudo size

  /// Checks for errors
  bool isError() const { return refE->empty(); }
  /// Gets the memory size of the histogram
  long int getMemorySize() const { return (refX->size()+refY->size()+refE->size())*sizeof(double); }

};

} // namespace DataObjects

}  //Namespace Mantid
#endif /*MANTID_DATAOBJECTS_HISTOGRAM1D_H_*/
