// MyClass.cpp
#include "counter.h"
#include <QQuickView>


Counter::Counter(QObject *parent) : QObject(parent)
{

}

void Counter::buttonClicked(int numberOfDays, QList<int> sundays, QList<int> saturdays, QList <QString> allMonth)
{
    Month month;
    month.SetMonthData(numberOfDays, sundays, saturdays, allMonth);

    std::vector<std::string> keys;
    std::vector<Shifts> shifts(40);

    int index;
    QVariant qString;
    std::string key;
    int width;
    int height;


    //Normal days
    for( int i = 0 ; i < numberOfDays  ; i++){
        if(!month.m_sundays.contains(i))
            for( int j = 0 ; j < 11 ; j++ ){
                key = allMonth[j * numberOfDays + i].toStdString();
                if (key == "" || key == "-") continue;
                index = doesExist(keys, key);
                if(index == -1){
                    keys.push_back(key);
                    index = keys.size() - 1;
                    shifts[index].m_normal++;
                } else {
                    shifts[index].m_normal++;
                }
            }
    }

   //Holidays
    for( int i = 0 ; i < numberOfDays  ; i++){
     if(month.m_sundays.contains(i))
            for( int j = 0 ; j < 11 ; j++ ){
                key = allMonth[j * numberOfDays + i].toStdString();
                if (key == "" || key == "-") continue;
                index = doesExist(keys, key);
                if(index == -1){
                    keys.push_back(key);
                    index = keys.size() - 1;
                    shifts[index].m_holiday++;
                } else {
                    shifts[index].m_holiday++;
                }
            }
    }


    //Normal nights
    for( int i = 0 ; i < numberOfDays  ; i++){
      if(!month.m_saturdays.contains(i) && !month.m_sundays.contains(i))
            for( int j = 12 ; j < 19 ; j++ ){
                key = allMonth[j * numberOfDays + i].toStdString();
                if (key == "" || key == "-") continue;
                index = doesExist(keys, key);
                if(index == -1){
                    keys.push_back(key);
                    index = keys.size() - 1;
                    shifts[index].m_nightNormal++;
                } else {
                    shifts[index].m_nightNormal++;
                }
            }
    }

//Saturday nights
    for( int i = 0 ; i < numberOfDays  ; i++){
            if(month.m_saturdays.contains(i))
            for( int j = 12 ; j < 19 ; j++ ){
                key = allMonth[j * numberOfDays + i].toStdString();
                if (key == "" || key == "-") continue;
                index = doesExist(keys, key);
                if(index == -1){
                    keys.push_back(key);
                    index = keys.size() - 1;
                    shifts[index].m_nightSaturday++;
                } else {
                    shifts[index].m_nightSaturday++;
                }
            }
    }


//Holiday nights
    for( int i = 0 ; i < numberOfDays  ; i++){
    if(month.m_sundays.contains(i))
            for( int j = 12 ; j < 19 ; j++ ){
                key = allMonth[j * numberOfDays + i].toStdString();
                if (key == "" || key == "-") continue;
                index = doesExist(keys, key);
                if(index == -1){
                    keys.push_back(key);
                    index = keys.size() - 1;
                    shifts[index].m_nightHoliday++;
                } else {
                    shifts[index].m_nightHoliday++;
                }
            }
    }

    saveToFile(shifts, keys);
}

void Counter::saveToFile(std::vector<Shifts> shifts, std::vector<std::string> keys){
    std::ofstream file("Shifts.csv");
    if (file.is_open()) {
        file << "Klucz,Dniowka,Swieta,Nocka,Nocka Sobota,Nocka Swieta\n";
        for ( int i = 0 ; i < keys.size() ; i++) {
            file << keys[i] << "," << shifts[i].m_normal << "," << shifts[i].m_holiday << "," << shifts[i].m_nightNormal << "," << shifts[i].m_nightSaturday << "," << shifts[i].m_nightHoliday << "\n";
            }
        file << "\n";
        }
        file.close();
    }



int Counter::doesExist(std::vector<std::string> vec, std::string key){
    for( int i = 0 ; i < vec.size() ; i++){
        if ( vec[i] == key && vec.size() != 0)
            return i;
    }
    return -1;
}

