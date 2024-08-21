//
// Created by alfoc on 21/08/24.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H
#include <ctime>
#include <string>
static const std::time_t t = std::time(nullptr);
static const std::tm* now = std::localtime(&t);
static char buffer[80];
class Timer {
public:
    Timer():year(now->tm_year),month(now->tm_mon),day(now->tm_mday),hour(now->tm_hour),minutes(now->tm_min),seconds(now->tm_sec)
    ,format(0){
        std::strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", now);
        datetime=buffer;
    }

    void changeFormat();

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Timer::year = year;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int month) {
        Timer::month = month;
    }

    int getDay() const {
        return day;
    }

    void setDay(int day) {
        Timer::day = day;
    }

    int getHour() const {
        return hour;
    }

    void setHour(int hour) {
        Timer::hour = hour;
    }

    int getMinutes() const {
        return minutes;
    }

    void setMinutes(int minutes) {
        Timer::minutes = minutes;
    }

    int getSeconds() const {
        return seconds;
    }

    void setSeconds(int seconds) {
        Timer::seconds = seconds;
    }

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

private:
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int seconds;
    int format;
    std::string datetime;
};


#endif //TIMER_TIMER_H
