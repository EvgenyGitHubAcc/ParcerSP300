#ifndef SPECTRUM_H
#define SPECTRUM_H

#include "point.h"
#include <QTextStream>

class Spectrum
{
private:
    QList<Point> points;
public:
    Spectrum();
    Spectrum(const Spectrum &);
//    Spectrum(Spectrum&&);
    void operator<<(const Point&);
    void clear();
    QList<Point> getPoints() const;
    const QString & getPot();
};

QTextStream & operator<<(QTextStream &, const Spectrum &);

#endif // SPECTRUM_H
