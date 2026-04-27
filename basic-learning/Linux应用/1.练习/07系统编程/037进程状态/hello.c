#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc,char ** argv)
{
    printf("argv[0]:%s \n" , argv[0]);
    printf("argv[1]:%s \n" , argv[1]);
    printf("argv[2]:%s \n" , argv[2]);
    printf("%d \n" , __LINE__);
    printf("hello \n");
    return 20;
}