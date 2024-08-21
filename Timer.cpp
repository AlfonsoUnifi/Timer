//
// Created by alfoc on 21/08/24.
//

#include "Timer.h"

void Timer::changeFormat() {
    std::string period = (now->tm_hour >= 12) ? "PM" : "AM";
    int american_hour = now->tm_hour % 12;
    if (american_hour == 0) american_hour = 12;
    std::tm* american_timer=std::localtime(&t);
    american_timer->tm_hour=american_hour;
    switch (format) {
        case 0:
            std::strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", now);
            datetime=buffer;
            break;
        case 1:
            std::strftime(buffer,sizeof(buffer),"%m/%d/%Y %I:%M:%S",american_timer);
            datetime=std::string(buffer)+" "+period;
            break;
    }
}