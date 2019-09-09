#include "container.h"

QList<Spectrum> Container::specta;

int Container::specInFile = 0;

QList<Spectrum> Container::getSpecta()
{
    return specta;
}

QString Container::createMottShottky()
{
    QString lines = {};
    for(int i = 0; i < specInFile; ++i)
    {
        lines += specta[i].getMottShottkyLine();
        specta[i].getPoints().pop_front();
    }
    return lines;
}

void Container::setSpecInFile(int value)
{
    specInFile = value;
}

Container::Container()
{

}

void Container::fillList(const QStringList & list)
{
    int specNum = 1;
    Spectrum spec = {};

    foreach(const QString & str, list)
    {
        QStringList rawList(str.split('\t'));
        if(str == list.last())
        {
            spec << Point(std::move(rawList));
            specta.append(std::move(spec));
            return;
        }
        if(rawList[0] == "0" || rawList[1] == "0" || rawList[2] == "0")
        {
            continue;
        }
        else if(rawList[12].toInt() == specNum)
        {
            spec << Point(std::move(rawList));
        }
        else
        {
            specta.append(std::move(spec));
            spec.clear();
            spec << Point(std::move(rawList));
            ++specNum;
        }
    }
}
