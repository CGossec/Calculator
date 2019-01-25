cmake_minimum_required(VERSION 3.0)

project(shunting LANGUAGES CXX)

add_executable(calculator src/main.cc src/lexer.cc
    src/calculator.cc)

#target_link_libraries()

set(CMAKE_BUILD_TYPE Debug)

include_directories(src)

add_definitions(-g -Wall -Werror -Wextra -pedantic -std=c++17)
