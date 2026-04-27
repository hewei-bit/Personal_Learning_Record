#include <stdio.h>
#include <string.h>

union stu
{
    char name[5];
    char age;
    int num;
};

enum test {A,B,C =20,D};
union Un
{
    int a;
    char b;
};
int IsLittleEnd1()
{
    union Un u;
    u.a = 0x1;
    if (u.b==0x1)
    {
        printf("小端 \n");
        return 1; //小端
    }
    return 0; //大端
}


int main()
{
    union stu hewei;
    printf("sizeof(hewei):%ld\n", sizeof(hewei));
    
    strcpy(hewei.name,"hewei");
    printf("%s \n",hewei.name);
    hewei.num = 0x12345678;
    printf("%x \n",hewei.num);
    hewei.age = 0x12;
    printf("%x \n",hewei.age);
    printf("%x \n",hewei.num);
    // printf("%s \n",hewei.name);
    // printf("%d \n",hewei.age);
    printf("%ld \n",IsLittleEnd1());
    printf("A:%d\n", A);
	printf("B:%d\n", B);
	printf("C:%d\n", C);
	printf("D:%d\n", D);

    return 0;
}

    