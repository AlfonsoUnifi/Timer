cmake_minimum_required(VERSION 3.5)
project(Timer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Aggiungi GoogleTest come sottodirectory
add_subdirectory(googletest)

# Aggiungi la directory dei test
add_subdirectory(Test)

set(SOURCE_FILES main.cpp Timer.cpp Timer.h Box.cpp Box.h
        SystemClock.h
        SystemClock.cpp)

add_executable(main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Timer core)

target_link_libraries(Timer ncurses)


