//
// Created by alfoc on 21/08/24.
//

#include <unistd.h>
#include "Box.h"

const void Box::show() {
    start_color();
    mousemask(ALL_MOUSE_EVENTS, nullptr);
    int original_y_r = start_y - 2;
    int original_x_r = start_x + width - 7;
    int temp_y= start_y - 1;
    WINDOW * win= newwin(height,width,start_y,start_x);
    WINDOW * win2= newwin(height/2,width/4,original_y_r,start_x);
    WINDOW * win3= newwin(height/2,width/4,original_y_r,original_x_r);
    WINDOW * winTimer= newwin(height,width,start_y+10,start_x);
    WINDOW * playButton= newwin(height/2+1,width/4+2,start_y+15,start_x);
    WINDOW * pauseButton = newwin(height/2+1,width/4+2,start_y+15,original_x_r-2);
    WINDOW * setTimer = newwin(height/2+1,width/4+4,start_y+15,original_x_r-14);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    keypad(win, TRUE);
    while (true) {
        clock->updateTime(SystemClock::now());
        if(timer->isPlay()&&!timer->isPause())
            timer->updateTimer();
        drawBox(win);
        drawBox(win2);
        drawBox(win3);
        drawBox(winTimer);
        drawBox(playButton);
        drawBox(pauseButton);
        drawBox(setTimer);
        wattron(win, COLOR_PAIR(1));
        mvwprintw(setTimer,1,2,"%s","newTimer");
        mvwprintw(playButton,1,2,"%s","play");
        mvwprintw(pauseButton,1,2,"%s","pause");
        mvwprintw(win, 1, 1, "%s", clock->getDatetime().c_str());
        mvwprintw(winTimer,1,1,"%d:%d:%d",timer->getHours(),timer->getMinutes(),timer->getSeconds());
        wattroff(win, COLOR_PAIR(1));
        wrefresh(win);
        wrefresh(win2);
        wrefresh(win3);
        wrefresh(winTimer);
        wrefresh(playButton);
        wrefresh(pauseButton);
        wrefresh(setTimer);
        sleep(1);
        int tasto = getch();
        if (tasto == 27) {
            break;
        }
        if (tasto == KEY_RIGHT) {
            moveButton(temp_y, original_x_r, win3);
            if(clock->getFormat()<2)
                clock->setFormat(clock->getFormat()+1);
        } else if( tasto == KEY_LEFT){
            moveButton(temp_y,start_x,win2);
            if(clock->getFormat()>0)
                clock->setFormat(clock->getFormat()-1);
        }
        MEVENT eventPlay;
        if (tasto == KEY_MOUSE) {
            if (getmouse(&eventPlay) == OK) {
                if (eventPlay.x >= start_x && eventPlay.x < start_x + width/4+2 &&
                        eventPlay.y >= start_y+15 && eventPlay.y < start_y+15 + height/2+1) {
                    timer->setPlay(true);
                    timer->setPause(false);
                }
                if (eventPlay.x >= original_x_r && eventPlay.x < original_x_r + width/4+2 &&
                    eventPlay.y >= start_y+15 && eventPlay.y < start_y+15 + height/2+1) {
                    timer->setPlay(false);
                    timer->setPause(true);
                }
                if (eventPlay.x >= original_x_r-12 && eventPlay.x < original_x_r-12 + width/4+2 &&
                    eventPlay.y >= start_y+15 && eventPlay.y < start_y+15 + height/2+1) {
                    timer->setTimer();
                }
            }
        }
    }
    delwin(win);
    endwin();
}

void Box::drawBox(WINDOW *win) const {
    werase(win);
    box(win, 0, 0);
}

void Box::moveButton(int temp_y_r, int temp_x_r, WINDOW *win3) const {
    werase(win3);
    wrefresh(win3);
    WINDOW * win4= newwin(height / 2, width / 4, temp_y_r, temp_x_r);
    box(win4,0,0);
    wrefresh(win4);
    usleep(100000);
}
