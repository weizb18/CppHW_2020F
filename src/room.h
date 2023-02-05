#ifndef ROOM_H
#define ROOM_H

#include <QString>

class Room
{
public:
    Room(){}
/*    Room(QString belong2Hotel, QString id, QString type, float price, QString description = NULL, float discount = 1.0)
        :belong2Hotel(belong2Hotel),id(id),type(type),price(price),description(description),discount(discount){}
        */
    ~Room(){}

    void SetBelong2Hotel(QString hotelname);
    void SetRoomId(QString roomid);
    void SetRoomType(QString roomtype);
    void SetRoomDescription(QString roomdescription);
    void SetRoomPrice(float roomprice);
    void SetRoomDiscount(float roomdiscount);

    QString GetBelong2Hotel();
    QString GetRoomId();
    QString GetRoomType();
    QString GetRoomDescription();
    float GetOriginalRoomPrice();
    float GetRoomDiscount();
    float GetPresentRoomPrice();
    bool  HasDiscount();

private:
    QString belong2Hotel;  // the room belongs to which hotel
    QString id;
    QString type;
    QString description;
    float price;  // original price
    float discount;
};

#endif // ROOM_H
