#include <stdio.h>
#include "calcu.h"
#include "input.h"

int main(int argc,char *argv[])
{
	printf("Hello!\n");
	int a,b,num;

	input_int(&a,&b);
	num = calcu(a,b);
	

	printf("%d+%d=%d\n",a,b,num);


	return 0;
}
