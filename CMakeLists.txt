cmake_minimum_required(VERSION 3.31)
project(.)

set(CMAKE_CXX_STANDARD 20)

add_executable(InsaneTPomgWaw1 main.cpp
        src/Item.cpp
        src/Item.h
        src/Inventory.cpp
        src/Inventory.h)
