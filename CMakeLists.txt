cmake_minimum_required(VERSION 3.31)
project(LibTrack)

set(CMAKE_CXX_STANDARD 20)

add_executable(LibTrack src/main.cpp
        include/Item.h
        src/Item.cpp
        include/Room.h
        src/Room.cpp
        include/InventoryManager.h
        src/InventoryManager.cpp
        include/CSVHandler.h
        src/CSVHandler.cpp)
