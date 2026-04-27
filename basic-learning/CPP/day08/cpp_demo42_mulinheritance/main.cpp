#include <iostream>

using namespace std;

/*
多继承中，大多数会出现三解问题
1，在子类中出现各父类中可能都包含成员
2，访问父类中的都包含的成员，不方便访问

*/
class Bed
{

    public:
    void printB()
    {
        cout << "Bed::printB() " <<endl;
    }
    int material; //材质
    int t;
private:
    int b;
};

class SaFa
{
 public:
    void printS()
    {
        cout << "SaFa::printS() " <<endl;
    }
    int material; //材
};

class SafaBed :public Bed,public SaFa
{
public:
    void printSB()
    {

        this->printB();
        this->printS();
       // this->material = 10;
        this->t = 0;
        Bed::t = 10;
        Bed::material = 90; //手动指定使用哪一个基类的成员
        SaFa::material = 100; //使用起来不方便
    }
private:
    int sb;
};


int main()
{
    SafaBed sb;
    sb.printSB();
    return 0;
}
