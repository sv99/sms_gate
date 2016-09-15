//
// Created by Volkov on 15.09.16.
//

#include "logger.h"

#include "boost/utility/empty_deleter.hpp"

namespace attrs = boost::log::attributes;
namespace expr = boost::log::expressions;
namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

//Defines a global logger initialization routine
BOOST_LOG_GLOBAL_LOGGER_INIT(my_logger, logger_t)
{
  logger_t lg;
  logging::add_common_attributes ();

  boost::shared_ptr<logging::core> log_core (logging::core::get ());

  boost::shared_ptr<sinks::text_ostream_backend> console_backend = boost::make_shared<sinks::text_ostream_backend> ();
  console_backend->auto_flush ();
  console_backend->add_stream (boost::shared_ptr<std::ostream> (&std::clog, boost::empty_deleter ()));

  typedef sinks::synchronous_sink <sinks::text_ostream_backend> text_sink_t;
  boost::shared_ptr<text_sink_t> console_sink = boost::make_shared<text_sink_t> (console_backend);
  console_sink->set_formatter (expr::stream
                                   << expr::format_date_time<boost::posix_time::ptime> ("TimeStamp", "%d.%m.%Y %H:%M:%S")
                                   << " [" << expr::attr<severity_level> ("Severity") << "]: "
                                   << expr::smessage);
  log_core->add_sink (console_sink);

// rotation file logging
  const std::string filename = "serverlist_%Y%m%d_%H%M%S.log";
  boost::shared_ptr<sinks::text_file_backend> file_backend = boost::make_shared<sinks::text_file_backend>
      (
          keywords::file_name = filename,
          keywords::rotation_size = 5 * 1024 * 1024,
          keywords::time_based_rotation = sinks::file::rotation_at_time_point (0, 0, 0),
          keywords::auto_flush = true
      );

  typedef sinks::synchronous_sink <sinks::text_file_backend> file_text_sink_t;
  boost::shared_ptr<file_text_sink_t> file_sink = boost::make_shared<file_text_sink_t> (file_backend);

  file_sink->set_formatter (expr::stream
                                << expr::format_date_time<boost::posix_time::ptime> ("TimeStamp", "%d.%m.%Y %H:%M:%S")
                                << " [" << expr::attr<severity_level> ("Severity") << "]: "
                                << expr::smessage);
  log_core->add_sink (file_sink);

  return lg;
}

//void set_logger_filter(severity_level level)
//{
//  logging::core::get ()->set_filter (expr::attr<severity_level> ("Severity") >= level);
//}