/**
 * @File Name: Demo.h
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-03-25
 *
 */
#ifndef __DEMO_H_
#define __DEMO_H_

using namespace std;
#include <list>

// 抽象观察者 Observer
class Observer
{
public:
    virtual ~Observer() {}
    // 声明响应更新方法
    virtual void update() = 0;
};

// 具体观察者
class ConcreteObserver : public Observer
{
public:
    // 实现响应更新方法
    void update()
    {
        // 具体操作
    }
};

// 抽象目标
class Subject
{
public:
    virtual ~Subject() {}
    // 添加观察者
    void attach(Observer *obs)
    {
        oblist.push_back(obs);
    }

    // 移除观察者
    void detach(Observer *obs)
    {
        oblist.remove(obs);
    }
    // 声明通知方法
    virtual void notify() = 0;

protected:
    list<Observer *> oblist;
};

// 具体目标
class ConcreteSubject : public Subject
{
public:
    // 实现通知方法
    void notify()
    {
        // 具体操作
        // 遍历通知观察者对象
        for (auto ob : oblist)
        {
            ob->update();
        }
    }
};
#endif
