set(SOURCE_FILES
        main.cpp
        Message.cpp Message.hpp
        PhoneBook.cpp PhoneBook.hpp
        GateController.cpp GateController.hpp
        HttpServer.cpp HttpServer.hpp
        InputWorker.cpp InputWorker.hpp
        OutputWorker.cpp OutputWorker.hpp)

add_executable(sms_gate ${SOURCE_FILES})
