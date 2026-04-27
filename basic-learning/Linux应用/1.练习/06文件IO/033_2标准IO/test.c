#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>

int main(void)
{
	int ret;
	/* 打开文件*/
	FILE *fp = fopen("a.txt", "a+");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}
	
	/* 读取文件数据*/ 
	char buf[10] = {0};
	ret = fread(buf, 1, 2, fp);
	printf("ret:%d\n", ret);
	if(ret < 2)
	{
		if(!feof(fp))
		{
			if(ferror(fp))
			{
				perror("fread");
				return -1;
			}
		}	
		else
			printf("文件已经读取完\n");
	}
	printf("buf:%s\n", buf);
	
	/* 写入数据*/
	ret = fwrite("1234567", 1, 4, fp);
	if(ret < 4)
	{
		perror("fwrite");
	}
	fflush(fp);
	
	
	/* 关闭文件 */
	ret = fclose(fp);
	if(ret == EOF)
	{
		perror("fclose");
		return -1;
	}	
	
	int fd = 10;
	ret = close(fd);
	if(ret == -1)
	{
		printf("%s\n", strerror(errno));
	}
	
	
	return 0;
}