cmake_minimum_required(VERSION 3.12)
project(cheaters)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cheaters
        main.cpp
        plagerismCatcher.h)
