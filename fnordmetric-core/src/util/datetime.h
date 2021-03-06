/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef _FNORDMETRIC_UTIL_DATETIME_H
#define _FNORDMETRIC_UTIL_DATETIME_H
#include <ctime>
#include <fnordmetric/util/datetime.h>
#include <inttypes.h>
#include <limits>
#include <string>

namespace fnord {
namespace util {

class DateTime {
public:

  /**
   * Create a new UTC DateTime instance
   *
   * @param timestamp the UTC microsecond timestamp
   */
  DateTime(uint64_t utc_time);

  /**
   * Return a representation of the date as a string (strftime)
   *
   * @param fmt the strftime format string (optional)
   */
  std::string toString(const char* fmt = "%Y-%m-%d %H:%M:%S") const;

  DateTime& operator=(const DateTime& other);

  bool operator==(const DateTime& other) const;
  bool operator<(const DateTime& other) const;
  bool operator>(const DateTime& other) const;
  bool operator<=(const DateTime& other) const;
  bool operator>=(const DateTime& other) const;

  /**
   * Cast the DateTime object to a UTC unix microsecond timestamp represented as
   * an uint64_t
   */
  explicit operator uint64_t() const;

  /**
   * Cast the DateTime object to a UTC unix microsecond timestamp represented as
   * a double
   */
  explicit operator double() const;

  /**
   * Return a new DateTime instance with time 00:00:00 UTC, 1 Jan. 1970
   */
  static DateTime epoch();

  /**
   * Return a new DateTime instance with time = now
   */
  static DateTime now();

protected:

  /**
   * The utc microsecond timestamp of the represented moment in time
   */
  uint64_t utc_time_;

  /**
   * The time zone offset to UTC in seconds
   */
  uint32_t tz_offset_;

};

}
}

namespace std {
template <> class numeric_limits<fnord::util::DateTime> {
public:
  static fnord::util::DateTime max();
  static fnord::util::DateTime min();
};
}

#endif
