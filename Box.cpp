//
// Created by alfoc on 21/08/24.
//

#include "Box.h"

void Box::show() {
    initscr();
    noecho();
    WINDOW * win= newwin(height,width,start_y,start_x);
    refresh();
    box(win,103,103);
    int tasto;
    do{
        mvwprintw(win,1,1, "%s", timer->getDatetime().c_str());
        tasto=getch();
        if(tasto==KEY_RIGHT&&timer->getFormat()<=1){
            timer->setFormat(timer->getFormat()+1);
            timer->changeFormat();
        }else if(tasto==KEY_LEFT&&timer->getFormat()>=0){
            timer->setFormat(timer->getFormat()-1);
            timer->changeFormat();
        }
    }while (tasto!=KEY_END);
    endwin();
}
