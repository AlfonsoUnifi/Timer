//
// Created by alfoc on 25/08/24.
//

#include "gtest/gtest.h"
#include "../SystemClock.h"
SystemClock clock1;
// Test per verificare il formato iniziale
TEST(TimerTest, InitialFormat) {
    EXPECT_EQ(clock1.getFormat(), 0);
}

// Test per verificare l'aggiornamento del tempo
TEST(TimerTest, UpdateTime) {
    clock1.updateTime(SystemClock::now());
    std::string datetime1 = clock1.getDatetime();
    sleep(1);
    clock1.updateTime(SystemClock::now());
    std::string datetime2 = clock1.getDatetime();
    EXPECT_NE(datetime1, datetime2);
}