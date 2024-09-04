//
// Created by alfoc on 21/08/24.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H
#include <ctime>
#include <string>
#include <ncurses.h>
class Timer {
public:
    Timer(int h,int m,int s): hours(h),minutes(m),seconds(s),pause(true),play(false){}

    int getHours() const {
        return hours;
    }

    int getMinutes() const {
        return minutes;
    }

    int getSeconds() const {
        return seconds;
    }

    bool isPlay() const {
        return play;
    }

    void setPlay(bool pl) {
        Timer::play = pl;
    }

    bool isPause() const {
        return pause;
    }

    void setPause(bool pa) {
        Timer::pause = pa;
    }

    void updateTimer();

    void setTimer();


private:
    int hours;
    int minutes;
    int seconds;
    bool play;
    bool pause;

    int changeTime(int change,int part);
};


#endif //TIMER_TIMER_H
