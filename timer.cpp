#include "timer.h"

QTime Timer::timer;

Timer::Timer()
{

}

void Timer::startTimer()
{
    timer.start();
}

int Timer::writeTime()
{
    return timer.elapsed();
}

void Timer::restartTimer()
{
    timer.restart();
}
