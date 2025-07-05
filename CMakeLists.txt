cmake_minimum_required(VERSION 3.14)
project(LibTrack VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBTRACK_HEADERS
        include/Item.h
        include/Room.h
        include/InventoryManager.h
        include/CSVHandler.h
)
set(LIBTRACK_SOURCES
        src/Item.cpp
        src/Room.cpp
        src/InventoryManager.cpp
        src/CSVHandler.cpp
)
set(MAIN_SRC src/main.cpp)

include_directories(include)

add_executable(LibTrack ${MAIN_SRC} ${LIBTRACK_HEADERS} ${LIBTRACK_SOURCES})

target_compile_options(LibTrack PRIVATE -Wall -Wextra -pedantic)

install(TARGETS LibTrack DESTINATION bin)
install(FILES ${LIBTRACK_HEADERS} DESTINATION include)
