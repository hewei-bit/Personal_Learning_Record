/**
 * @File Name: AllyCenter.h
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-03-25
 *
 */
#ifndef __ALLYCENTER_H__
#define __ALLYCENTER_H__

#include "common.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

// 前向声明
class Observer;
class Player;

// 抽象目标：联盟中心
class AllyCenter
{
public:
    AllyCenter();
    virtual ~AllyCenter() {}
    // 声明通知方法
    virtual void notify(INFO_TYPE infoType, std::string name) = 0;
    // 加入玩家
    void join(Observer *player);
    // 移除玩家
    void remove(Observer *player);

protected:
    // 玩家列表
    std::vector<Observer *> playerList;
};

// 具体目标
class AllyCenterController : public AllyCenter
{
public:
    AllyCenterController();
    // 实现通知方法
    void notify(INFO_TYPE infoType, std::string name);
};

#endif