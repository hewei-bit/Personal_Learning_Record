#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define NONE                 "\e[0m"
#define L_GREEN              "\e[1;32m"
#define YELLOW                  "\e[1;32m"


void print_type(struct stat *info)
{
	switch(info->st_mode&S_IFMT)
	{
		case S_IFSOCK:printf("s"); break;
		case S_IFLNK:printf("l") ; break;
		case S_IFREG:printf("-") ; break;
		case S_IFBLK:printf("b") ; break;
		case S_IFDIR:printf("d") ; break;
		case S_IFCHR:printf("c") ; break;
		case S_IFIFO:printf("p") ; break;
	}
}


//打印文件权限
void print_perm(struct stat *info)
{
	char rwx[] = {'r','w','x'};
	for(int i=0; i<9; i++)
		printf("%c",info->st_mode&(0400>>i)?rwx[i%3]:'-');

    putchar(' ');
}


int main(int argc,char **argv)
{
    //没有参数
    if(argc < 2)
    {
        DIR *dir = opendir(".");
        while(1)
        {
            //读取目录项
            struct dirent *dp = readdir(dir);
            if(dp ==NULL)
                break;
            //跳过上级目录和下级目录
            if(strcmp(dp->d_name,"..")==0 ||strcmp(dp->d_name,".")==0)
               continue; 

            printf("%s  ",dp->d_name);
        }
        putchar('\n');
        return 0;
    }

    //当参数为-l、-al、-la时
    if(strcmp(argv[1] ,"-l") == 0 || strcmp(argv[1],"-la") == 0 || strcmp(argv[1],"-al") == 0 )
    {
        //printf("-l \n");
        int sum = 0 ;
        //打开目录以获得目录指针
        DIR *dir = opendir(".");
        while(1)
        {
            //读取目录项
            struct dirent *dp = readdir(dir);
            if(dp ==NULL)
                break;
            //打印文件信息
            struct stat info;
            int ret =  stat(dp->d_name,&info);
            if(ret != 0)
            {
                perror("stat");
                return  -1;
            }
            //当参数为-l时
            if(strcmp(argv[1] ,"-l") == 0)
            {
                //跳过上级目录和下级目录
                if(strcmp(dp->d_name,"..")==0 ||strcmp(dp->d_name,".")==0)
                {
                    //sum += info.st_size;
                    continue;
                }
            }
            
            //文件类型
            print_type(&info);
            print_perm(&info);
            //用户名
            struct passwd *usr_info = getpwuid(info.st_uid);
            printf("%s ",usr_info->pw_name);
            //组名
            struct group *grp_info = getgrgid(info.st_gid);
            printf("%s ",grp_info->gr_name);
            
            //文件大小
            printf("%5lu ",info.st_size);
            sum += info.st_size;
            //创建时间
            struct tm *tim= localtime(&info.st_atime);
            printf("%d月 %4d %d:%2d  ",tim->tm_mon+1,tim->tm_mday,tim->tm_hour,tim->tm_min);

            //printf("%s",ctime(&info.st_atime));
            //文件名
            printf( YELLOW "%s " NONE,dp->d_name);//"\e[1A"
            putchar('\n');
        }
        sum = sum/1024;
        printf("总用量：%d \n",sum);
        return 0;
    }

}