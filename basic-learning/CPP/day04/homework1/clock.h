#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <ctime>

using namespace std;

class clock
{
public:
    clock();
    clock(const clock &other){}
    ~clock(){}
    void gettime();
private:
    time_t now;
    tm* p;
};








#endif // CLOCK_H
