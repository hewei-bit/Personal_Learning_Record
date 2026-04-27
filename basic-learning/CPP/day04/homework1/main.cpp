#include <iostream>
#include "clock.h"
#include <windows.h>
#include <unistd.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    class clock c;
    while (1) {
        c.gettime();
        sleep(1);
    }

    return 0;
}
