cmake_minimum_required(VERSION 3.14)
project(c_algorithms C)

set(CMAKE_C_STANDARD 11)

include_directories(src/data-structures/linked-list)

add_executable(LinkedList
    src/data-structures/linked-list/LinkedList.c
    src/data-structures/linked-list/LinkedList.h
    src/data-structures/linked-list/LinkedListTest.c)

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/bin)