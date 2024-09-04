//
// Created by alfoc on 27/08/24.
//
#include "gtest/gtest.h"
#include "../SystemClock.h"

class ClockSuite : public ::testing::Test {
protected:
    SystemClock clock1;
};

TEST_F(ClockSuite, UpdateTime24hours) {
    std::tm fakeTime{};
    fakeTime.tm_year = 124;
    fakeTime.tm_mon = 7;
    fakeTime.tm_mday = 15;
    fakeTime.tm_hour = 14;
    fakeTime.tm_min = 30;
    fakeTime.tm_sec = 0;
    clock1.setFormat(0);
    clock1.updateTime(&fakeTime);
    EXPECT_EQ(clock1.getDatetime(), "15/08/2024 14:30:00");
}

TEST_F(ClockSuite, UpdateTime12hours) {
    std::tm fakeTime{};
    fakeTime.tm_year = 124;
    fakeTime.tm_mon = 7;
    fakeTime.tm_mday = 15;
    fakeTime.tm_hour = 14;
    fakeTime.tm_min = 30;
    fakeTime.tm_sec = 0;
    clock1.setFormat(1);
    clock1.updateTime(&fakeTime);
    EXPECT_EQ(clock1.getDatetime(), "08/15/2024 02:30:00 PM");
}

TEST_F(ClockSuite, UpdateUTCTime) {
    std::tm fakeTime{};
    fakeTime.tm_year = 124;
    fakeTime.tm_mon = 7;
    fakeTime.tm_mday = 15;
    fakeTime.tm_hour = 14;
    fakeTime.tm_min = 30;
    fakeTime.tm_sec = 0;
    clock1.setFormat(2);
    clock1.updateTime(&fakeTime);
    EXPECT_EQ(clock1.getDatetime(), "2024/08/15T14:30:00Z");
}
