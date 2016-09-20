# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED) # GTest::main

set(sms_gate_TEST_FILES
        basic_check.cpp
        command_line_check.cpp
        version_check.cpp
        logger_check.cpp)

add_executable(sms_gate_tests ${sms_gate_TEST_FILES})

# link unit test executable against google test
target_link_libraries(sms_gate_tests GTest::main)
target_link_libraries(sms_gate_tests sms_gate_lib Boost::program_options fmt spdlog::spdlog)

### Testing ###
enable_testing()

add_test(NAME SmsGateTest COMMAND sms_gate_tests)
