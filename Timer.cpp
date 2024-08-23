//
// Created by alfoc on 21/08/24.
//

#include "Timer.h"

void Timer::updateTime() {
    time_t t = std::time(nullptr);
    now = std::localtime(&t);
    switch (format) {
        case 0:
            std::strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", now);
            datetime = buffer;
            break;
        case 1:
            std::string period = (now->tm_hour >= 12) ? "PM" : "AM";
            std::strftime(buffer, sizeof(buffer), "%m/%d/%Y %I:%M:%S", now);
            datetime = std::string(buffer) + " " + period;
            break;
    }
}

void Timer::changeFormat() {
    format = (format + 1) % 2;
}
