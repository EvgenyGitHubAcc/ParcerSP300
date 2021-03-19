#ifndef SPECTRUM_H
#define SPECTRUM_H

#include "point.h"
#include <QTextStream>

class Spectrum
{
private:
    QList<Point> points;
    double getAverCur();
    double getAverC_2();
public:
    Spectrum();
    Spectrum(const Spectrum &);
//    Spectrum(Spectrum&&);
    void operator<<(const Point&);
    void clear();
    QList<Point> getPoints() const;
    const QString & getPot();
    const QString getMottShottkyLine();
};

QTextStream & operator<<(QTextStream &, const Spectrum &);

#endif // SPECTRUM_H
