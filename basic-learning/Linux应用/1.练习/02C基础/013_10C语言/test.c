#include <stdio.h>


extern int c;
extern int add(int a,int b);
typedef unsigned int my_size_t;
int main(int argc, char **argv)
{
	my_size_t a = 10;
	printf("a:%d\n", a);
	
	// if()
	// {
		// printf("b:%d\n", b);
		// int b;
		
	// }

	// char *arr = "hello";
	// arr[1] = 'a';
	
	// printf("argc:%d\n", argc);
	
	// printf("argv[0]:%s\n", argv[0]);
	// printf("argv[1]:%s\n", argv[1]);
	
	printf("c:%d\n", c);
	
	printf("%d\n", add(1,2));
	
	return 0;
}