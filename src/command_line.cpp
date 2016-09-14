//
// Created by Volkov on 14.09.16.
//

#include "command_line.h"
#include <iostream>

// Declare the supported options.
opt::options_description get_description()
{
  opt::options_description desc ("Allowed options");
  desc.add_options ()
      ("version", "print version string")
      ("help,h", "produce help message")
      ("verbose,v", "verbose output")
      ("compression", opt::value<int> (), "set compression level");
  return desc;
}

bool parse_command_line (opt::variables_map &vm, int argc, const char *argv[])
{
  const opt::options_description& desc = get_description();
  try
    {
      opt::store (opt::parse_command_line (argc, argv, desc), vm);
      opt::notify (vm);
    }
  catch(opt::unknown_option& e)
    {
      std::cerr << e.what() << std::endl;
      vm.insert(std::make_pair("help", opt::variable_value()));
    }

  if (vm.count ("help"))
    {
      std::cerr << desc << std::endl;
      return false;
    }

  return true;
}

