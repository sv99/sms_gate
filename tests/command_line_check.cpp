//
// Created by svolkov on 06.10.15.
//
#include "gtest/gtest.h"
#include "command_line.h"

opt::variables_map get_vars (int argc, const char *argv[])
{
  opt::variables_map vm;
  //const opt::options_description& desc = get_description();
  //opt::store (opt::parse_command_line (argc, argv, desc), vm);
  //opt::notify (vm);
  parse_command_line (vm, argc, argv);
  return vm;
}

TEST(command_line_check, test_help) {
  const char* n_argv[] = { __FILE__, "--help", NULL };
  auto vm = get_vars(2, n_argv);
  EXPECT_EQ(vm.count ("help"), 1);
}

TEST(command_line_check, test_h) {
  const char* n_argv[] = { __FILE__, "-h", NULL };
  auto vm = get_vars(2, n_argv);
  EXPECT_EQ(vm.count ("help"), 1);
}

TEST(command_line_check, test_duble_help) {
  const char* n_argv[] = { __FILE__, "--help", "-h", NULL };
  EXPECT_THROW (get_vars(3, n_argv), opt::multiple_occurrences);
}

TEST(command_line_check, test_version) {
  const char* n_argv[] = { __FILE__, "--version", NULL };
  auto vm = get_vars(2, n_argv);
  EXPECT_EQ(vm.count ("version"), 1);
}

TEST(command_line_check, test_verbose) {
  const char* n_argv[] = { __FILE__, "--verbose", NULL };
  auto vm = get_vars(2, n_argv);
  EXPECT_EQ(vm.count ("verbose"), 1);
}

TEST(command_line_check, test_v) {
  const char* n_argv[] = { __FILE__, "-v", NULL };
  auto vm = get_vars(2, n_argv);
  EXPECT_EQ(vm.count ("verbose"), 1);
}


