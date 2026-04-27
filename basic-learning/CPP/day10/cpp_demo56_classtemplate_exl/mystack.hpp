#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Stack
{
public:
    Stack(int size = 1024);
    bool isEmpty();
    bool isFull();

    void push(const T& ch); //将数据入栈
    T pop(); //将数据出栈

private:
    T* buffer; //泛型的指针
    int top; //指向栈顶的光标
    int bufferSize; //栈的容量
};

template <class T>
Stack<T>::Stack(int size)
{
    this->top = 0;
    this->buffer = new T[size];
    memset(this->buffer,0,sizeof (T));
    this->bufferSize = size;
}
template <class T>
bool Stack<T>::isEmpty()
{
    return  this->top == 0;
}

template <class T>
bool Stack<T>::isFull()
{
    return this->top == bufferSize;
}

template <class T>
void Stack<T>::push(const T& ch)
{

    buffer[top++] = ch;
}

template <class T>
T Stack<T>::pop()
{
    return buffer[--top];
}

