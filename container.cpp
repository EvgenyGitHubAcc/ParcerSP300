#include "container.h"

QMap<QString, QList<Spectrum>> Container::specta;

QMap<QString, QList<Spectrum>> Container::getSpecta()
{
    return specta;
}

QString Container::createMottShottky(const QString & fileStr)
{
    QString lines = {};
    QList<Spectrum> specList = specta[fileStr];
    for(int i = 0; i < specList.count(); ++i)
    {
        lines += specList[i].getMottShottkyLine();
        specList[i].getPoints().pop_front();
    }
    return lines;
}

Container::Container()
{

}

void Container::fillList(const QStringList & list, const QString & srcFile)
{
    int specNum = 1;
    Spectrum spec = {};
    QList<Spectrum> localSpecList;
    foreach(const QString & str, list)
    {
        QStringList rawList(str.split('\t'));
        if(str == list.last())
        {
            spec << Point(std::move(rawList));
            localSpecList.append(std::move(spec));
            specta.insert(srcFile, std::move(localSpecList));
            return;
        }
        if(rawList[0].toDouble() == 0.0000000E+000 || rawList[1].toDouble() == 0.0000000E+000 || rawList[2].toDouble() == 0.0000000E+000)
        {
            continue;
        }
        else if((int)std::stod(rawList[12].toStdString()) == specNum)
        {
            spec << Point(std::move(rawList));
        }
        else
        {
            localSpecList.append(std::move(spec));
            spec.clear();
            spec << Point(std::move(rawList));
            ++specNum;
        }
    }
}
