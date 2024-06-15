#include "RecordManager.h"
#include <QFile>
#include <QTextStream>

int RecordManager::readRecord(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return 0;

    QTextStream in(&file);
    int record = 0;
    in >> record;
    file.close();
    return record;
}

void RecordManager::writeRecord(const QString& filePath, int score) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << score;
    file.close();
}
