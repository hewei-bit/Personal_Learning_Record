#include <iostream>
#include "super_market.h"
using namespace std;




int main()
{
    cout << "Hello World!" << endl;

    apple aa(5,8,0.9);
    double sale = aa.sale(100);
    double profit = aa.profit(100);
    double profit_margin = aa.profit_margin(sale,profit);



    return 0;
}
