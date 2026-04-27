#include <stdio.h>

void fun10(void)
{
	printf("%s\n", __FUNCTION__);	
}

int main(void)
{
	int a;
	int n;
	fun10();
	printf("申请资源1\n");
	scanf("%d", &a);
	if(a < 0)
		goto err_num1;

	printf("申请资源2\n");
	scanf("%d", &n);
	if(n < 0)
		goto err_num2;

	printf("申请资源之后要做的操作\n");

	return 0;
	
err_num1:	
	printf("资源1申请失败!\n");
	printf("查找失败原因\n");
	return -1;
err_num2:	
	printf("资源2申请失败!\n");
	printf("查找失败原因\n");
	return -2;
}