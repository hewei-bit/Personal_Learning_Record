#include <stdio.h>

int main(void)
{
	int a = 10;
	
	// if(a>10)
		// printf("a>10\n");
	// else
		// printf("a<=10\n");
	
	// if(a>10)
		// printf("a>10\n");
	
	// if(a>10 && a<=20)
		// printf("a>10 && a<=20\n");
	// else if(a<=30 && a>20)
		// printf("a<=30 && a>20\n");
	// else if(a<=40 && a>30)
		// printf("a<=40 && a>30\n");
	// else if(a<=50 && a>40)
		// printf("a<=50 && a>40\n");
	// else
		// printf("a<=10 或 a>50\n");
	
	// char b;
	// scanf("%c", &b);
	// switch(b)
	// {
		// case 43:printf("结果：+\n");break;
		// case '-':printf("结果：-\n");break;
		// case '*':printf("结果：*\n");break;
		// case '/':printf("结果：/\n");break;
		// case '%':printf("结果：%%\n");break;		
		// default:printf("没有找到该符号\n");
	// }
	
// a:
	// printf("%d\n", __LINE__);
	// goto lable;
	
	// printf("%d\n", __LINE__);

// lable:	
	// printf("%d\n", __LINE__);
	
	// goto a;
	
	// int i = 0;
	// while(i<10)
	// {
		// i++;
		// if(i<3)
			// continue;
		// printf("i:%d\n", i);
	// }
	
	int i = 0;
	while(i<10)
	{
		i++;
		if(i==3)
			break;
		printf("i:%d\n", i);
	}
	
	return 0;
}