#include <iostream>
#include <ncurses.h>
#include "Timer.h"
#include "Box.h"
#include "SystemClock.h"
int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    SystemClock clock1;
    Timer timer1(clock1);
    int height, width;
    getmaxyx(stdscr, height, width);
    int win_height = 5;
    int win_width = 30;
    int start_y = (height - win_height) / 2;
    int start_x = (width - win_width) / 2;
    Box box1(win_width,win_height,start_x,start_y,&timer1);
    box1.show();
    endwin();
    return 0;
}
