/* 282例 119 */ 
#include <stdio.h>

int fun(int x)
{
    int i = 1, k = 1, j = 1;
	while(j <= x)
	{
		if(j == 1)
			printf("1,");
		else if(j == 2)
			printf("1,");
		else
		{ 
			int tmp;
			tmp = i+k;
			i = k;
			k = tmp;
			printf("%d,",tmp);
			
		}
		j++;
	}
	
	printf("\n");
		
}

int fun1(int n)
{
	int num;
	if(n==1 || n == 2)
		return 1;
	else
		num = fun1(n-1)+fun1(n-2);
	return num;
}

int main(int argc, char const *argv[])
{
int a, i = 1;
	printf("input num:\n");
	scanf("%d", &a);
	fun(a);
	
	while(i<=a)
		printf("%d,", fun1(i++));
		
	printf("\n");
		
	return 0;
}