#include <signal.h>
#include <iostream>
#include <sstream>

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

int main ()
{
  std::cout << "Start SMS Gate" << std::endl;

  signal (SIGINT, my_handler);

  controller.start ();

  // TODO - replace wait threads in the workers
  while (1);
  return 0;
}