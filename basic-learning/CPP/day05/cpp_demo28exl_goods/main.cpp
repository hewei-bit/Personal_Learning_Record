#include <iostream>

using namespace std;
class Goods
{
public:
    Goods()
    {
        this->weight = 0;
        this->next = nullptr;
    }
    Goods(int weight)
    {
        this->weight = weight;
        this->next = nullptr;
        //当进货时，总重量要增加
        total_weight += this->weight;

    }
    static int getTotalWeight()
    {
        return total_weight;
    }

    //当货物被销售出去，那么总的重要就要减少
    ~Goods()
    {
        total_weight -= weight; //weight 是指被销售出货特重量
    }
private:
    //货物本身的质量
    int weight;
    //仓库中货物总重量
    static int total_weight;

    //用来管理货物指针
    Goods* next;
};

int Goods::total_weight = 0;

 //货物本身是没有销售和进货功能，可以使用全局函数来测试，或者设计一个类
void buy(Goods* head,int w)
{
     //使用链表插入操作来完成
}

void sale(Goods* head)
{
    //相当于从链表中删除一个货物，删除操作
}
int main()
{
   //1 .代表进货 2.售出，可以重复操作
    return 0;
}
