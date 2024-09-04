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
    printw("Modifica ora...: %d",hours);
    while (change != 10) {
        change = getch();
        if (change == KEY_UP) {
            hours++;
            clear();
            refresh();
            printw("Modifica ora...: %d",hours);
        } else if (change == KEY_DOWN && hours > 0) {
            hours--;
            clear();
            refresh();
            printw("Modifica ora...: %d",hours);
        }
        if (change == KEY_ENTER)
            break;
    }
    clear();
    refresh();
    change = getch();
    printw("Modifica minuto...: %d",minutes);
    while (change != 10) {
        change = getch();
        if (change == KEY_UP && minutes < 60) {
            minutes++;
            clear();
            refresh();
            printw("Modifica minuto...: %d",minutes);
        } else if (change == KEY_DOWN && minutes > 0) {
            minutes--;
            clear();
            refresh();
            printw("Modifica minuto...: %d",minutes);
        }
        if (change == KEY_ENTER)
            break;
    }
    clear();
    refresh();
    change = getch();
    printw("Modifica secondo...: %d",seconds);
    while (change != 10) {
        change = getch();
        if (change == KEY_UP && seconds < 60) {
            seconds++;
            clear();
            refresh();
            printw("Modifica secondo...: %d",seconds);
        } else if (change == KEY_DOWN && seconds > 0) {
            seconds--;
            clear();
            refresh();
            printw("Modifica secondo...: %d",seconds);
        }
        if (change == KEY_ENTER)
            break;
    }
    clear();
    refresh();
}