#include <signal.h>
#include <iostream>
#include <ostream>

#include "config.h"
#include "command_line.h"
#include "logger2.h"
#include "GateController.hpp"

GateController controller;

void my_handler (int s)
{
  std::cout << "Caught signal: " << s << std::endl;
  std::cout << "try stop" << std::endl;
  controller.stop ();
  std::cout << "stopped" << std::endl;
  exit (0);
}

int main (int argc, const char *argv[])
{
  // parse command line params
  opt::variables_map vm;
  try
    {
      parse_command_line (vm, argc, argv);
    }
  catch(opt::error_with_option_name& e)
    {
      std::cout << e.what() << std::endl;
      vm.insert(std::make_pair("help", opt::variable_value()));
    }

  if (vm.count ("help"))
    {
      std::cout << "Usage: sms_gate [options]" << std::endl;
      std::cout << get_description () << std::endl;
      return 1;
    }

  if (vm.count ("version"))
    {
      std::cout << get_version() << std::endl;
      return 1;
    }

  // init logging
  init_logger ("smsgate", spdlog::level::debug);

  auto l = spdlog::get("smsgate");
  l->info ("Start SMS Gate");
  l->flush ();

  signal (SIGINT, my_handler);

  controller.start ();

  // TODO - replace wait threads in the workers
  while (1);
  return 0;
}