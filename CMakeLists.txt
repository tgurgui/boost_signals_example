cmake_minimum_required(VERSION 3.20)
project(boost_signals_example)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(boost_signals_example main.cpp)
