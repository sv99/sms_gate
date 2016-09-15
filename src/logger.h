//
// Created by Volkov on 15.09.16.
//

#ifndef SMS_GATE_LOGGER_H
#define SMS_GATE_LOGGER_H

#include <ostream>

#include "boost/log/expressions.hpp"
#include "boost/log/sources/global_logger_storage.hpp"
#include "boost/log/support/date_time.hpp"
#include "boost/log/trivial.hpp"
#include "boost/log/utility/setup.hpp"

enum severity_level {
    debug,
    info,
    warning,
};

template<typename CharT, typename TraitsT>
inline std::basic_ostream<CharT, TraitsT> &operator<< (std::basic_ostream<CharT, TraitsT> &strm, severity_level lvl)
{
  static const char *const str[] =
      {
          "debug",
          "info",
          "warning",
      };

  if (static_cast<std::size_t>(lvl) < (sizeof (str) / sizeof (*str)))
    strm << str[lvl];
  else
    strm << static_cast<int>(lvl);
  return strm;
}

#define DEBUG    BOOST_LOG_SEV(my_logger::get(), debug)
#define INFO    BOOST_LOG_SEV(my_logger::get(), info)
#define WARN    BOOST_LOG_SEV(my_logger::get(), warning)

typedef boost::log::sources::severity_logger_mt<severity_level> logger_t;
BOOST_LOG_GLOBAL_LOGGER(my_logger, logger_t);
//void set_logger_filter(severity_level level);

#endif //SMS_GATE_LOGGER_H
