#include <iostream>
#include "tv_remote.h"



using namespace std;


//（友元、嵌套引用）
//编写一个程序包含两个类，
//一个为Remote类用来表示（万能）遥控器，
//一个为TV类用来表示电视机，要求遥控器能控制电视机，提供如下功能：
//电视机本身提供诸如setChannel()、setVolume() 等接口来修改频道和音量
//遥控器（万能）可控制电视机，但诸如开灯、降低空调温度等操作对电视机无效
//（类继承关系中构造函数、析构函数执行次序）

int main()
{
    cout << "Hello World!" << endl;

    Romote rr;
    rr.TVVolumeUP();
    rr.TVVolumeDOWN();
    rr.TVchannelUP();
    rr.TVchannelDOWN();
    rr.TVchannelset(22);
    rr.TVPower();
    rr.TVPower();
    rr.TVPower();




    return 0;
}
