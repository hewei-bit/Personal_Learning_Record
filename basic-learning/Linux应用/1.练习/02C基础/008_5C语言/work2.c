/* 282例 119 */ 
#include <stdio.h>

int fun(int n)
{
	//1、确定问题变量
	int age = 0;
	
	//3、确定结束条件
	if(n == 1)
		return 10;
	else
		age = fun(n-1)+2; //2、确定递归公式
	
	return age;
		
}

int main(int argc, char const *argv[])
{
	int age = 10, i = 4;
	
	while(i--)
		age += 2;
	printf("age:%d\n", age);
	
	printf("age:%d\n", fun(5));
	
	return 0;
}