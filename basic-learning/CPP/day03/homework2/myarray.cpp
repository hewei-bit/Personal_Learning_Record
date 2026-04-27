#include "myarray.h"



MyArray::MyArray()//无参构造函数
{
    cout << "无参构造函数被调用"<<endl;
    this->capacity = 100;
    this->size = 0;
    this->array_Address = new int[capacity];
}

MyArray::MyArray(int cap)//有参构造函数
{
    cout << "有参构造函数被调用"<<endl;
    this->capacity = cap;
    this->size = 0;
    this->array_Address = new int[capacity];
}

MyArray::MyArray(const MyArray &array)//拷贝构造函数
{
    cout << "拷贝构造函数被调用"<<endl;
    this->capacity = array.capacity;
    this->size = array.size;
    this->array_Address = new int[capacity];

    *(this->array_Address) = *(array.array_Address);
    for(int i = 0;i < size;i++)
    {
        this->array_Address[i] = array.array_Address[i];
    }
}

MyArray::~MyArray()//析构函数
{
    cout << "析构函数被调用"<<endl;
    if(this->array_Address != nullptr)
    {
        delete[] this->array_Address;
    }
}

void MyArray::insert(int val)
{
    if(size >= capacity)
    {
        return ;
    }
    this->array_Address[size] = val;
    this->size++;
}

int MyArray::getSize()
{
    return this->size;
}

int MyArray::getCapacity()
{
    return this->capacity;
}

void MyArray::SetData(int pos, int val)
{
    if (pos < 0 || pos > this->capacity - 1)
    {
        return;
    }
    this->array_Address[pos] = val;
}

int MyArray::getData(int pos)
{
    return this->array_Address[pos];
}
