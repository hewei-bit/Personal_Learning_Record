#include <stdio.h>
#include <string.h>

/* 结构体模板声明 */
typedef struct stu
{
	char name[5];
	double age;
	int num;
}zhangsan,*wangwu;

typedef struct teacher
{
	char name[20];
	unsigned char age;
	int num;
} *TEACHER;

void test(struct stu *test)
{
	printf("test->name:%s, test->num:%d\n", test->name, test->num);
	test->num = 12345;
	printf("test->name:%s, test->num:%d\n", test->name, test->num);
}

int main() 
{

    TEACHER TT;
    struct teacher tt;
    
	// struct stu hewei = {"hewei", 18, 2020416};  //实例化结构体
	// struct stu hewei = {"hewei"};
	// struct stu hewei = {.name="hewei", .num = 2020416};
	// struct stu hw = hewei;

    struct stu hewei;
    hewei.num = 123123132;
    hewei.age=24;
    strcpy(hewei.name,"hewei");
    printf("%s \n",hewei.name);

    struct stu arr[3];
    arr[0] = hewei;
    printf("%s \n",arr[0].name);
    
    struct stu *p = &hewei;
    printf("%s \n",(*p).name);
    printf("%s \n",p->name);
    p->num = 456789;
    test(p);
    
    printf("sizeof(hewei) :%ld\n",sizeof(hewei));

    
	printf("&(hewei.name):%p\n", &(hewei.name));
	printf("&(hewei.age):%p\n", &(hewei.age));
	printf("&(hewei.num):%p\n", &(hewei.num));
    return 0;
}