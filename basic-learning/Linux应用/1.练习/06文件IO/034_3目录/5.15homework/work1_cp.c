#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
 #include <sys/types.h>


//断点续传和完整复制
int send_continue(char *src,char *dest)
{
	FILE *fd_1 = fopen(src,"r"); //打开要复制的文件
	if(fd_1 == NULL)
	{
		printf("打开文件失败！\n");
		return -1;
	}

	FILE *fd_2 = fopen(dest,"a+"); //打开或创建复制后的文件
	if(fd_2 == NULL)
	{
		printf("打开文件失败！\n");
		return -1;
	}

	int ret = fseek(fd_2,0,SEEK_END);  //将复制后的文件位置偏移到末尾
	if(ret)
	{
		perror("fseek");
		return -1;
	}
	int ret_dest = ftell(fd_2);//获取fd_2的位置偏移量
	
	/* 将要复制的文件位置偏移量往后偏移 */
	ret = fseek(fd_1, ret_dest, SEEK_SET);
	if(ret)
	{
		perror("fseek");
		return -1;
	}
	

	char buff[100000] = {};
	int num = 0;
	while(1)
	{
		num = ftell(fd_1);
		ret = fread(buff,1,100000,fd_1);
		if(ret < sizeof(buff))
		{
			if(!feof(fd_1))  //文件没有到达末尾，查看遇到了什么错误
			{
				if(ferror(fd_1))
				{
					perror("fread");
					return -1;
				}
			}	
			else   //读取文件到达末尾，读取完成退出循环
			{
				num = ftell(fd_1) - num;
				fwrite(buff,1,num,fd_2);
				break;
			}
				
		}

		/* 从fd_1中读取了多少个数据，写入多少数据到fd_2中 */
		ret = fwrite(buff,1,ret,fd_2);
		if(ret <= 0)
		{
			perror("fwrite");
			break;
		}
	}

	fclose(fd_1);//关闭文件
	fclose(fd_2);
	//free(buff);
	
	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("输入程序名 要复制的文件 复制后的文件名\n");
		return -1;
	}
	
	char file_name[30] = {};
	
	FILE *fd_1 = fopen(argv[1],"r"); //打开要复制的文件
	if(fd_1 == NULL)
	{
		printf("打开文件失败！\n");
		return -1;
	}
	// fread(file_name,3,sizeof(file_name)/3,fd_1);
	// printf("%s\n",file_name);
	// memset(file_name, 0, 30);
	FILE *fd_2 = fopen(argv[2],"r+"); //打开复制后的文件
	if(fd_2 == NULL)  //文件不存在
	{
		sprintf(file_name, "%s.tmp", argv[2]);	//新建文件名
		FILE *fd_2tmp = fopen(argv[2],"a+"); //打开或创建复制后的文件
			
		send_continue(argv[1], file_name);	//2.tmp断点续传

		fclose(fd_2tmp);
	}       
	else   //复制后的文件已经存在
	{
		char flag;
		printf("文件%s已存在,是否继续复制[Y/N]\n", argv[2]);
		scanf("%c", &flag);
		if(flag == 'N') //不复制，直接退出程序
			return 0;
		else if(flag == 'Y') //复制，将文件fd_2清空，写入fd_1文件的内容(将文件2删除，新建b.tmp文件开始复制)
		{
			remove(argv[2]); //删除复制后的文件
			
			sprintf(file_name, "%s.tmp", argv[2]); //新建文件名
	
			send_continue(argv[1], file_name);
			
		}	
		else
		{
			printf("输入有误！\n");
			return -1;
		}	
		int ret = fclose(fd_2);
		if(!ret)
			printf("关闭文件成功！\n");
		else
		{
			printf("关闭文件失败！\n");
			exit(1);
		}
	}
	
	//文件更名  b.tmp -->  b
	rename(file_name, argv[2]);
	int ret = fclose(fd_1);
	if(!ret)
		printf("关闭文件成功！\n");
	else
	{
		printf("关闭文件失败！\n");
		exit(1);
	}
		
	return 0;
}


