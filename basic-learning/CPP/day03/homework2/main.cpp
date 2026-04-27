#include <iostream>
#include "myarray.h"
using namespace std;

int main()
{
    int cap = 60;
    MyArray a(cap);
    int capa_a = a.getCapacity();
    int size_a = a.getSize();
    cout <<"capacity_a = "<<capa_a<<endl;
    cout <<"size_a = "<<size_a<<endl;

    for(int i = 10;i < 50;i++)
    {
        a.insert(i);
    }
    cout << endl;

    for (int j = 20; j < 30; j++)
    {
         a.getData(j);
         cout << "data" <<a.getData(j)<<endl;
    }

    cout << endl;


    a.SetData(34,99);
    int data = a.getData(34) ;
    cout << "data" <<data<<endl;

    capa_a = a.getCapacity();
    size_a = a.getSize();
    cout <<"capacity_a = "<<capa_a<<endl;
    cout <<"size_a = "<<size_a<<endl;

    MyArray b = a;
    int capa_b = b.getCapacity();
    int size_b = b.getSize();
    cout <<"capacity_a = "<<capa_b<<endl;
    cout <<"size_a = "<<size_b<<endl;



    return 0;
}
