cmake_minimum_required(VERSION 3.27)
project(Structure)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/List
                    ${CMAKE_SOURCE_DIR}/Queue
                    ${CMAKE_SOURCE_DIR}/Stack
                    ${CMAKE_SOURCE_DIR}/Tree/Bst)

add_executable(Structure main.cpp
        Queue/queue_array.cpp
        Queue/queue_list.cpp
        List/list.cpp
        Stack/stack_array.cpp
        Stack/stack_list.cpp
        Stack/stack_test.cpp)
