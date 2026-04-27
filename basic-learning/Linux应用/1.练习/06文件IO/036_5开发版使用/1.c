#include <stdio.h>


int main()
{
    int i;
    for( i = 1;i < 10;i++)
    {
        char bmp[10] = {0};
        sprintf(bmp,"%d.bmp",i);
        printf("%s",bmp);
        
    }
    return  0;
}