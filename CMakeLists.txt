cmake_minimum_required(VERSION 3.6)
project(sms_gate)

# project version
set(VERSION_MAJOR 0)
set(VERSION_MINOR 2)
set(VERSION_PATCH 0)

# location of additional cmake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(BIN_DIR ${PROJECT_SOURCE_DIR}/build)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(EXT_DIR ${PROJECT_SOURCE_DIR}/external)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")

# set c++11 compiler flags
# add_definitions(-std=c++11) - for all files, error for mongoose.c -std=c++11 not allowed with C/ObjC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# get git hash
include(git_revision)

# configure header file
configure_file(
        ${PROJECT_SOURCE_DIR}/cmake/config.h.in
        ${SRC_DIR}/config.h
)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.60 REQUIRED COMPONENTS
        log program_options)

include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(${EXT_DIR}/fmt)
include_directories(${EXT_DIR}/fmt)

# header only
include_directories(${EXT_DIR}/spdlog/include)
include_directories(${EXT_DIR}/mongoose)

add_subdirectory(${SRC_DIR})
include_directories(${SRC_DIR})

add_subdirectory(${EXT_DIR}/googletest)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

# target to update git submodules
add_custom_target(
        update_submodules
        COMMAND git submodule init
        COMMAND git submodule update
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)