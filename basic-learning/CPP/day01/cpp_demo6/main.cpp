#include <iostream>
#include "test.h"
using namespace std;

//面试题：如何在C++中,移植C语言中函数接口
/*
#ifdef __cplusplus
extern "C" {
#endif
//C语言的语法

#ifdef __cplusplus
}
#endif
*/
int main()
{
   func(10);//错误：func没有定义，但是，func函数在test.c源文件中已有定义
           // 报错的原因：编译C++项目在编译程序时，使用底层的倾辄技术，在C++ func --->func_i
           // 解决办法：在C++中，使用一个编译器定义好的宏来进行处理，告诉编译器，这个是C程序中
           // 要使用C编译来进行编译，不能C++编译器来进行编译C程序
    return 0;
}
