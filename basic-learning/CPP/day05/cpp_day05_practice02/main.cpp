#include <iostream>

using namespace std;

//某商店销售苹果和洗发水，它们具备普通商品通用的一些属性和行为，
//如成本（cost）、售价（price）、可以被售出（sold）等；
//同时它们各自有个性化的东西，如苹果被售出时是要按斤称的，洗发水是按瓶卖的。
//销售人员在销售时可以灵活掌握商品折扣（discount），
//销售人员除了追求利润，还要追求利润率（利润率=总利润/总成本），
//比如某季度它们的业绩如下：

class Goods
{
public:
    Goods(string name,string unit,int cost,int price,bool sold,int discount):name(name),unit(unit)
    {
        this->cost = cost;
        this->price =price;
        this->sold = sold;
        this->discount = discount;
    }
private:
    const string name;
    const string unit;
    int cost;
    int price;
    bool sold;
    int discount;
};

class salesman
{
private:
    string name;
};




int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
