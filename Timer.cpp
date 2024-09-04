//
// Created by alfoc on 21/08/24.
//

#include <ncurses.h>
#include "Timer.h"


void Timer::updateTimer() {
    if (hours != 0 || minutes != 0 || seconds != 0) {
        if(hours>0&&seconds==0&&minutes==0){
            hours--;
            minutes=59;
            seconds=59;
        }else if(seconds==0&&minutes>0){
            minutes--;
            seconds=59;
        }else if(seconds>0){
            seconds--;
        }
    }
}

void Timer::setTimer() {
    clear();
    refresh();
    hours = 0;
    minutes = 0;
    seconds = 0;
    pause = true;
    play = false;
    int change = getch();
    printw("Modifica ora...: ");
    hours=changeTime(change, hours);
    change = getch();
    printw("Modifica minuto...: ");
    minutes=changeTime(change, minutes);
    change = getch();
    printw("Modifica secondo...: ");
    seconds=changeTime(change, seconds);
}

int Timer::changeTime(int change, int part) {
    while (change != 10) {
        change = getch();
        if (change == KEY_UP) {
            part++;
            clear();
            refresh();
            printw("%d", part);
        } else if (change == KEY_DOWN && hours > 0) {
            part--;
            clear();
            refresh();
            printw("%d", part);
        }
        if (change == KEY_ENTER)
            break;
    }
    clear();
    refresh();
    return part;
}
