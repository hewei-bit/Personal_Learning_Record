#include <stdio.h>

int main(void)
{
	int a = 100000;
	char b = '0';
	float c = 1.2;
	const char arr[5] = "abcd";
	
	printf("%s\n", arr);
	printf(arr);
	
	printf("a:%d, b:%c, c:%f, arr:%s\n", a, b, c, arr);
	printf("a:%5d, b:%5c, c:%5f, arr:%2s\n", a, b, c, arr);

	int a1 = 10;
	int a2 = 432;
	int a3 = 65;
	int a4 = 3246;
	int a5 = 146567;
	int a6 = 324546;
	
	printf("%7d%7d%7d\n", a1, a2, a3);
	printf("%7d%7d%7d\n", a4, a5, a6);
	
	printf("c:%6.8f\n", c);
	
	
	return 0;
}