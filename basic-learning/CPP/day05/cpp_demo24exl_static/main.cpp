#include <iostream>

using namespace std;

class Grade
{
public:
    Grade(float cprogram = 0)
    {
        this->m_cprogram = cprogram;
    }
    static float getAvg()
    {

        return m_avg;
    }
    static void setAvg(float value)
    {
        m_avg = value;
    }
    static float getTotal();
    static void setTotal(float total);

    float getCprogram() const; //const修饰成员函数，说明成员函数不会去修改类中成员变量的值
    void setCprogram(float cprogram);


private:

    float m_cprogram;
    static float m_avg; //平均分
    static float m_total; //总分
};

//类外初始化静态成员变量
float Grade::m_avg = 0.0;
float Grade::m_total = 0;

int main()
{
    const Grade g6; //const 对象不会去调用 非const成员函数


    Grade g1(60);
    Grade g2(70);
    Grade g3(80);
    Grade g4(90);
    Grade g5(50);
    float total = g1.getCprogram() + g2.getCprogram() + g3.getCprogram() + g4.getCprogram()
             + g5.getCprogram();
    cout << "total = " << total << endl; //total = 3

    Grade::setTotal(total);
    cout << Grade::getTotal() <<endl;

    Grade::setAvg(Grade::getTotal()/5);

    cout << Grade::getAvg() << endl; //通过类名来访问静态成员函数

    cout << g1.getAvg() << endl; //通过对象来访问静态成员函数

    return 0;
}

float Grade::getTotal()
{
    return m_total;
}

void Grade::setTotal(float total)
{
       m_total = total;
}

float Grade::getCprogram() const
{

    return m_cprogram;
}

void Grade::setCprogram(float cprogram)
{
    m_cprogram = cprogram;
}
