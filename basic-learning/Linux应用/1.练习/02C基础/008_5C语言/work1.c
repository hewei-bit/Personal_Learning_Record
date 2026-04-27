/* 编写一个函数，接收两个整型，求得两个整型数之间的素数的个数并返回。 */ 
#include <stdio.h>
#include <stdlib.h>
/*  求一个数是否是素数 */
int prime(int n)
{
    int flag = 1;
    for(int i = 2;i<n/2;i++)
    {
        if(n%i == 0)
        {
            flag =0;
            break;
        }
    }
    return flag;
}

/* 求x~y之间素数的个数 */
int fun(int x,int y)
{
    int  num = 0;
    for(int i = x;i < y;i++)
    {
        if(prime(i) == 1)
            num++;
    }
    return num;
}


int main(int argc,char **argv) 
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int ret = fun(a,b);
    printf("ret:%d \n",ret);
    return 0;
}