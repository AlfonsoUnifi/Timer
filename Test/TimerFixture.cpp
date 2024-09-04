//
// Created by alfoc on 04/09/24->
//
#include "gtest/gtest.h"
#include "../Timer.h"

class TimerSuite : public ::testing::Test {
protected:
    void SetUp(){
        timer1=new Timer(1,1,1);
    }
    void TearDown(){
        delete timer1;
    }
    Timer * timer1;
};

TEST_F(TimerSuite,UpdateTimer){
    timer1->updateTimer();
    EXPECT_EQ(0,timer1->getSeconds());
    timer1->updateTimer();
    EXPECT_EQ(59,timer1->getSeconds());
    EXPECT_EQ(0,timer1->getMinutes());
    timer1->setSeconds(0);
    timer1->updateTimer();
    EXPECT_EQ(0,timer1->getHours());
    EXPECT_EQ(59,timer1->getMinutes());
    EXPECT_EQ(59,timer1->getSeconds());
}

