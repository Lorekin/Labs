cmake_minimum_required(VERSION 3.21)
project(hw)

set(CMAKE_C_STANDARD 17)

add_executable(${PROJECT_NAME} 
	common.h
	common.c
	hlgenerator.c
)

#include(CTest)
#
#if(BUILD_TESTING)
#  add_subdirectory(test)
#endif()

