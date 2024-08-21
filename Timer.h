//
// Created by alfoc on 21/08/24.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H
#include <ctime>
#include <string>
static const std::time_t t = std::time(nullptr);
static const std::tm* now = std::localtime(&t);

class Timer {
    Timer():year(now->tm_year),month(now->tm_mon),day(now->tm_mday),hour(now->tm_hour),minutes(now->tm_min),seconds(now->tm_sec)
    ,format(1){}
private:
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int seconds;
    int format;
};


#endif //TIMER_TIMER_H
