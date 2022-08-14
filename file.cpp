#include "file.h"
#include "timer.h"

File::File()
{
    QDir fileInputPath = QDir(QString("%1/%2").arg(QDir::currentPath()).arg("Initial Files"));
    QStringList nameFilter("*.mpt");
    srcFiles = fileInputPath.entryList(nameFilter);
}

void File::readAllFiles()
{
    if(!srcFiles.size())
    {
        std::cout << "There are no files to analyse" << std::endl;
        return;
    }
    for(QString & el : srcFiles)
    {
        QString srcFile = QString("%1/%2/%3").arg(QDir::currentPath()).arg("Initial files").arg(el);
        QFile file(srcFile);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }
        fileLines = QString(file.readAll()).split('\n');
        purifyFile();
        el.truncate(el.lastIndexOf('.'));
        Container::fillList(fileLines, el);
        fileLines.clear();
        std::cout << QString("File %1 is loaded. %2 msec").arg(el).arg(Timer::writeTime()).toStdString() << std::endl;
    }
}

void File::writeNyquistFiles()
{
    if(!srcFiles.size())
    {
        return;
    }
    foreach(QString el, srcFiles)
    {
        QString path = QString("%1/%2/%3").arg(QDir::currentPath()).arg("Final files").arg(el);
        QDir dir(path);

        if (!dir.exists())
        {
          dir.mkdir(path);
        }
        for(int j = 0; j < Container::getSpecta()[el].count(); ++j)                             //Specta count in the top of spectra file
        {
            QString name = Container::getSpecta()[el][j].getPot();
            QString finFile = QString(path + "/%1-%2[%3].txt").arg(j + 1).arg(el).arg(name.toDouble(), 0, 'f', 5);
            QFile file(finFile);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                return;
            }
            QTextStream out(&file);
            out << Container::getSpecta()[el][j];
            file.close();
        }
        std::cout << QString("Folder %1 is ready. %2 msec").arg(el).arg(Timer::writeTime()).toStdString() << std::endl;
    }
}

void File::writeCVFile()
{
    if(!srcFiles.size())
    {
        return;
    }
    for(int i = 0; i < srcFiles.count(); ++i)
    {
        QString path = QString("%1/%2/%3").arg(QDir::currentPath()).arg("Final files").arg(srcFiles[i]);
        QString finFile = QString(path + "/%1-CV.txt").arg(srcFiles[i]);
        QFile file(finFile);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }
        QTextStream out(&file);
        out << Container::createMottShottky(srcFiles[i]);
        file.close();
        std::cout << QString("File %1-CV is ready. %2 msec").arg(srcFiles[i]).arg(Timer::writeTime()).toStdString() << std::endl;
    }
}

void File::purifyFile()
{
    QRegExp expr("[0-9]+");
    expr.indexIn(fileLines[1]);
    int lineNumber = expr.cap().toInt();
    while(lineNumber)
    {
        fileLines.pop_front();
        --lineNumber;
    }
}
