//
// Created by Volkov on 14.09.16.
//

#include "command_line.h"
#include <iostream>

// Declare the supported options.
opt::options_description get_description ()
{
  opt::options_description desc ("Allowed options");
  desc.add_options ()
      ("version", "print version string")
      ("help,h", "produce help message")
      ("verbose,v", "verbose output")
      ("compression", opt::value<int> (), "set compression level");
  return desc;
}

// may be throw exception:
void parse_command_line (opt::variables_map &vm, int argc, const char *argv[])
{
  opt::store (opt::parse_command_line (argc, argv, get_description ()), vm);
  opt::notify (vm);
}

