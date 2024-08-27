//
// Created by alfoc on 27/08/24.
//

#ifndef TIMER_MOCKCLOCK_H
#define TIMER_MOCKCLOCK_H
//
// Created by alfoc on 27/08/24.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Clock.h"
class MockClock: public Clock{
public:
    MOCK_METHOD(std::tm *,now,(),(const,override));
};
#endif //TIMER_MOCKCLOCK_H
