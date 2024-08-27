//
// Created by alfoc on 27/08/24.
//

#ifndef TIMER_CLOCK_H
#define TIMER_CLOCK_H

#include <ctime>

class Clock{
public:
    virtual ~Clock() = default;
    virtual std::tm * now() const = 0;
};

#endif //TIMER_CLOCK_H
