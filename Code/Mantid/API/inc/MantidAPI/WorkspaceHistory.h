#ifndef MANTID_DATAOBJECTS_WORKSPACEHISTORY_H_
#define MANTID_DATAOBJECTS_WORKSPACEHISTORY_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "MantidAPI/AlgorithmHistory.h"
#include "MantidAPI/EnvironmentHistory.h"
#include <ctime>
#include <vector>

namespace Mantid
{
namespace API
{
/** @class WorkspaceHistory WorkspaceHistory.h API/MAntidAPI/WorkspaceHistory.h

    This class stores information about the Workspace History used by algorithms
    on a workspace and the environment history.

    @author Dickon Champion, ISIS, RAL
    @date 21/01/2008

    Copyright &copy; 2007-8 STFC Rutherford Appleton Laboratory

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

    File change history is stored at: <https://svn.mantidproject.org/mantid/trunk/Code/Mantid>.
    Code Documentation is available at: <http://doxygen.mantidproject.org>
 */
class DLLExport WorkspaceHistory
{
public:
  WorkspaceHistory();
  WorkspaceHistory(const EnvironmentHistory&, const std::vector<AlgorithmHistory>&);
  virtual ~WorkspaceHistory();
  WorkspaceHistory(const WorkspaceHistory&);
  WorkspaceHistory& operator=(const WorkspaceHistory& );

  const std::vector<AlgorithmHistory>& getAlgorithmHistories() const;
  void copyAlgorithmHistory(const WorkspaceHistory& otherHistory);
  void addAlgorithmHistory(const AlgorithmHistory& algHistory);

  void printSelf(std::ostream&, const int indent  = 0) const;

private:
  /// The environment of the workspace
  EnvironmentHistory m_environment;
  /// The algorithms which have been called on the workspace
  std::vector<AlgorithmHistory> m_algorithms;
};

DLLExport std::ostream& operator<<(std::ostream&, const WorkspaceHistory&);

} // namespace API
} // namespace Mantid

#endif /*MANTID_DATAOBJECTS_WORKSPACEHISTORY_H_*/
