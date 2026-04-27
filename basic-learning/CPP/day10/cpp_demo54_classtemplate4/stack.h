#ifndef STACK_H
#define STACK_H


template <class T>
class Stack
{
public:
    Stack()
    {

    }
    void pop()
    {
        if(this->empty())
        {
            cout <<"The stack is empty, can't do pop" <<endl;
            return;
        }
        elements.pop_back();
    }
    void push(T const &element)
    {
        elements.emplace_back(element);
    }
    bool empty() const
    {
        return elements.empty();
    }
    T top()const;

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


#endif // STACK_H
