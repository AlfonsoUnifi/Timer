//
// Created by alfoc on 21/08/24.
//

#include <unistd.h>
#include "Box.h"

void Box::show() {
    start_color();
    int original_y_r = start_y - 2;
    int original_x_r = start_x + width - 7;
    int temp_y_r = start_y - 1;
    int temp_x_r = start_x + width - 7;
    int temp_y_l = start_y - 1;
    int temp_x_l = start_x;
    WINDOW * win= newwin(height,width,start_y,start_x);
    WINDOW * win2= newwin(height/2,width/4,start_y-2,start_x);
    WINDOW * win3= newwin(height/2,width/4,original_y_r,original_x_r);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    keypad(win, TRUE);
    while (true) {
        timer->updateTime();
        werase(win);
        werase(win2);
        werase(win3);
        box(win, 0, 0);
        box(win2, 0, 0);
        box(win3, 0, 0);
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win, 1, 1, "%s", timer->getDatetime().c_str());
        wattroff(win, COLOR_PAIR(1));
        wrefresh(win);
        wrefresh(win2);
        wrefresh(win3);
        sleep(1);
        int tasto = getch();
        if (tasto == 27) {
            break;
        } else if (tasto == KEY_RIGHT) {
            moveButton(temp_y_r, temp_x_r, win3);
            timer->changeFormat();
        } else if( tasto == KEY_LEFT){
            moveButton(temp_y_l,temp_x_l,win2);
            timer->changeFormat();
        }
    }
    delwin(win);
    endwin();
}

void Box::moveButton(int temp_y_r, int temp_x_r, WINDOW *win3) const {
    werase(win3);
    wrefresh(win3);
    WINDOW * win4= newwin(height / 2, width / 4, temp_y_r, temp_x_r);
    box(win4,0,0);
    wrefresh(win4);
    usleep(100000);
}
