//
// Created by svolkov on 06.10.15.
//

#include "gtest/gtest.h"
#include "logger2.h"

TEST(logger_check, test_filter) {
  //set_logger_filter (info);
  init_logger ("smsgate");
  testing::internal::CaptureStdout();
  auto l = spdlog::get("smsgate");
  l->info ("info message");
  l->warn ("warning message");
  l->debug ("warning message");
  l->flush ();

  // capture cout and count lines
  std::string output = testing::internal::GetCapturedStdout();
  int numLines = 0;
  std::stringstream strm(output);
  std::string unused;
  while ( std::getline(strm, unused) )
    ++numLines;

  EXPECT_EQ (numLines, 2);
}

