#include "file.h"
#include "timer.h"

File::File()
{
    QDir fileInputPath = QDir(QString("%1/%2").arg(QDir::currentPath()).arg("Src"));
    QStringList nameFilter("*.mpt");
    srcFiles = fileInputPath.entryList(nameFilter);
}

void File::readAllFiles()
{
    foreach(const QString el, srcFiles)
    {
        QString srcFile = QString("%1/%2/%3").arg(QDir::currentPath()).arg("Src").arg(el);
        QFile file(srcFile);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }

        fileLines = QString(file.readAll()).split('\n');
        purifyFile();
        Container::fillList(fileLines);
        fileLines.clear();
        std::cout << QString("File %1 is loaded. %2 msec").arg(el).arg(Timer::writeTime()).toStdString() << std::endl;
    }
}

void File::writeAllFiles()
{

    for(int i = 0; i < srcFiles.count(); ++i)
    {
        srcFiles[i].truncate(srcFiles[i].lastIndexOf('.'));
        QString path = QString("%1/%2/%3").arg(QDir::currentPath()).arg("Fin").arg(srcFiles[i]);
        QDir dir(path);

        if (!dir.exists())
        {
          dir.mkdir(path);
        }

        for(int j = 1; j < Container::getSpecta().size(); ++j)
        {
            QString name = Container::getSpecta()[j].getPot();
            name.remove(4, name.size() - 5);
            QString finFile = QString(path + "/%1-%2.txt").arg(srcFiles[i]).arg(name);
            QFile file(finFile);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                return;
            }
            QTextStream out(&file);
            int k = Container::getSpecta().size();
            out << Container::getSpecta()[j];
            file.close();
        }
        std::cout << QString("File %1 is ready. %2 msec").arg(srcFiles[i]).arg(Timer::writeTime()).toStdString() << std::endl;
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
