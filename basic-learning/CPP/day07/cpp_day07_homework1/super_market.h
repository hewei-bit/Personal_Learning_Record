#ifndef SUPER_MARKET_H
#define SUPER_MARKET_H

#include <iostream>
using namespace std;
//某商店销售苹果和洗发水，它们具备普通商品通用的一些属性和行为，
//如成本（cost）、售价（price）、可以被售出（sold）等；
//同时它们各自有个性化的东西，如苹果被售出时是要按斤称的，洗发水是按瓶卖的。
//销售人员在销售时可以灵活掌握商品折扣（discount），
//销售人员除了追求利润，还要追求利润率（利润率=总利润/总成本），

//比如某季度它们的业绩如下：
//销售员
//总销售额（totalAmount）利润（profit）利润率（count）备注
//Jack    117.5           ￥9.4        8.3%
//Rose    294.72          ￥35.37      12.0%
//Bill    2150            ￥107.5      5.0%    薄利多销

//请编写一个程序，可计算商店的总销售额、每个销售员的总利润，
//以及每个销售员的平均利润率等。

class goods
{
public:
    goods(int cost = 0,int price = 0,double discount = 0):cost(cost),price(price),discount(discount)
    {
        cout << "goods(int cost = 0,int price = 0,int discount = 0) " <<endl;
    }
    ~goods()
    {
        cout << "~goods()"<<endl;
    }
    int cost;
    int price;
    double discount;
private:

};

class apple:public goods
{
public:
    apple(int cost,int price,double discount):goods(cost,price,discount)
    {
        cout << "apple(int cost,int price,double discount) " <<endl;
    }
    ~apple()
    {
        cout << "~apple()"<<endl;
    }
    double sale(int jin)
    {
        double sale = jin*price*discount;
        cout << "sale : "<<sale<<endl;
        return sale;
    }
    double profit(int jin)
    {

        double profit = jin*(price*discount - cost);
        cout << "the profit : "<<profit<<endl;
        return profit;
    }
    double profit_margin(double sale,double profit)
    {
        double profit_margin = profit/sale;
        cout << "profit_margin : "<<profit_margin<<endl;
        return profit_margin;
    }
};

#endif // SUPER_MARKET_H
