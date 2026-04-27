#include <iostream>
#include <ctime> //#include <time.h>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
using namespace std;

class CClock{
public:
    CClock()
    {
        //在创建时间对象时，就应该去获取系统时间
        time_t _time = time(NULL); //到当前时间的距离 1970-1-1 00：00：00
        //
       tm *pTm = localtime(&_time); //把时间距离传入给localtime，返回当前时间的结构体
       this->m_hour = pTm->tm_hour;
       this->m_minute = pTm->tm_min;
       this->m_second = pTm->tm_sec;

      // cout << this->m_hour << ":" << this->m_minute <<":" << this->m_second<<endl;
    }


    void Run()
    {

       while(1)
       {
           //设计一个算法，该算法只对内部可见
           this->Tick();

           //显示时间
           this->showTime();
       }

    }
private:
    //计算时间的算法
    void Tick()
    {
        sleep(1);
        if(++this->m_second == 60)
        {
            this->m_second = 0;
            if(++this->m_minute == 60)
            {
                this->m_minute = 0;
                if(++this->m_hour == 24)
                {
                    this->m_hour = 0;
                }
            }
        }
    }

    void showTime()
    {
        //清屏
        system("cls");
        //setfill('0')  setw(2)  ---> 设置字符的宽度，不够的用0去填充
        cout << setfill('0') << setw(2) << this->m_hour << ":" << setw(2)
             << this->m_minute << ":" << setw(2) << this->m_second <<endl;
    }
private:
    int m_hour;
    int m_minute;
    int m_second;
};
int main()
{
    CClock clock;
    clock.Run();



    return 0;
}
