#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <string>

using namespace std;


template <class T>
class MyArray
{
    //重载 << 操作符

public:
    MyArray(){}
    explicit MyArray(int capacity)//防止隐式转换,构造函数
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->address = new T[this->m_Capacity];
    }
    //拷贝构造函数
    MyArray(const MyArray &arr)
    {
        this->m_Size = arr.m_Size;
        this->m_Capacity = arr.m_Capacity;
        this->address = new T[this->m_Capacity];
        for (int i = 0; i < arr.m_Size; ++i) {
            this->address[i] = arr.address[i];
        }
    }
    //析构函数
    ~MyArray()
    {
        if(this->address != NULL)
        {
            delete [] this->address;
            this->address = NULL;
        }

    }
    //重载 = 操作符
    MyArray &operator =(const MyArray &arr)
    {
        if(this->address != NULL)
        {
            delete [] this->address;
            this->address = NULL;
        }
        this->m_Size = arr.m_Size;
        this->m_Capacity = arr.m_Capacity;
        this->address = new T[this->m_Capacity];
        for (int i = 0; i < arr.m_Size; ++i) {
            this->address[i] = arr.address[i];
        }
    }
    //重载 [] 操作符
    T & operator[](int index)
    {
        return this->address[index];
    }




    //添加数据
    void add_num(T val)
    {
        this->address[this->m_Size] = val;
        this->m_Size++;
    }
    //获取大小
    int getSize()
    {
        return m_Size;
    }

    //获取容量
    int getCapacity()
    {
        return m_Capacity;
    }


private:
    T * address;
    int m_Capacity;
    int m_Size;
};

template <class T>
ostream & operator<<(ostream &os, MyArray<T> &arr)
{
    os<<"size : "<<arr.getSize() <<"capacity"<<arr.getSize() <<endl;
    return os;
}
#endif // MYARRAY_H
