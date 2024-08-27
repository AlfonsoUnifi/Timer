cmake_minimum_required(VERSION 3.5)

# Includi le directory di GoogleTest
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES runAllTests.cpp
        TimerTest.cpp
)
add_executable(runTimerTests ${SOURCE_FILES}
        TimerTest.cpp
)

# Linka GoogleTest e la libreria core
target_link_libraries(runTimerTests gtest gtest_main core)