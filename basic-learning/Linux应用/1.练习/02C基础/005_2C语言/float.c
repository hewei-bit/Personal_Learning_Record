#include <stdio.h>



int main(void)
{
	char arr[10]="abcdefg";
	float a = 1.123456;
	double b = 2.48;
	long double c = 1.0;
	int d = 4;
	
	
	printf("a:%ld, b:%ld, c:%ld\n", sizeof(a), sizeof(b), sizeof(c));
	printf("a:%f, b:%lf, c:%Lf\n", a, b, c);
	printf("a+d:%d\n", (int)a+d);
	
	arr[0] = '\0';
	printf("arr:%s\n", arr);
	
	printf("1\t234\b5678\n");
	
	return 0;
}