cmake_minimum_required(VERSION 3.5)

project(Lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LAB2.exe
    src/Main.cpp
)

include_directories(headers)
