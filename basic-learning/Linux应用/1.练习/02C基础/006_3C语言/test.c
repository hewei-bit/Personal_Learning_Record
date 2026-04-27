#include <stdio.h>

int main()
{
    int a=0x20;
	
	// a = 5/3;
	// printf("a:%d\n", a);
	
	//a = 11%2.0;   错误，%左右两边都要是整型
	// a = 11%2;
	// printf("a:%d\n", a);
	
	// a = 10;
	// printf("a:%d\n", a++);
	// printf("a:%d\n", a);	
	
	// a++;
	// ++a;
	// a = 10;
	// printf("a:%d\n", ++a);
	// printf("a:%d\n", a);	
	
	// if(a >= 10)
		// printf("a>=10\n");

    // a = 10;
	// if(a>20 && a++)
		// printf("a>20\n");
	
	// printf("a:%d\n", a);	
	
	// if(a<20 || a++)
		// printf("a<20\n");
	
	// printf("a:%d\n", a);
	
	
	// a = 14;

    // int b =36;

    //a=a^b;
    //b=a^b;
    //a=a^b;
    
    //printf("a:%d\n", a);
	//printf("b:%d\n", b);
    char b = 0x14;
    printf("b>>4 :%d \n",b>>4);
    /*//
    a &= ~1<<5;
    //
    a |= 1<<10;
    //
    a ^= 1<<15;
//
    (a>>20)&1;
*/
printf("max:%d \n ",a>b?a:b);
printf("min: %d \n",a>b?b:a);
printf("sizeod(%d) \n ",sizeof(a));



    return 0;
}


