#include "base.h"
//#include "base.hpp"  //方法一C++方法 将类定义和成员函数实现都放在.hpp文件中，来实现

#include "base.cpp" //方法二 c语言方法，将源文件直接在使用的源文件手动引用进来
/*
  将类模板分成不同的文件中实现
  头文件 ---- > 类模板的定义和成员函数声明
  源文件 ---- > 类模板的成员函数的实现
*/
#include <vector>
int main()
{
    //在具体实例化时，Base<string,int>(string name,int age)
    Base<string,int> b("li4",20);
    b.printB();

    vector<int> first; //定义一个装整型数据的容器
    for (int i=0;i<5;i++) {
        first.push_back(i);
    }

    for (int i=0;i<first.size();i++) {
        cout << first.at(i) << endl;
        //cout << first[i] << endl;
    }
    return 0;
}
