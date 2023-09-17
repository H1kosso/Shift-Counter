#ifndef MONTH_H
#define MONTH_H

#include <QList>
#include <QQuickItem>

class Month
{
public:
    void SetMonthData(int &numberOfDays, QList<int> &sundays, QList<int> &saturdays, QList <QString> allMonth);
    QList<int> m_sundays;
    QList<int> m_saturdays;
    int m_numberOfDays;
    QList <QString> m_allMonth;
};

#endif // MONTH_H
