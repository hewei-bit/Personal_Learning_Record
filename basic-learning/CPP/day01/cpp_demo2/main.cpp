#include <iostream>

using namespace std;
void swap(int* a,int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_r(int& a,int& b) //引用在做为函数形参时，不要初始化，其他情况必须初始化
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp; //引用很好的避免了指针带来的问题
}
int main()
{
    //[1] cin cout endl使用

#if 0
    int i,j;
    char c;
    //关于cin--- 标准输入相当于键盘 cout----标准输出，相当于屏幕或者控制台
    //<< ---- 该符号表示流输出重定向  >> ---- 该符号表示流输入重定向

    cout << "hello World!" << endl;
    cout << i <<endl; //将i的值输出到控制台
    cout << "请输入i>>j>>c"<<endl;
    cin >> i >> j >> c; //当输入多个时，可以按回车一个一个输出，或者在输入时，用空格进行分开进入
                        //当输入不同类型的变量值时，要按顺序进行输入
    cout << "i = "<<i << "j = " << j << "c = " << c;
#endif
    //[2] bool类型使用
#if 0
    //在c++中，bool类型只有true(1)和flase(0)
    bool flag = false;

        cout << "flag = " << flag << endl; //0

        flag = true;
         cout << "flag = "<< flag << endl; //1

         flag = -3;

         cout << "flag = "<< flag << endl; //1

         int a = flag;

         cout << "a = " << a << endl; //1
        #endif

      //[3] 三目运算符
#if 0
         int a =1,b=3;

             (a>b?a:b)= 5; //ok 返回的是a或b变量，而不是变量的值，所以可以做左值
            //(a>b?20:b)= 5; //error 三目运算符不能返回常量

             cout << "a = " << a << "b = "<<b <<endl;
#endif
     //[4] 引用的基本概念
             int r = 10;  //声明一个变量,分配一块内存给取名叫做r，并且把10赋值到内存空间上

             cout << "r = " << r << endl;
             r = 20; //重新直接通过r来修改所占内存的值
              cout << "r = " << r << endl;
             int* p_r = &r; //解引号跟类型在一起，说明该变量为指针变量
             //解引号跟变量在一起，表示读写内存
                // 解引号在赋值符号(=)左边 --- 写内存
                //解引号在赋值符号(=)右边 --- 读内存
             *p_r = 30; //通过指针间接修改所占内存的值
             cout << "r = " << r << endl;
             //在C++中，对于间接赋值操作有了更好的解决方案---引用
             int& rr = r; //引用在声明时，必须初始化，因为它是一个关系型声明，该引用变量不占空间

             cout << "&r" << &r << endl; //&r0x61feac
             cout << "&rr" << &rr << endl; //&rr0x61feac

             rr = 100;
              cout << "r = " << r << endl;

              int a = 3;
              int b = 5;
              //设计一个函数来交换a b的值
              cout << "交换前" << a << b <<endl;
              //swap(&a,&b);
              swap_r(a,b);
              cout << "交换后" << a << b <<endl;

              int& b_r = b; //说明引用变量与b指向同一块内存空间， b_r是变量b的别名

              int& b_rr = b; //一个变量可以有多个引用变量
              cout <<"b = " << b << "b_r = " << b_r << "b_rr = " << b_rr << endl; //3 3 3

              b_rr = 100;
              cout <<"b = " << b << "b_r = " << b_r << "b_rr = " << b_rr << endl;
              int& b_rrr = b_r;
              cout << "b_rrr = " << b_rrr << endl;
              return 0;
}
