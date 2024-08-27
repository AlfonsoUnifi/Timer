//
// Created by alfoc on 27/08/24.
//

#ifndef TIMER_SYSTEMCLOCK_H
#define TIMER_SYSTEMCLOCK_H

#include "Clock.h"

class SystemClock: public Clock{
public:
    std::tm * now() const override{
        std::time_t t = std::time(nullptr);
        return std::localtime(&t);
    }
};

#endif //TIMER_SYSTEMCLOCK_H
