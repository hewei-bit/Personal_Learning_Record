#include "FingerPrintModule.h"

using namespace std;

int main()
{
    FingerPrintModule *fp = new FingerPrintModuleA();
    fp->algorithm();
    delete fp;

    fp = new FingerPrintModuleB();
    fp->algorithm();
    delete fp;

    fp = new FingerPrintModuleC();
    fp->algorithm();
    delete fp;

    cout << endl;

    system("pause");

    return 0;
}