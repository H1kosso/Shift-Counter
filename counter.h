#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QList>
#include <QQuickItem>
#include "Shifts.h"
#include <vector>
#include <fstream>
#include "Month.h"

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);
private:
    int doesExist(std::vector<std::string> vec, std::string key);
    void saveToFile(std::vector<Shifts> shifts, std::vector<std::string> keys);
public slots:
    void buttonClicked(int numberOfDays, QList<int> sundays, QList<int> saturdays, QList <QString> allMonth);
};

#endif
