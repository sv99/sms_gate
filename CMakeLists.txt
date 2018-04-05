cmake_minimum_required(VERSION 3.0)

include("cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.15.33.tar.gz"
        SHA1 "7849ccc2607964afd5fc8b48130473a133665670"
#        LOCAL # <----- Use local config.cmake
)

project(sms_gate)

# project version
set(VERSION_MAJOR 0)
set(VERSION_MINOR 2)
set(VERSION_PATCH 0)

set(BIN_DIR ${PROJECT_SOURCE_DIR}/build)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(EXT_DIR ${PROJECT_SOURCE_DIR}/external)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")

# set c++11 compiler flags
# add_definitions(-std=c++11) - for all files, error for mongoose.c -std=c++11 not allowed with C/ObjC
set (CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# location of additional cmake modules
#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# get git hash
include("cmake/git_revision.cmake")

# configure header file
configure_file(
        ${PROJECT_SOURCE_DIR}/cmake/config.h.in
        ${SRC_DIR}/config.h
)

hunter_add_package(Boost COMPONENTS program_options)
find_package(Boost 1.60 CONFIG REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIRS})

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

hunter_add_package(spdlog)
find_package(spdlog CONFIG REQUIRED)

# header only
include_directories(${EXT_DIR}/mongoose)

add_subdirectory(${SRC_DIR})
include_directories(${SRC_DIR})

add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

# target to update git submodules
add_custom_target(
        update_submodules
        COMMAND git submodule init
        COMMAND git submodule update
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)