#ifndef MYCLOCK_H
#define MYCLOCK_H

#include <iostream>
#include <unistd.h>
#include <iomanip>
using namespace std;

class Myclock
{
public:
    Myclock();
    Myclock(int hour = 0,int minute = 0,int second =0);
    ~Myclock();
    Myclock &operator++();
    Myclock &operator--();
    Myclock &operator++(int);
    Myclock &operator--(int);

    void show();


private:
    int hour;
    int minute;
    int second;
};

void count(Myclock &cc);
void countReverse(Myclock &cc);

#endif // MYCLOCK_H
