//
// Created by alfoc on 27/08/24.
//

#ifndef TIMER_SYSTEMCLOCK_H
#define TIMER_SYSTEMCLOCK_H

#include "Clock.h"
#include <string>

class SystemClock: public Clock{
public:
    explicit SystemClock():format(0){}

    std::tm * now() const override{
        std::time_t t = std::time(nullptr);
        return std::localtime(&t);
    }

    void updateTime() override;

    int getFormat() const {
        return format;
    }

    const std::string &getDatetime() const {
        return datetime;
    }

    void setFormat(int format) {
        SystemClock::format = format;
    }

    virtual ~SystemClock();

private:
    int format;
    std::string datetime;
};

#endif //TIMER_SYSTEMCLOCK_H
