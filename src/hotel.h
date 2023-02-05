#ifndef HOTEL_H
#define HOTEL_H

#include <QString>
#include "user.h"

class Hotel : public User
{
public:
    Hotel();
    Hotel(QString hotelName, QString place, QString tel,
          bool isPermitted = false,
          float comment = 5, int commentNum = 0, QString addr = NULL):
      hotelName(hotelName), place(place), tel(tel), isPermitted(isPermitted),
      comment(comment), commentNum(commentNum), addr(addr){ }

    void SetHotelName(QString name);
    void SetPlace(QString place);
    void SetTel(QString tel);
    void SetisPermitted(bool ispermitted);
    void SetComment(float comment);
    void SetCommentNum(int commentnum);
    void SetAddr(QString addr);
    QString GetHotelName();
    QString GetPlace();
    QString GetTel();
    QString GetAddr();
    bool GetIsPermitted();
    float GetComment();
    int GetCommentNum();

private:
    QString hotelName;
    QString place;
    QString tel;
    bool isPermitted;
    float comment;
    int commentNum;
    QString addr;
};

#endif // HOTEL_H
