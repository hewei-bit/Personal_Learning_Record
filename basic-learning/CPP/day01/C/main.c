#include <stdio.h>

int main()
{
    const int i = 20;
    char p[6] = "hello";
    *(p+1) = 'H';
//    int* p  = &i;
//    *p = 30;
    printf("%s\n",p);
    printf("i = %d\n",i);
    printf("Hello World!\n");
    return 0;
}
