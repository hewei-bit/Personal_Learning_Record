#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char **argv)
{
/*
	// 关闭0之后，不能使用scanf函数从键盘获取数据
	close(0);
	
	int data = 0;
	int ret = scanf("%d", &data);
	printf("data:%d\n", data);
	printf("ret:%d\n", ret);
	
	// 从0中读取键盘上输入的数据
	char buf[10]={0};
	int ret = read(0, buf, 10);
	printf("buf:%s\n", buf);
	printf("ret:%d\n", ret);
	*/
	
	/*
	//关闭1之后，不能使用printf函数将数据输出到屏幕上
	close(1);
	
	int ret = printf("after close(1)\n");
	printf("ret:%d\n", ret);
	*/

	// 使用write函数将数据写入到2后，数据会显示到屏幕
	close(1);
	int ret = printf("after close(1)\n");
	// if(ret == -1)
	// {
		
	// }
	write(2, "printf err\n", 12);
	
	
	
	return 0;
}
