#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QStringList>
#include <QDebug>
#include "customer.h"
#include "hotel.h"
#include "date.h"

class Order
{
public:
    Order();
    ~Order();

    int GetOrderId();
    QString GetHotelName();
    QString GetRoomId();
    QString GetRoomType();
    QString GetCustomerId();
    float GetTotalMoney();
    int GetTimeSpan();
    Date GetBeginDate();
    Date GetEndDate();

    void SetOrderId(int orderid);
    void SetHotelName(QString hname);
    void SetRoomId(QString rid);
    void SetRoomType(QString rtype);
    void SetCustomerId(QString cid);
    void SetTotalMoney(float tmoney);
    void SetTimeSpan(int tspan);
    void SetTimeSpan();
    void SetBeginDate(Date bdate);
    void SetEndDate(Date edate);

    bool GetExistence();
    bool GetNewOrder();
    bool GetCommented();
    bool GetRefund();

    void SetExistence(bool exist);
    void SetNewOrder(bool norder);
    void SetCommented(bool comment);
    void SetRefund(bool rfund);

    QStringList GetOrderInfo();
    static int idnum;

private:
    int id;  // order id
    QString hotelname;
    QString roomid;
    QString roomtype;
    QString customerid;  // the username of the customer
    float totalmoney;
    int timespan;
    Date beginDate;
    Date endDate;

    bool existence;    // show to hotel, set to "list of exist order"
    bool neworder;     // show to hotel, set to "list of new order"
    bool commented;    // show to customer, if customer has commented the hotel
    bool refund;       // show to customer, if customer get the refund after cancelling the future order
};

#endif // ORDER_H
