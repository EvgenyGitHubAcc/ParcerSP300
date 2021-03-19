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
        int a = (int)std::stod(rawList[12].toStdString());
        if(str == list.last())
        {
            spec << Point(std::move(rawList));
            specta.append(std::move(spec));
            return;
        }
//        if(rawList[0] == "0.0000000E+000" || rawList[1] == "0.0000000E+000" || rawList[2] == "0.0000000E+000")
        if((int)rawList[0].toDouble() == 0 || (int)rawList[1].toDouble() == 0 || (int)rawList[2].toDouble() == 0)
        {
            continue;
        }
        else if((int)std::stod(rawList[12].toStdString()) == specNum)
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
