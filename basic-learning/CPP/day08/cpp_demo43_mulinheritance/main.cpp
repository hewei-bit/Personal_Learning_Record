#include <iostream>

using namespace std;

//祖父类
//采用虚继承祖父类，使用关键字
//如果采用虚继承时，在当前的子类中系统会分配 一个vptr（虚函数表的指针）
//该虚函数指针指向虚函数：子类的虚析构函数，当前类中的虚函数
//将这些虚函数存放在虚函数表中，vptr指针指向第一个表中的函数
//这些操作是由编译器在程序运行的时候，自动创建时
class Material
{

public:
    Material()
    {
        cout << "material:: material()" << endl;
    }
    int material; //材质
};


class Bed :virtual public  Material
{

    public:
    Bed()
    {
        cout << "Bed:: Bed()" << endl;
        this->material = 30;
    }
    void printB()
    {
        cout << "Bed::printB() " <<endl;
        //在儿子类(基类中)访问祖父类中的成员
       // this->material = 30;
        cout << "material = " << this->material<<endl;
    }

    int t;
private:
    int b;
};



//destructor --- 析构  constructor --- 构造器
class SaFa :virtual public Material
{
 public:
    SaFa()
    {
         cout << "SaFa:: SaFa()" << endl;
        this->material = 20;
    }
    virtual void test()
    {

    }
    void printS()
    {
        cout << "SaFa::printS() " <<endl;
        //this->material = 20;
        cout << "material = " << this->material <<endl;

    }
    //虚析构函数
    virtual ~SaFa()
    {

    }
};

class SafaBed :public Bed,public SaFa
{
public:

    SafaBed()
    {
        cout << "SafaBed:: SafaBed()" << endl;
        this->material = 10;
    }
    void printSB()
    {

        this->printB();
        this->printS();
        //在派生类(孙子类中访问祖父类中的成员)
       // this->material = 10; //三角问题，使用起来不方便
        this->t = 0;
       // this->material = 0;
        cout << "material = " << this->material <<endl;

    }
    virtual ~SafaBed()
    {

    }
private:
    int sb;
};




int main()
{
    SafaBed sb;
    sb.printSB(); //10 10 10 输出是这一份副本值
    SaFa sf;
    sf.printS(); //20 输出是这一份副本值
    Bed bd;
    bd.printB(); //30  输出是这一份副本值

    Material m;
    cout << m.material << endl; //真正的原件并没有初始化，所以输出随机值：1957153984

    return 0;
}
