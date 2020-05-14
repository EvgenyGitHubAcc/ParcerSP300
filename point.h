#ifndef POINT_H
#define POINT_H

#include <QString>
#include <QStringList>

struct Point
{
    QString freq;
    QString ReZ;
    QString ImZ;
    QString Z;
    QString Phase;
    QString time;
    QString Ewe;
    QString I;
    QString Cs;
    QString Cs_2;
    QString Cp;
    QString Cp_2;
    QString cycleNumber;
    QString IRange;
    QString EweMod;
    QString IMod;
    QString ReY;
    QString ImY;
    QString Y;
    QString PhaseY;

    Point() = default;
    Point(const QStringList &);
//    Point(Point &&);

};

#endif // POINT_H
