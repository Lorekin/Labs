cmake_minimum_required(VERSION 3.21)
project(TestConcat)
set(CMAKE_C_STANDARD 17)

add_executable(${PROJECT_NAME}
        testMain.c
        )
target_link_libraries(${PROJECT_NAME}
            sum
        )
add_test(NAME ${PROJECT_NAME} COMMAND  ${PROJECT_NAME})
