#include <stdio.h>
#include <stdlib.h>

int *test(int a)
{
    int *arr = (int *)malloc(100);  //使用指针p指向100字节的堆内存
	if(arr == NULL)
	{
		printf("malloc err!\n");
		return (int *)-1;
	}
	printf("%d, %d, %d\n", *(arr), *(arr+1), *(arr+2));
	
    *(arr+1) = 10;
    return arr;
}


int main(void)
{
    int *arr = (int *)malloc(100);  //使用指针p指向100字节的堆内存
	if(arr == NULL)
	{
		printf("malloc err!\n");
		return -1;
	}
	printf("%d, %d, %d\n", *(arr), *(arr+1), *(arr+2));
	
	free(arr);
	arr = NULL;


    char *p = (char *)calloc(25,4);
    if(p == NULL) 
    {
        printf("malloc err \n");
        return -1;
    }
    scanf("%s",p);
    printf("%s \n",p);
    printf("sizeof(p): %ld \n",sizeof(p));
    printf("%p \n",p);
    free(p);
    p = NULL;

    int *k = test(3);
    if(k == (int  *)-1)
        printf("test err \n");
    else
        printf("*(k+1) : %d\n",*(k+1));

    free(k);
    k = NULL;
    

    return 0;

}