cmake_minimum_required(VERSION 3.5)

# Includi le directory di GoogleTest
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(GTest REQUIRED)

set(SOURCE_FILES runAllTests.cpp
        TimerTest.cpp
        TimerFixture.cpp
        MockClock.h
        ../Timer.h
        ../Timer.cpp
)
add_executable(runTimerTests ${SOURCE_FILES}
)

# Linka GoogleTest e la libreria core
# Linka GoogleTest e GoogleMock
target_link_libraries(runTimerTests
        gtest
        gtest_main
        gmock
        gmock_main
)
