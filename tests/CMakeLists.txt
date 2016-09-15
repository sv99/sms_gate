include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(sms_gate_TEST_FILES
        basic_check.cpp
        command_line_check.cpp
        version_check.cpp
        logger_check.cpp)

add_executable(sms_gate_tests ${sms_gate_TEST_FILES})

# link unit test executable against google test
target_link_libraries(sms_gate_tests gtest gtest_main)
target_link_libraries(sms_gate_tests ${Boost_LIBRARIES} sms_gate_lib fmt)

