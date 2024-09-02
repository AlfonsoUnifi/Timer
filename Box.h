//
// Created by alfoc on 21/08/24.
//

#ifndef TIMER_BOX_H
#define TIMER_BOX_H
#include "Timer.h"
#include "SystemClock.h"
#include <ncurses.h>
#include <iostream>

class Box {
public:
    Box(int wid,int heig,int x,int y,SystemClock * clock1):width(wid),height(heig),start_x(x),start_y(y),clock(clock1){}

    void show();

private:
    int width;
    int height;
    int start_x;
    int start_y;
    SystemClock * clock;

    void moveButton(int temp_y_r, int temp_x_r, WINDOW *win3) const;
};


#endif //TIMER_BOX_H
