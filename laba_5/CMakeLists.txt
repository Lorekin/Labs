cmake_minimum_required(VERSION 3.24)
project(hlgenerator)

include(CTest)
set(CMAKE_C_STANDARD 17)
enable_testing()
include_directories(src)

add_subdirectory(src)

add_executable(${PROJECT_NAME}
        hlgenerator.c)
add_executable(hldetector
        src/hldetector.c)
target_link_libraries(hldetector
        sum)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

