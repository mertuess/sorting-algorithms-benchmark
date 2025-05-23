cmake_minimum_required(VERSION 3.10)
project(sort)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB SRC_FILES "src/*.cpp")
list(APPEND SRC_FILES "main.cpp")

add_executable(sort ${SRC_FILES} ${RESOURCE_FILES})

