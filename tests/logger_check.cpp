//
// Created by svolkov on 06.10.15.
//

#include "gtest/gtest.h"
#include "logger.h"

TEST(logger_check, test_filter) {
  //set_logger_filter (info);
  testing::internal::CaptureStderr();
  INFO << "info log";
  DEBUG << "debug log";

  // capter cerr and count lines
  std::string output = testing::internal::GetCapturedStderr();
  int numLines = 0;
  std::stringstream strm(output);
  std::string unused;
  while ( std::getline(strm, unused) )
    ++numLines;

  EXPECT_EQ (numLines, 1);
}

