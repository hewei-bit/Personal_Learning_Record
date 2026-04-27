#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void fun1()
{
    printf("fun1 \n");

}
void fun2()
{
    printf("fun2\n");
}

int main()
{
    atexit(fun1);
    atexit(fun2);
    fprintf(stdout,"abcsdcsd\n");

#ifdef _EXIT
    _exit(0);
#else
    exit(0);
#endif // DEBUG

    return 0;
}