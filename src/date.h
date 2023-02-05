#ifndef DATE_H
#define DATE_H

#include <cstdlib>
#include <QString>

class Date
{
public:
    Date();
    Date(int year, int month, int day);
    ~Date(){}
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getTotalDays() const;  // get totaldays from AD0000.01.01 till today
    int getMaxDay() const;  // get number of days in this month
    bool isLeapYear() const;
    int timeSpan(const Date &date) const;  // timespan between two dates
    Date AfterDate(int d);  // move a date to d days after
    QString showDate();  // eg. '2020-12-24'
    void operator = (const Date &date);

private:
    int year;
    int month;
    int day;
    int totaldays;
};

#endif // DATE_H
