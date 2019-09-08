#ifndef CONTAINER_H
#define CONTAINER_H

#include "point.h"
#include "spectrum.h"
#include <QList>


class Container
{
private:
    static QList<Spectrum> specta;

    Container();
public:
    static void fillList(const QStringList &);
    static QList<Spectrum> getSpecta();

};

#endif // CONTAINER_H
