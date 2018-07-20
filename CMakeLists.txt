cmake_minimum_required(VERSION 3.9)
project(Abstract_VM)

set(CMAKE_CXX_STANDARD 14)

add_executable(Abstract_VM main.cpp Lexer.cpp Lexer.h)