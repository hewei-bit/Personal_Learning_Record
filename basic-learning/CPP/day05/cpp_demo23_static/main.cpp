#include <iostream>

using namespace std;

class Test{
public:
    //注意事项：静态成员变量不能用构造函数初始化列表来初始化
    Test(int a=0):a(a)
    {
       // this->b = b; //ok ，但是，不推荐，有可能在某些编译器不支持

    }

    void printT()
    {
        cout << this->a << this->b << endl;
       setB(5); //ok 在非静态成员函数中，可以调用静态成员函数
       b = 10;

       cout << this->a << this->b << endl;
    }
    static int getB()
    {
       // printT()； //error静态成员函数中，不能调用非static成员函数
        // a = 10;  //error静态成员函数中，不能使用非static成员变量
        return b;
    }
    static void setB(int value)
    {

        b = value;
    }

private:
    int a;
    //对于静态成员变量，在C++中，如果使用公有的修饰限定，就可以直接通过类本身来访问和使用
        //可以不通过对象来使用，但是，public破坏了类的封装性，为了保持封闭性，可以使用接口:
        //静态成员函数来访问，也是该函数存在的意义,该函数也是属于类本身
    static int b; //[1]在类中声明静态成员变量
};

 int Test::b = 100; //[2]在类外初始化静态成员变量
int main()
{
    //[3] 使用静态成员变量：类本身来访问，类的对象来访问
    //cout << Test::b <<endl;
    cout<<Test::getB() << endl; //因为静态成员函数，是属于类本身
    Test t;
    t.printT();
    //t.setB(200);
    cout << t.getB() <<  " "  << Test::getB() << endl;
    return 0;
}
//int getB()
//{
//    return b;
//}
/*总结：
 * 1.静态成员变量和静态成员函数都是属于类本身，所以直接通过类名来访问
 * 2.静态成员变量在类中声明，并且要加static，在类外定义初始时，要去掉static
 * 3.静态成员函数它是外界访问类中静态成员变量的方法，也直接通过类名来调用
 * 4.静态成员函数如果在类中声明时，要加static关键字，在类外定义时，要去掉static
 *    如果在类中定义 时，要保留static
 * 5. 由于静态成员函数是属于类本身，在调用的时候，可以不通过对象不调用它，所以this指针在
 *   静态成员函数中失效
 * 6. 静态成员函数中，不能调用非static成员函数和不能使用非static成员变量,除非静态
 * 成员函数的形参是该类的对象时，反之，非静态成员函数可以使用静态成员变量和函数
 * */



