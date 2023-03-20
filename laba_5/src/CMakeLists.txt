cmake_minimum_required(VERSION 3.21)
project(sum C)
set(CMAKE_C_STANDARD 17)

add_library(${PROJECT_NAME}
#        sum.h
#        sum.c
        common.h
        common.c
#        hlgenerator.c
        )