//
// Created by Volkov on 14.09.16.
//

#ifndef SMS_GATE_COMMAND_LINE_H
#define SMS_GATE_COMMAND_LINE_H

#include <boost/program_options.hpp>

namespace opt = boost::program_options;

opt::options_description get_description();
void parse_command_line (opt::variables_map &vm, int argc, const char *argv[]);

#endif //SMS_GATE_COMMAND_LINE_H
