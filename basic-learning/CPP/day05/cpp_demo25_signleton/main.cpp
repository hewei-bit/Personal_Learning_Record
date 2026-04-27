#include <iostream>

using namespace std;

class Test
{

};
//静态成员变量和成员函数应用：单例模式---一个系统中，某个类的对象始终是唯一
class SingleTon
{
public:
    //定义一个静态成员函数，该函数 的作用 是用来获取该类的一个对象
    static SingleTon* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new SingleTon; //调用无参的构构造函数，默认的无参构造函数是public
        }else {

            cout << "the object is created"<<endl;
            return instance;
        }
    }

    void test()
    {
        cout << " test() "<<endl;
    };


private:
    SingleTon() //手动实现无参的构造函数，将它设置为private
    {

    }
    //禁止类外尝试通过拷贝构造函数来创建对象
    SingleTon(const SingleTon& other) = delete ;

    //禁止类外尝试通过赋值运算符来给对象赋值，类似于int i = j;
    SingleTon& operator=(const SingleTon& other) = delete ;
    static SingleTon* instance;
};

SingleTon* SingleTon::instance = nullptr;

int main()
{
   // SingleTon s1;
    SingleTon* s1 = SingleTon::getInstance();
    s1->test();
    //SingleTon s2;
   // SingleTon s3 = s2; //防止使用拷贝构造函数实例化对象
   // SingleTon s4;
    //s4 = s2; //防止使用赋值运算符来初始化一个对象
   SingleTon* s2 = SingleTon::getInstance();
   cout << s1 <<"    " <<s2 << endl;
    return 0;
}
