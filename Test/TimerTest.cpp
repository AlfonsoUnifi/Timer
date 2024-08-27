//
// Created by alfoc on 25/08/24.
//

#include "gtest/gtest.h"
#include "../Timer.h"

// Test per verificare il formato iniziale
TEST(TimerTest, InitialFormat) {
    Timer timer;
    EXPECT_EQ(timer.getFormat(), 0);
}

// Test per verificare il cambio di formato
TEST(TimerTest, ChangeFormat) {
    Timer timer;
    timer.changeFormat();
    EXPECT_EQ(timer.getFormat(), 1);
    timer.changeFormat();
    EXPECT_EQ(timer.getFormat(), 0);
}

// Test per verificare l'aggiornamento del tempo
TEST(TimerTest, UpdateTime) {
    Timer timer;
    timer.updateTime();
    std::string datetime1 = timer.getDatetime();
    sleep(1);
    timer.updateTime();
    std::string datetime2 = timer.getDatetime();
    EXPECT_NE(datetime1, datetime2);
}