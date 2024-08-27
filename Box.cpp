//
// Created by alfoc on 21/08/24.
//

#include <unistd.h>
#include "Box.h"

void Box::show() {
    WINDOW * win= newwin(height,width,start_y,start_x);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    keypad(win, TRUE);
    while (true) {
        timer->updateTime();
        werase(win);
        box(win, 0, 0);
        mvwprintw(win, 1, 1, "%s", timer->getDatetime().c_str());
        wrefresh(win);
        sleep(1);
        int tasto = getch();
        if (tasto == 27) {
            break;
        } else if (tasto == KEY_RIGHT || tasto == KEY_LEFT) {
            timer->changeFormat();
        }
    }
    delwin(win);
    endwin();
}