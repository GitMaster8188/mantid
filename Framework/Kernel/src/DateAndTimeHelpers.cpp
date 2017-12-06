#include "MantidKernel/DateAndTimeHelpers.h"
#include "MantidKernel/Logger.h"
#include <Poco/DateTime.h>
#include <Poco/DateTimeFormat.h>
#include <Poco/DateTimeParser.h>

namespace {
std::tuple<bool, size_t, std::string> isARGUSDateTime(const std::string &date) {
  // Some ARGUS files have an invalid date with a space instead of zero.
  // To enable such files to be loaded we correct the date and issue a warning
  // Normal ISO8601 Date "2009-07-08T10:23:50"
  // Possible Argus Format "2009-07- 8T10:23:50"

  // (ticket #4017).
  // just take the date not the time or any date-time separator
  std::string strippedDate = date.substr(0, 10);
  const size_t nSpace = strippedDate.find(' ');
  return std::make_tuple(nSpace != std::string::npos, nSpace, strippedDate);
}
} // namespace

namespace Mantid {
namespace Kernel {
namespace DateAndTimeHelpers {
// Initialize the logger
Logger g_log("DateAndTime");

/** Creates a DateAndTime object from a date string even if the string does not
 *exactly conform to ISO8601 (ARGUS File)
 *@param date Date used to create DateAndTime object. May be sanitized first.
 *
 */
Types::Core::DateAndTime createFromSanitizedISO8601(const std::string &date) {
  return Types::Core::DateAndTime(verifyAndSanitizeISO8601(date));
}

/** Verifies whether or not a string conforms to ISO8601. Corrects the string
 *if it does not and is of the ARGUS file date/time format.
 *e.g 2009-07- 8T10:23:50 becomes 2009-07-08T10:23:50.
 *
 *@param date Date to be checked/corrected
 *@param displayWarnings display warning messages in the log if the date is non
 *conforming.
 */
std::string verifyAndSanitizeISO8601(const std::string &date,
                                     bool displayWarnings) {
  auto res = isARGUSDateTime(date);

  if (std::get<0>(res)) {
    auto time = date;
    if (displayWarnings) {
      g_log.warning() << "Invalid ISO8601 date " << date;
    }

    auto nSpace = std::get<1>(res);

    time[nSpace] = '0'; // replace space with 0

    // Do again in case of second space
    auto strippedDate = std::get<2>(res);
    strippedDate[nSpace] = '0';

    const size_t nSecondSpace = strippedDate.find(' ');
    if (nSecondSpace != std::string::npos)
      time[nSecondSpace] = '0';
    if (displayWarnings) {
      g_log.warning() << " corrected to " << time << '\n';
    }

    return time;
  }

  return date;
}

} // namespace DateAndTimeHelpers
} // namespace Kernel
} // namespace Mantid