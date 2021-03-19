#include "spectrum.h"

QList<Point> Spectrum::getPoints() const
{
    return points;
}

Spectrum::Spectrum()
{

}

Spectrum::Spectrum(const Spectrum & _spec)
{
    points = _spec.getPoints();
}

//Spectrum::Spectrum(Spectrum && _spec)
//{
//    points = _spec.getPoints();
//    _spec.getPoints().clear();
//}

void Spectrum::operator<<(const Point & _point)
{
    points.append(_point);
}

void Spectrum::clear()
{
    points.clear();
}

const QString & Spectrum::getPot()
{
    return points[0].Ewe;
}

QTextStream &operator<<(QTextStream & out, const Spectrum & spec)
{
    QList<Point> specLocal = spec.getPoints();
    out << spec.getPoints().size() << '\n';
    for(int i = 0; i < specLocal.size(); ++i)
    {
        out << specLocal[i].ReZ << '\t' << specLocal[i].ImZ << '\t' << specLocal[i].freq << '\n';
    }
    return out;
}
