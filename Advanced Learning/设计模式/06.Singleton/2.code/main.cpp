/**
 * @File Name: main.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-19
 *
 */

#include <iostream>
#include "Singleton.h"

#define SIMPLE 1

#if SIMPLE
int main()
{
    Singleton *s1 = Singleton::Getinstance();
    Singleton *s2 = Singleton::Getinstance();

    system("pause");
    return 0;
}

#else

#endif
