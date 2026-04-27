#include <iostream>
#include <cstring>
using namespace std;
void swap(const char* &p,const char* &pp) //char* &p = main函数中的p
{
    const char* tmp = p; //p--- char*
    p = pp; //p 指向了wrold
    pp = tmp; //pp 指向了hello
}

void swap1(  char* const & p, char*const &pp)
{
    char* const tmp = p; //p--- char*
    //error 是因为p被const修饰，p指向的内存地址是不可以改变
  // p = pp; //p 指向了wrold
  // pp = tmp; //pp 指向了hello
}
void test( const int& i) //可以接受变量或者常量进行传参
{
   //i++; error const它限定了不要去修改i的值
}
int main()
{
    //[1] 练习
    //在C++，对于字符串操作，不建议使用char*
   char* p = "hello";
   char* pp = "world";

   cout << "p = " << p<<endl;
  // *(p + 1) = 'W'; //error 字符串常量不可以修改
   cout << "p = " << p<<endl;
   char a[] = "hello";
   cout << "a = " << a<<endl;
   *(a+1) = 'G' ; //ok 修改的字符是字符数组中副本的值，并不是真正字符串常量
   cout << "a = " << a<<endl;
   char b[] = "world";

   cout << p << endl;
   cout << pp << endl;
   swap(p,pp);


   cout << p << endl;
   cout << pp << endl;

   // swap("gz2027","gz2024");

   //[2] const引用  const type&

   int i = 1; //普通变量 类型 i
   int& i_r = i; //普通引用对应用于普通变量

   const int j = 0; //常量 类型为 const int

   const int & j_r = j; //严格匹配 用const int对象来给const 引用 ok

   const int& t_r = 1; //用常量来给const 引用 初始化 ok
   const int& t_i = i;//用int对象来给const 引用 初始化 ok


   test(10); //ok

    //"gz2027" ---  const char *
   swap1("gz2027","gz2024");
   return 0;
}
