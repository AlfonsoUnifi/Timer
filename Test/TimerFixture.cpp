//
// Created by alfoc on 27/08/24.
//
#include "../Timer.h"
#include "gtest/gtest.h"
#include "MockClock.h"

class TimerSuite: public ::testing::Test{
protected:
    virtual void SetUp(){
       timer=new Timer(mockClock);
    }
    Timer * timer;
    MockClock mockClock;
};

TEST_F(TimerSuite,UpdateTime24hours){
    std::tm fakeTime{};
    fakeTime.tm_year=124;
    fakeTime.tm_mon=7;
    fakeTime.tm_mday=15;
    fakeTime.tm_hour=14;
    fakeTime.tm_min=30;
    fakeTime.tm_sec=0;

    EXPECT_CALL(mockClock,now()).WillOnce(::testing::Return(&fakeTime));
    timer->updateTime();
    EXPECT_EQ(timer->getDatetime(), "15/08/2024 14:30:00");
}

TEST_F(TimerSuite,UpdateTime12hours){
    std::tm fakeTime{};
    fakeTime.tm_year=124;
    fakeTime.tm_mon=7;
    fakeTime.tm_mday=15;
    fakeTime.tm_hour=14;
    fakeTime.tm_min=30;
    fakeTime.tm_sec=0;
    EXPECT_CALL(mockClock,now()).WillOnce(::testing::Return(&fakeTime));
    timer->changeFormat();
    timer->updateTime();
    EXPECT_EQ(timer->getDatetime(), "08/15/2024 02:30:00 PM");
}