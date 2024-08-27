//
// Created by alfoc on 25/08/24.
//

#include "gtest/gtest.h"
#include "../Timer.h"
#include "../SystemClock.h"
SystemClock clock1;
Timer timer(clock1);
// Test per verificare il formato iniziale
TEST(TimerTest, InitialFormat) {
    EXPECT_EQ(timer.getFormat(), 0);
}

// Test per verificare il cambio di formato
TEST(TimerTest, ChangeFormat) {
    timer.changeFormat();
    EXPECT_EQ(timer.getFormat(), 1);
    timer.changeFormat();
    EXPECT_EQ(timer.getFormat(), 0);
}

// Test per verificare l'aggiornamento del tempo
TEST(TimerTest, UpdateTime) {
    timer.updateTime();
    std::string datetime1 = timer.getDatetime();
    sleep(1);
    timer.updateTime();
    std::string datetime2 = timer.getDatetime();
    EXPECT_NE(datetime1, datetime2);
}