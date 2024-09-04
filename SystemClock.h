//
// Created by alfoc on 27/08/24.
//

#ifndef TIMER_SYSTEMCLOCK_H
#define TIMER_SYSTEMCLOCK_H
#include <ctime>
#include <string>
const static int dimensionBuffer=80;
static char buffer[dimensionBuffer];
class SystemClock{
public:

    explicit SystemClock() : format(0) {}

    static std::tm * now(){
        std::time_t t = std::time(nullptr);
        return std::localtime(&t);
    }

    void updateTime(std::tm * customTime);

    int getFormat() const {
        return format;
    }

    const std::string &getDatetime() const {
        return datetime;
    }

    void setFormat(int form) {
        SystemClock::format = form;
    }

    virtual ~SystemClock();

private:
    int format;
    std::string datetime;
};

#endif //TIMER_SYSTEMCLOCK_H
