cmake_minimum_required(VERSION 3.14)
project(c_algorithms C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wconversion")

include_directories(src/data-structures/linked-list)
include_directories(src/data-structures/doubly-linked-list)

add_executable(LinkedList
        src/data-structures/linked-list/LinkedList.c
    src/data-structures/linked-list/LinkedList.h
    src/data-structures/linked-list/LinkedListTest.c)


add_executable(DoublyLinkedList
        src/data-structures/doubly-linked-list/DoublyLinkedList.c
    src/data-structures/doubly-linked-list/DoublyLinkedList.h
    src/data-structures/doubly-linked-list/DoublyLinkedListTest.c)

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/bin)