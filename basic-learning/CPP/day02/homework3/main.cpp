/*作业三：使用C++面向对象的思想，实现一个单链表*/

#include <iostream>

using namespace std;

class List
{
public:
    List(){createList();}
    ~List(){clear();}
    void createList();
    void insertTail(const int &d);//尾插
    void insertHead(const int &d);//头插
    void insertPos(const int & n,const int &d);//指定位置插入
    void deleteData(const int &d);//删除指定数据
    void deletePos(const int &n);//删除指定位置数据
    void updateData(const int &d,const int &d1);
    void updatePos(const int &n,const int &d);

    void print();//打印
    void clear();//清除链表

private:
    typedef struct Node
    {
        int data;
        Node *next;
    }*NODE;
    NODE head;//创建头结点
    //返回需要查找的指定节点的上一个节点，并返回
    NODE find(const int &d)
    {
        NODE p=head;
        for(;p;p=p->next)
        {
        if(p->next->data==d)
        break;
        }
        return p;
    }

};

int main()
{
    cout << "Hello World!" << endl;
    List list;
//    list.createList();

    list.insertHead(10);
    list.insertHead(22);
    list.insertTail(11);

    list.insertHead(88);
    list.insertHead(99);

    list.insertPos(1,33);
    list.insertHead(55);

    list.print();
    cout<<endl;

    list.deletePos(1);
    list.print();
    cout<<endl;

    list.deleteData(11);
    list.print();
    cout<<endl;

    list.updatePos(3,66);
    list.print();
    cout<<endl;

    list.updateData(33,44);
    list.print();
    cout<<endl;



//    list.clear();






    return 0;
}



void List::createList()
{
    head = new Node;
    head->next = NULL;
    head->data = 0;

}

void List::insertTail(const int &d)
{
    NODE p = head;
    NODE q = new Node;
    q->data = d;
    q->next = NULL;
    while(p->next)
    {
        p = p->next;
    }
    p->next = q;
}

void List::insertHead(const int &d)
{

    NODE q = new Node;
    q->data = d;
    q->next = head->next;
    head->next = q;
}

void List::insertPos(const int &n, const int &d)
{
    NODE p = head;
    NODE q = new Node;
    q->data = d;
    q->next = NULL;
    for(int i = 1;i<n ;i++)
    {
        p = p->next;
    }
    q->next= p->next;
    p->next =q;

}

void List::deleteData(const int &d)
{
    NODE p = head;
    for(;p;p=p->next)
    {
        if(p->next->data==d)
        break;
    }
    NODE q = p->next;
    p->next = q->next;
    delete q;
}

void List::deletePos(const int &n)
{
    NODE p = head;
    for(int i = 1;i < n;i++)
    {
        p= p->next;
    }
    NODE q = p->next;
    p->next = p->next->next;
    delete q;
}

void List::updateData(const int &d, const int &d1)
{
    NODE p = head;
    while (p)
    {
        p = p->next;
        if(p->data == d)
            break;
    }
    p->data = d1;
}

void List::updatePos(const int &n, const int &d)
{
    NODE p = head;
    for(int i = 1;i<n;i++)
    {
        p=p->next;
    }
    p->next->data = d;
}


void List::print()
{
    NODE p = head->next;
    while(p)
    {
        cout<< p->data<<" ";
        p = p->next;
    }
}

void List::clear()
{
    NODE p = head->next;
    while(p)
    {
        NODE q = p;
        p = p->next;
        delete q;

    }
    cout<<"over"<<endl;

}


