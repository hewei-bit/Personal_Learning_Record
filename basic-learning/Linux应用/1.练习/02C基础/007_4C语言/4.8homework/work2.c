#include <stdio.h>



int main()
{
    int i;
    float s = 100,h =100;

    for(i=1;i<9;i++)
    {
        h=h/2;
        s+=h/2;
    }

    printf("高度:%f \n",h);
    printf("路程: %f \n",s);



    return 0 ;
}
