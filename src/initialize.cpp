#include "initialize.h"

void initialWeizibu(){

    // initialize date
    Date initday(2020,12,21);
    today = initday;

    // initialize customer
    Customer cweizibu; cweizibu.SetUsername("cweizibu"); cweizibu.SetPassword("cweizibu"); cweizibu.SetBalance(1000.0); customerList.append(cweizibu);
    Customer cc;  cc.SetUsername("cc");  cc.SetPassword("cc");  cc.SetBalance(1000.0);  customerList.append(cc);

    // initialize hotel
    Hotel hweizibu;  hweizibu.SetUsername("tsinghua");  hweizibu.SetPassword("tsinghua");
    hweizibu.SetHotelName("tsinghua");  hweizibu.SetPlace("HaiDian");
    hweizibu.SetTel("62780000");  hweizibu.SetAddr("ShuangqingRoad");
    hweizibu.SetComment(5.0);  hweizibu.SetCommentNum(100);  hotelList.append(hweizibu);
    Hotel h1;  h1.SetUsername("zijing");  h1.SetPassword("zijing");
    h1.SetHotelName("zijing"); h1.SetPlace("HaiDian");
    h1.SetTel("62780001");  h1.SetAddr("XinminRoad");
    h1.SetComment(4.0);  h1.SetCommentNum(5);  hotelList.append(h1);
    Hotel h2;  h2.SetUsername("gugong");  h2.SetPassword("gugong");
    h2.SetHotelName("gugong"); h2.SetPlace("DongCheng");
    h2.SetTel("62780002");  h2.SetAddr("Chang'anSt.");
    h2.SetComment(5.0);  h2.SetCommentNum(10);  hotelList.append(h2);
    Hotel h3;  h3.SetUsername("qingfen");  h3.SetPassword("qingfen");
    h3.SetHotelName("qingfen"); h3.SetPlace("HaiDian");
    h3.SetTel("62780003");   h3.SetAddr("XuetangRoad");
    h3.SetComment(3.0);  h3.SetCommentNum(4);  hotelList.append(h3);

    // initialize room
    Room wroom[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            QString strRoomId = QString::number(i) + "0" + QString::number(j);
            wroom[i][j].SetBelong2Hotel("tsinghua");
            wroom[i][j].SetRoomId(strRoomId);
            wroom[i][j].SetRoomType("standard");
            wroom[i][j].SetRoomPrice(100.0);
            wroom[i][j].SetRoomDescription("wifi,breakfast");
            wroom[i][j].SetRoomDiscount(1.0);
            roomList.append(wroom[i][j]);
        }
    }
    Room h1room[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            QString strRoomId = QString::number(i) + "0" + QString::number(j);
            h1room[i][j].SetBelong2Hotel("zijing");
            h1room[i][j].SetRoomId(strRoomId);
            h1room[i][j].SetRoomType("single");
            h1room[i][j].SetRoomPrice(80.0);
            h1room[i][j].SetRoomDescription("wifi");
            h1room[i][j].SetRoomDiscount(0.9);
            roomList.append(h1room[i][j]);
        }
    }
    Room h2room[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            QString strRoomId = QString::number(i) + "0" + QString::number(j);
            h2room[i][j].SetBelong2Hotel("gugong");
            h2room[i][j].SetRoomId(strRoomId);
            h2room[i][j].SetRoomType("standard");
            h2room[i][j].SetRoomPrice(999.9);
            h2room[i][j].SetRoomDescription("breakfast");
            h2room[i][j].SetRoomDiscount(1.0);
            roomList.append(h2room[i][j]);
        }
    }
    Room h3room[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            QString strRoomId = QString::number(i) + "0" + QString::number(j);
            h3room[i][j].SetBelong2Hotel("qingfen");
            h3room[i][j].SetRoomId(strRoomId);
            h3room[i][j].SetRoomType("single");
            h3room[i][j].SetRoomPrice(120.0);
            h3room[i][j].SetRoomDescription("wifi");
            h3room[i][j].SetRoomDiscount(0.8);
            roomList.append(h3room[i][j]);
        }
    }

    // initialize order
    //    Date date10(2020,12,10),date11(2020,12,11),date12(2020,12,12),date13(2020,12,13),date14(2020,12,14);
    //    Date date15(2020,12,15),date16(2020,12,16),date17(2020,12,17),date18(2020,12,18),date19(2020,12,19);
    Date date20(2020,12,20),date21(2020,12,21),date22(2020,12,22),date23(2020,12,23),date24(2020,12,24);
    Date date25(2020,12,25),date26(2020,12,26),date27(2020,12,27),date28(2020,12,28),date29(2020,12,29);  // date30(2020,12,30);
    Order order1;
    order1.SetHotelName("tsinghua");  order1.SetCustomerId("cweizibu");
    order1.SetRoomId("000");  order1.SetRoomType("standard");
    order1.SetBeginDate(date20);  order1.SetEndDate(date21);
    order1.SetTotalMoney(500);    order1.SetCommented(false);
    order1.SetOrderId(0);  orderList.append(order1);
    Order order2;
    order2.SetHotelName("zijing");  order2.SetCustomerId("cweizibu");
    order2.SetRoomId("100");  order2.SetRoomType("single");
    order2.SetBeginDate(date25);  order2.SetEndDate(date26);
    order2.SetTotalMoney(360);    order2.SetCommented(false);
    order2.SetOrderId(1);  orderList.append(order2);
    Order order3;
    order3.SetHotelName("gugong");  order3.SetCustomerId("cweizibu");
    order3.SetRoomId("001");  order3.SetRoomType("standard");
    order3.SetBeginDate(date22);  order3.SetEndDate(date27);
    order3.SetTotalMoney(4999.5); order3.SetCommented(false);
    order3.SetOrderId(2);  orderList.append(order3);
    Order order4;
    order4.SetHotelName("qingfen");  order4.SetCustomerId("cweizibu");
    order4.SetRoomId("101");  order4.SetRoomType("single");
    order4.SetBeginDate(date23);  order4.SetEndDate(date28);
    order4.SetTotalMoney(480);    order4.SetCommented(false);
    order4.SetOrderId(3);  orderList.append(order4);
    Order order5;
    order5.SetHotelName("tsinghua");  order5.SetCustomerId("cweizibu");
    order5.SetRoomId("101");  order5.SetRoomType("standard");
    order5.SetBeginDate(date24);  order5.SetEndDate(date29);
    order5.SetTotalMoney(500);    order5.SetCommented(false);
    order5.SetOrderId(4);  orderList.append(order5);
}
