//
// Created by alfoc on 21/08/24.
//

#ifndef TIMER_BOX_H
#define TIMER_BOX_H
#include "Timer.h"

class Box {
    Box(int wid,int heig,int x,int y,Timer * timer):width(wid),height(heig),start_x(x),start_y(y),timer(timer){}
private:
    int width;
    int height;
    int start_x;
    int start_y;
    Timer * timer;
};


#endif //TIMER_BOX_H
