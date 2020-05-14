#ifndef FILE_H
#define FILE_H

#include "spectrum.h"
#include "container.h"
#include <QStringList>
#include <QDir>
#include <QTextStream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

class File
{
private:
    QStringList srcFiles;
    QStringList fileLines;
    void purifyFile();
public:
    File();
    void readAllFiles();
    void writeNyquistFiles();
    void writeCVFile();
};

#endif // FILE_H
