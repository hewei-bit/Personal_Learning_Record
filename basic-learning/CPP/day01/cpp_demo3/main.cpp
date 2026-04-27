#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


struct student
{
    int age;
};

//二级指针实现
void initStudnet_1( student**p)//*p相当于main函数中的指针变量s1
{
    student* tmp = NULL;
    //判断参数的合法性
    if(p == NULL)
    {
        return;
    }

    tmp = (student*)malloc(sizeof(student));

    if(tmp == NULL)
    {
        return;
    }
    tmp->age = 18;

    *p = tmp; //将申请的内存返回给外面指针变量
}

//使用指针引用
void initStudnet_2( student*&p) //p 相当于main函数中的指针变量s1
{
    p = (student*)malloc(sizeof(student));
    if(p == NULL)
    {
        return;
    }
    p->age = 20;
    //引用相当于是一个变量的别名，同变量有拥有同一个内存空间
}

int main()
{
    int a =10;
    int *p = &a;//给指针引用，还是用已有变量给它初始化（指针引用要用指针变量给它赋值）
                //p_r 它是p的一个别名，本质上也是一个指针变量，也可以通过它来访问内存
                //访问内存的访问跟指针一样

    int *&p_r = p;

    cout << "a = " << a << " *p = " << *p << " *p_r = " << *p_r << endl;

    //指针引用拓展
    student *s1;

   //封装两个函数：初始化函数和释放信息
   // initStudnet_1(&s1); //二级指针
   // cout << "age = " << s1->age<<endl;

    initStudnet_2(s1);
    cout << "age = " << s1->age<<endl;

    cout << "Hello World!" << endl;
    return 0;
}
