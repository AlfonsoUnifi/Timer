//
// Created by alfoc on 21/08/24.
//

#ifndef TIMER_BOX_H
#define TIMER_BOX_H
#include "Timer.h"
#include <ncurses.h>
#include <iostream>

class Box {
public:
    Box(int wid,int heig,int x,int y,Timer * timer):width(wid),height(heig),start_x(x),start_y(y),timer(timer){}

    int getWidth() const {
        return width;
    }

    void setWidth(int width) {
        Box::width = width;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        Box::height = height;
    }

    int getStartX() const {
        return start_x;
    }

    void setStartX(int startX) {
        start_x = startX;
    }

    int getStartY() const {
        return start_y;
    }

    void setStartY(int startY) {
        start_y = startY;
    }

    void show();

private:
    int width;
    int height;
    int start_x;
    int start_y;
    Timer * timer;
};


#endif //TIMER_BOX_H
