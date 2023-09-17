#include "Month.h"

void Month::SetMonthData(int &numberOfDays, QList<int> &sundays, QList<int> &saturdays, QList <QString> allMonth){
    m_numberOfDays = numberOfDays;
    m_sundays = sundays;
    m_saturdays = saturdays;
    m_allMonth = allMonth;
}
