#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <strings.h>

#define SWAP(a,b)       \
 do{                     \
     char temp = b;      \
     b = a;              \
     a = temp;           \
 }while(0)
	 
#define zhizhen  char *



void reverse(char buf[],int i)
{
    int j = 0;

    for(j = 0;j<i/2;j++)
    {
        if(j>=0)
            SWAP(buf[j],buf[i-1-j]);
        else
        printf("error\n");
    }
}

void itoa(int num,char buf[])
{
    int i = 0;
    do{
        buf[i] = num%10 + '0';
        i++;

        num /= 10;
    }while(num != 0);

    buf[i] = '\0';
    reverse(buf,i);
}


void my_printf(const char *format,...)
{
    va_list arg_ptr;
    va_start(arg_ptr,format);//让指针指向format

    int argnum = 0,i,j = 0;
    char arg[10];
    bzero(arg,10);
    int arg_int;

    //查验format字符串是否到结尾
    for(i = 0;format[i] != '\0';i++)
    {
        if(format[i] == '#')
        {
            switch(format[++i])
            {
                case 'i':
                    //指针向上偏移一个int类型,求得int值
                    arg_int = va_arg(arg_ptr,int);
                    itoa(arg_int,arg);
                    while(arg[j])
                        fputc(arg[j++],stdout);
                    break;
                // case 'f':
					// arg_double = va_arg(arg_ptr, double);
					// sum += arg_double;
					// break;
				default:
					printf("format error!\n");
					exit(1);
            }
        }
        else
        {
            fputc(format[i],stdout);
        }

    }

}






int main()
{
    int a = 12345;
    char  b = '0';
    float c = 0;
    char buf[10];

    printf("a:%d , b:%c ,c:%f \n",a,b,c);

    fputc('a',stdout);

    itoa(a,buf);
    printf("buf: %s \n",buf);

    my_printf("a:#i \n",a);
    return 0;
}