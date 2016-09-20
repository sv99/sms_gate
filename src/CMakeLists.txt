# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere.

set(sms_gate_SOURCE_FILES
        Message.cpp Message.hpp
        PhoneBook.cpp PhoneBook.hpp
        GateController.cpp GateController.hpp
        HttpServer.cpp HttpServer.hpp
        InputWorker.cpp InputWorker.hpp
        OutputWorker.cpp OutputWorker.hpp
        command_line.cpp command_line.h
        logger2.h
        ${EXT_DIR}/mongoose/mongoose.c)

add_library(sms_gate_lib ${sms_gate_SOURCE_FILES})

add_executable(sms_gate main.cpp)
#target_link_libraries(sms_gate sms_gate_lib Boost::program_options${Boost_LIBRARIES} fmt)
target_link_libraries(sms_gate sms_gate_lib Boost::program_options fmt spdlog::spdlog)