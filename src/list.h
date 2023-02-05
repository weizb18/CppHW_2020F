#ifndef LIST_H
#define LIST_H

#include <QList>
#include <QString>
#include "customer.h"
#include "hotel.h"
#include "room.h"
#include "date.h"
#include "order.h"

bool ExistedCtmUsername(QString);  // judge whether the username has been registered(for customer)
bool ExistedHtlUsername(QString);  // judge whether the username has been registered(for hotel)

extern QList<Customer> customerList;
extern QList<Hotel> hotelList;
extern QList<Room> roomList;
extern QList<Order> orderList;
extern QList<Hotel> unpermittedhotelList;
extern int currentUserType;  //1:customer,2:hotel,3:platform
extern int currentUserRank;
extern Date today;

#endif // LIST_H
