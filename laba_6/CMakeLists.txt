cmake_minimum_required(VERSION 3.24)
project(laba_6 C)

set(CMAKE_C_STANDARD 17)

include_directories(.)

add_executable(laba_6
        common.c
        common.h
        hldetector.c
#        hlgenerator.c
        )
