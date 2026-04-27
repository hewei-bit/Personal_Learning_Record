#include "myclock.h"

Myclock::Myclock()
{


}

Myclock::Myclock(int hour, int minute, int second):hour(hour),minute(minute),second(second)
{

}

Myclock::~Myclock()
{
    cout << " ~Myclock() "<<endl;
}

Myclock &Myclock::operator++()
{
    if(this->second++ == 60)
    {
        this->second = 0;
        if(this->minute++ == 60)
        {
            this->minute = 0;
            if(this->hour++ ==24)
            {
                this->hour = 0;
            }
        }
    }
    return *this;
}



Myclock &Myclock::operator--()
{
    if(this->second-- == 0)
    {
        this->second = 59;
        if(this->minute-- == 0)
        {
            this->minute = 59;
            if(this->hour-- ==0)
            {
                this->hour = 23;
            }
        }
    }
    return *this;
}

Myclock &Myclock::operator++(int)
{
    if(this->second++ == 60)
    {
        this->second = 0;
        if(this->minute++ == 60)
        {
            this->minute = 0;
            if(this->hour++ ==24)
            {
                this->hour = 0;
            }
        }
    }
    return *this;
}

Myclock &Myclock::operator--(int)
{
    if(this->second-- == 0)
    {
        this->second = 59;
        if(this->minute-- == 0)
        {
            this->minute = 59;
            if(this->hour-- ==0)
            {
                this->hour = 23;
            }
        }
    }
    return *this;
}

void Myclock::show()
{
    system("cls");
    cout << setfill('0')<<setw(2)<<this->hour<<":"<<setw(2)<<this->minute<<":"
         <<setw(2)<<this->second<<endl;
}

void count(Myclock &cc)
{

    sleep(1);
    cc++;
    cc.show();

}

void countReverse(Myclock &cc)
{

    sleep(1);
    cc--;
    cc.show();

}
