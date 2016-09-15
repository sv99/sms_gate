//
// Created by svolkov on 06.10.15.
//

#include "gtest/gtest.h"
#include "config.h"

TEST(version_check, test_eq) {
  EXPECT_STREQ (get_version ().c_str (), "sms_gate version 0.1.0");
}
