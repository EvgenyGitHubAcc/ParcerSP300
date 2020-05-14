#ifndef CONTAINER_H
#define CONTAINER_H

#include "point.h"
#include "spectrum.h"
#include <QList>


class Container
{
private:
    static QList<Spectrum> specta;
    static int specInFile;
    Container();
public:
    static void fillList(const QStringList &);
    static QList<Spectrum> getSpecta();
    static QString createMottShottky();
    static void setSpecInFile(int value);
};

#endif // CONTAINER_H
