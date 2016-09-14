#include <signal.h>
#include <iostream>
#include <ostream>

#include "config.h"
#include "GateController.hpp"
#include "command_line.h"

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
  std::cout << "Start SMS Gate" << std::endl;

  opt::variables_map vm;
  if (!parse_command_line (vm, argc, argv))
    return 1;

  signal (SIGINT, my_handler);

  controller.start ();

  // TODO - replace wait threads in the workers
  while (1);
  return 0;
}