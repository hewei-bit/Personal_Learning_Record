#include "clock.h"

clock::clock()
{
    time(&now);
    p = localtime(&now);
}

void clock::gettime()
{
    time(&now);
    p = localtime(&now);
    cout <<p->tm_hour <<":"<<p->tm_min <<":"<< p->tm_sec<<endl;
}
