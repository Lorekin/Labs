cmake_minimum_required(VERSION 3.24)
project(laba_7-8 C)

set(CMAKE_C_STANDARD 17)

include_directories(.)

add_executable(laba_7-8
        common.c
        common.h
        hlgenerator.c
        )