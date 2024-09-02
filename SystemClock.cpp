//
// Created by alfoc on 02/09/24.
//
#include "SystemClock.h"
#include <string>

void SystemClock::updateTime() {
    const std::tm * now = SystemClock::now();
    std::string period;
    switch (format) {
        case 0:
            std::strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", now);
            datetime = buffer;
            break;
        case 1:
            period = (now->tm_hour >= 12) ? "PM" : "AM";
            std::strftime(buffer, sizeof(buffer), "%m/%d/%Y %I:%M:%S", now);
            datetime = std::string(buffer) + " " + period;
            break;
        case 2:
            std::strftime(buffer,sizeof(buffer),"%Y/%m/%d%H:%M:%S",now);
            datetime=buffer;
            datetime.insert(10,"T");
            datetime.insert(19,"Z");
            break;
    }
}

SystemClock::~SystemClock() {

}

