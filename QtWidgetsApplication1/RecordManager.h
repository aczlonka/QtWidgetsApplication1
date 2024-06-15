#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include <QString>

class RecordManager {
public:
    static int readRecord(const QString& filePath);
    static void writeRecord(const QString& filePath, int score);
};

#endif // RECORDMANAGER_H
