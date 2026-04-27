#include <iostream>
#include "kitty.h"
using namespace std;

int main()
{
    //[1]创建类的对象
   kitty cat,cat1;
   //[2] 通过对象来访问类成员变量和函数
   cat.setSex('W');
   cat.setWeight(0.5);
   cat.setFurcolor(gold);
   cat.showInfo();
   cat1.showInfo();


   cat.eat();
   cat.eat();
   cat.eat();

   cat.showInfo();
    return 0;
}
