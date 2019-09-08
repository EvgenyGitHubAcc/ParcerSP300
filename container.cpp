#include "container.h"

QList<Spectrum> Container::specta;

QList<Spectrum> Container::getSpecta()
{
    return specta;
}

Container::Container()
{

}

void Container::fillList(const QStringList & list)
{
    int specNum = 0;
    Spectrum spec = {};

    foreach(const QString & str, list)
    {
        QStringList rawList(str.split('\t'));
        if(rawList.size() != 20)
        {
            return;
        }
        if(rawList[12].toInt() == specNum)
        {
            spec << Point(rawList);
        }
        else
        {
            specta.append(spec);
            spec.clear();
            ++specNum;
        }
    }
}
