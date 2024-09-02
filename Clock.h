//
// Created by alfoc on 27/08/24.
//

#ifndef TIMER_CLOCK_H
#define TIMER_CLOCK_H

#include <ctime>
const static int dimensionBuffer=80;
static char buffer[dimensionBuffer];
class Clock{
public:
    ~Clock(){}
    virtual std::tm * now() const = 0;
    virtual void updateTime()=0;
};

#endif //TIMER_CLOCK_H
