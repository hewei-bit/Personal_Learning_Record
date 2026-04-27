#include <iostream>

using namespace std;
//求数组中的最大值
//思路一 ：先对数组进行排序，然后输出第一个元素或者最一个元素值
//思路二：打擂台
template <class T>
void myMax(T a[],int len,T* ret)
{
      *ret = a[0]; //假设第一个值最大
    for (int i=0;i<len;i++) {

        if(*ret > a[i])
        {

        }else {
           *ret = a[i];
        }
    }
}

//输出一个数组
template <typename A>
void printT(A a[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int max;
    float max1;
       int a[5] = {1,3,8,5,2};

       printT(a,5);
       myMax(a,5,&max);
       cout << "max = " << max << endl;

       cout << "===========" << endl;
       float b[5] = {1.2,3.5,8.1,5.5,2.5};
       printT(b,5);
       myMax(b,5,&max1);
       cout << "max1 = " << max1 << endl;
    return 0;
}
