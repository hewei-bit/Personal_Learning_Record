#include <iostream>

using namespace std;
int global; //bss

//int global = 20; //data

struct stduent
{

    char name[20];
    int age;
};

void test()
{

}

int main()
{
    //cout相当于屏幕，将字符串"Hello====== World!"输出到屏幕上，endl 输出到屏幕上
    cout << "Hello====== World!"<< endl; //相当于一个换行符,用它来实现跨平台的换行符
    //test(1);

    stduent s1;
    const int i = 20;
    int* p = (int*)&i;
    *p = 30;
   // printf("i = %d\n",i);
    cout << i;
    const int temp = 30;

    int*p_t = (int*)&temp;
    *p_t = 50;

    int a[i]; //i是一个真正的常量，所以声明数组时，可以确定其大小
    return 0;
}
