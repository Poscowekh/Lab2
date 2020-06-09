cmake_minimum_required(VERSION 3.5)

project(Lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LAB2.exe
    src/Main/Main.cpp
    #src/Interface/Interface.cpp
    #src/Interface/Manual.cpp
    #src/Examples/Example.cpp
    #src/Tests/Main/TestMain.cpp
)

include_directories(headers)
