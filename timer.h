#ifndef TIMER_H
#define TIMER_H

#include <QTime>
#include <iostream>

class Timer
{
    static QTime timer;
    Timer();
public:
    static void startTimer();
    static int writeTime();
    static void restartTimer();
};

#endif // TIMER_H
