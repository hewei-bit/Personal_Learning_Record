#ifndef __DEMO_H__
#define __DEMO_H__
/**
 * @File Name: Demo.h
 * @Brief : 模板方法demo，基类中定义定义算法框架，
 *          并声明所有方法，在子类实现的用虚函数，
 *          子类中只重写或覆盖基类中基本方法，没有其他操作
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2021-12-27
 *
 */

//抽象类（基类）
class AbstractClass
{
public:
    virtual ~AbstractClass() {}
    //基本方法1——公共方法
    void method1() {}
    //基本方法2——子类中实现
    virtual void method2() = 0;
    //基本方法3——默认实现
    void method3() {}
    //模板方法：定义一个算法的框架流程
    void templateMethod()
    {
        method1();
        method2();
        method3();
    }
};

//具体类（派生类）
class ConcreteClass : public AbstractClass
{
public:
    //实现基本方法2
    void method2()
    {
    }
    //重定义基本方法3，覆盖基类的方法3
    void method3()
    {
    }
};

#endif