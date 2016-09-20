//
// Created by Volkov on 15.09.16.
//

#ifndef SMS_GATE_LOGGER2_H
#define SMS_GATE_LOGGER2_H

#include <iostream>
#include "spdlog/spdlog.h"

#define SPDLOG_QSIZE 32

/*
 * from http://eao197.blogspot.ru/2016/05/progc11-spdlog.html
 */
struct custom_daily_file_name_calculator {
    static spdlog::filename_t calc_filename (const spdlog::filename_t &basename, const spdlog::filename_t &extension)
    {
      std::tm tm = spdlog::details::os::localtime ();
      fmt::MemoryWriter w;
      w.write ("{}_{:04d}{:02d}{:02d}.{}", basename, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, extension);
      return w.str ();
    }
};

inline void init_logger (std::string name, spdlog::level::level_enum level = spdlog::level::info)
{
  try
    {
      spdlog::set_async_mode (SPDLOG_QSIZE, spdlog::async_overflow_policy::block_retry,
                              nullptr,
                              std::chrono::seconds (2));
      std::vector<spdlog::sink_ptr> sinks;
      sinks.push_back (std::make_shared<spdlog::sinks::stdout_sink_st> ());
      // file sink with custom file name generator
      using my_file_sink = spdlog::sinks::daily_file_sink<std::mutex, custom_daily_file_name_calculator>;
      sinks.push_back (std::make_shared<my_file_sink>
                           ("logfile", "txt", 23, 59));
      auto combined_logger = std::make_shared<spdlog::logger> (name, std::begin (sinks), std::end (sinks));
      spdlog::register_logger (combined_logger);
      spdlog::set_level (level);
    }
  catch (const spdlog::spdlog_ex &ex)
    {
      std::cout << "Log initialization failed: " << ex.what () << std::endl;
    }
}

#endif //SMS_GATE_LOGGER2_H
