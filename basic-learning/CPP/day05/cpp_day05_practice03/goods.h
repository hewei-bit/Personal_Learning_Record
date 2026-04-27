#ifndef GOODS_H
#define GOODS_H
#include <iostream>

using namespace std;

typedef class Goods* GOODS;

class Goods
{
public:
    Goods();
    Goods(int weight);
    static int getTotalWeight();
    ~Goods();

    Goods *next;
private:
    int weight;
    static int total_weight;
};



void buy(Goods* &head,int w);

void sale(Goods* &head);

#endif // GOODS_H
