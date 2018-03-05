#ifndef NEXUSGEOMETRY_INSTRUMENTBUILDER_H
#define NEXUSGEOMETRY_INSTRUMENTBUILDER_H

#include "MantidNexusGeometry/DllConfig.h"
#include "MantidGeometry/Objects/IObject.h"
#include "Eigen/Core"
#include <string>
#include <memory>

namespace Mantid {
namespace Geometry {
class Instrument;
class IComponent;
}
namespace NexusGeometry {

/** InstrumentBuilder : Builder for wrapping the creating of a Mantid
  Instrument. Provides some useful abstractions over the full-blown Instrument
  interface

  Copyright &copy; 2018 ISIS Rutherford Appleton Laboratory, NScD Oak Ridge
  National Laboratory & European Spallation Source

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

  File change history is stored at: <https://github.com/mantidproject/mantid>
  Code Documentation is available at: <http://doxygen.mantidproject.org>
*/
class MANTID_NEXUSGEOMETRY_DLL InstrumentBuilder {
public:
  /// Constructor creates the instrument
  InstrumentBuilder(const std::string &instrumentName);
  /// Adds component to instrument
  Geometry::IComponent *addComponent(const std::string &compName,
                                     const Eigen::Vector3d &position);
  /// Adds detector to instrument
  void addDetector(const std::string &detName, int detId,
                   const Eigen::Vector3d &position,
                   boost::shared_ptr<const Mantid::Geometry::IObject> &shape);
  /// Adds detector to instrument
  void addMonitor(const std::string &detName, int detId,
                  const Eigen::Vector3d &position,
                  boost::shared_ptr<const Mantid::Geometry::IObject> &shape);
  /// Add sample
  void addSample(const std::string &sampleName,
                 const Eigen::Vector3d &position);
  /// Add source
  void addSource(const std::string &sourceName,
                 const Eigen::Vector3d &position);
  /// Returns underlying instrument
  std::unique_ptr<const Geometry::Instrument> createInstrument() const;

private:
  /// Sorts detectors
  void sortDetectors() const;
  /// product
  mutable std::unique_ptr<Geometry::Instrument> m_instrument;
};
}
}
#endif // NEXUSGEOMETRY_INSTRUMENTBUILDER_H
