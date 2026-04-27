#include <iostream>

using namespace std;
//写两个函数模板：
//1.用来排序一个数组
//2.用来打印数组

template <typename T>
void sort(T dp[],int len)
{
    for(int i = 0;i < len;i++)
    {
        for (int j = 0; j < i; ++j) {
            if(dp[i] < dp[j])
            {
                T temp = dp[i];
                dp[i] = dp[j];
                dp[j] = temp;
            }
        }
    }
}

template <class A>
void print(A dp[],int len)
{
    for (int i = 0; i < len; ++i) {
        cout << dp[i] << " ";
    }
    cout <<endl;
}

int main(int argc,char *argv[])
{
    cout << "Hello World!" << endl;
    int a[5] = {1,3,3,23,12};
    int len = sizeof(a)/sizeof(a[0]);
    sort(a,len);
    print<int>(a,len);

    string s[5] = {"object-c","c++","java","py","basic"};
    sort<string>(s,5); //1 2 3 5 8
    print<string>(s,5); //basic c++ java object-c py

    return 0;
}
