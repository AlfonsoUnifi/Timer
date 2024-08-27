//
// Created by alfoc on 21/08/24.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H
#include <ctime>
#include <string>
const std::time_t t = std::time(nullptr);
const static std::tm* now = std::localtime(&t);
const static int dimensionBuffer=80;
static char buffer[dimensionBuffer];
class Timer {
public:
    Timer():format(0){}

    void changeFormat();

    int getFormat() const {
        return format;
    }

    void setFormat(int format) {
        Timer::format = format;
    }

    const std::string &getDatetime() const {
        return datetime;
    }

    void setDatetime(const std::string &datetime) {
        Timer::datetime = datetime;
    }

    void updateTime();


private:
    int format;
    std::string datetime;
};


#endif //TIMER_TIMER_H
