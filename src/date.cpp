#include "date.h"
using namespace std;
namespace{
    const int BEFMONTH[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
}
Date::Date()
{
}

Date::Date(int year, int month, int day):year(year),month(month),day(day){
    int befyear = year - 1;
    totaldays = befyear * 365 + befyear / 4 - befyear / 100 + befyear / 400 + BEFMONTH[month-1] + day;
    if(isLeapYear() && month > 2) totaldays++;
}

int Date::getYear() const{
    return year;
}

int Date::getMonth() const{
    return month;
}

int Date::getDay() const{
    return day;
}

int Date::getTotalDays() const{
    return this->totaldays;
}

int Date::getMaxDay() const{
    if(isLeapYear() && month == 2)
        return 29;
    else
        return BEFMONTH[month] - BEFMONTH[month-1];
}

bool Date::isLeapYear() const{
    return(year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::timeSpan(const Date &date) const{
    return this->totaldays - date.getTotalDays();
}

Date Date::AfterDate(int d){
    Date checkout(this->getYear(),this->getMonth(),this->getDay());
    checkout.day += d;
    if(checkout.isLeapYear() && checkout.month == 2){
        if(checkout.day > 29){
            checkout.day -= 29;
            checkout.month++;
        }
        return checkout;
    }
    if(checkout.day > BEFMONTH[checkout.month] - BEFMONTH[checkout.month-1]){
        checkout.day -= BEFMONTH[checkout.month] - BEFMONTH[checkout.month-1];
        checkout.month++;
        if(checkout.month > 12){
            checkout.month -= 12;
            checkout.year++;
        }
    }
    return checkout;
}

QString Date::showDate(){
    return QString::number(this->getYear()) + "-" + QString::number(this->getMonth()) + "-" + QString::number(this->getDay());
}

void Date::operator =(const Date &date){
    this->year = date.getYear();
    this->month = date.getMonth();
    this->day = date.getDay();
    this->totaldays = date.getTotalDays();
}
