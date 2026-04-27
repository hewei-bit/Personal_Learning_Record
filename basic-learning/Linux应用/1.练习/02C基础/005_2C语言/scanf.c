#include <stdio.h>

int main(void)
{
	int a, b, c;
	int ret;
	/*
	printf("input a value:\n");
	scanf("%d", &a);
	printf("a:%d\n", a);
	*/
	printf("input a、b、c value: a,b,c\n");
	scanf("%d,%d,%d", &a, &b, &c);
	ret = printf("a:%d, b:%d, c:%d\n", a, b, c);
	printf("ret:%d\n", ret);
	
	return 0;
}