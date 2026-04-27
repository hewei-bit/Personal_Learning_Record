#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Stack
{
public:
    Stack()
    {

    }

    void pop();
    void push(T const &element);
    bool empty() const;
    T top()const;

    virtual ~Stack()
    {

    }
protected:
    vector <T> elements;
};

template<class T>
T Stack<T>::top() const
{
    if(this->empty())
    {
        cout <<"The stack is empty, can't do pop" <<endl;
        return T();
    }
    return elements.back();
}

template<class T>
void Stack<T>::pop()
{
    if(this->empty())
    {
        cout <<"The stack is empty, can't do pop" <<endl;
        return;
    }
    elements.pop_back();
}

template<class T>
void Stack<T>::push(const T &element)
{
    elements.emplace_back(element);
}

template<class T>
bool Stack<T>::empty() const
{
    return elements.empty();
}

#endif // STACK_H
