//
// Created by alfoc on 21/08/24.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H
#include <ctime>
#include <string>
#include "Clock.h"
const static int dimensionBuffer=80;
static char buffer[dimensionBuffer];
class Timer {
public:
    explicit Timer(const Clock & clock1):format(0),clock(clock1){}

    void changeFormat();

    int getFormat() const {
        return format;
    }

    const std::string &getDatetime() const {
        return datetime;
    }

    void updateTime();


private:
    int format;
    std::string datetime;
    const Clock &clock;
};


#endif //TIMER_TIMER_H
