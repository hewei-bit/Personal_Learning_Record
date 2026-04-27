/**
 * @File Name: Singleton.h
 * @Brief : 单例模式
 * 保证一个类仅有一个实例，并提供一个该实例的全局访问点。 ——《设计模式》GoF
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-19
 * @finished Date : 2022-06-18
 * @Statement : finished
 *
 */

#ifndef __SINGLETON_HW_
#define __SINGLETON_HW_

#include <iostream>
#include <string.h>
#include <mutex>

#define Version_0_0 0
#define Version_0_1 0
#define Version_1 0
#define Version_2 0
#define Version_3 1
#define Version_4 1
#define Version_5 1
#define Version_6 1

using namespace std;

#if Version_0_0
// 懒汉模式
class Singleton_Lazy
{
public:
    static Singleton_Lazy *getInstance()
    {
        printf("This is Singleton Lazy mode...\n");
        if (instance == NULL)
        {
            m_mutex.lock();
            if (instance == NULL)
            {
                printf("创建新的实例\n");
                instance = new Singleton_Lazy();
            }
            m_mutex.unlock();
        }
        return instance;
    }

private:
    Singleton_Lazy() {}

    static Singleton_Lazy *instance;
    static std::mutex m_mutex;
};

Singleton_Lazy *Singleton_Lazy::instance = NULL;
std::mutex Singleton_Lazy::m_mutex;

#elif Version_0_1

// 饿汉模式
class Singleton_Hungry
{
public:
    static Singleton_Hungry *getInstance()
    {
        printf("This Singleton Hungry mode...\n");
        return instance;
    }

private:
    Singleton_Hungry() {}
    static Singleton_Hungry *instance;
};

Singleton_Hungry *Singleton_Hungry::instance = new Singleton_Hungry;

#elif Version_1

class Singleton
{
public:
    static Singleton *Getinstance()
    {
        if (_instance == nullptr)
            _instance == new Singleton();
        return _instance;
    }

private:
    // 需要将默认生成的函数保护起来
    Singleton() {}                             // 构造
    ~Singleton() {}                            // 析构函数
    Singleton(const Singleton &clone) {}       // 拷贝构造函数
    Singleton &operator=(const Singleton &) {} // 赋值
    static Singleton *_instance;               // static 实例
};
// 静态成员需要初始化
Singleton *Singleton::_instance = nullptr;

#elif Version_2
// 类对象之间 友元
class Singleton
{
public:
    static Singleton *Getinstance()
    {
        if (_instance == nullptr)
        {
            _instance == new Singleton();
            atexit(Destructor);
        }

        return _instance;
    }

private:
    // 需要将默认生成的函数保护起来
    static void Destructor()
    {
        if (nullptr != _instance)
        {
            delete _instance;
            _instance = nullptr;
        }
    }
    Singleton() {}                             // 构造
    ~Singleton() {}                            // 析构函数
    Singleton(const Singleton &clone) {}       // 拷贝构造函数
    Singleton &operator=(const Singleton &) {} // 赋值
    static Singleton *_instance;               // static 实例
};
// 静态成员需要初始化
// 还可以使?内部类，智能指针来解决； 此时还有线程安全问题
Singleton *Singleton::_instance = nullptr;

#elif Version_3
// 类对象之间 友元
class Singleton // 懒汉模式 lazy load
{
public:
    static Singleton *GetInstance()
    {
        // std::lock_guard<std::mutex> lock(_mutex); // 3.1 切换线程
        if (_instance == nullptr)
        {
            lock_guard<mutex> lock(_mutex); // 3.2
            if (_instance == nullptr)
            {
                _instance = new Singleton();
                // 1. 分配内存
                // 2. 调用构造函数
                // 3. 返回指针
                // 多线程环境下 cpu reorder操作
                atexit(Destructor);
            }
        }
        return _instance;
    }

private:
    static void Destructor()
    {
        if (nullptr != _instance)
        {
            delete _instance;
            _instance = nullptr;
        }
    }
    Singleton() {}                     //构造
    Singleton(const Singleton &cpy) {} //拷?构造
    Singleton &operator=(const Singleton &) {}
    static Singleton *_instance;
    static mutex _mutex;
};
Singleton *Singleton::_instance = nullptr; //静态成员需要初始化
mutex Singleton::_mutex;                   //互斥锁初始化

#elif Version_4

#elif Version_5

#elif Version_6

#endif

#endif