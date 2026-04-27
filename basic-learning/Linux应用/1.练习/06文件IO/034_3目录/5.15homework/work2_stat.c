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


//#define S_IFMT 0b1111000000000000

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

    putchar('\n');
}







int main(int argc,char **argv)
{
    struct stat info;
    int ret = stat("a.txt",&info);
    if(ret != 0)
    {
        perror("stat");
        return  -1;
    }
    
    //普通文件所在存储器的设备号
    printf("dev : %lu\n",info.st_dev);
    int num1 = major(info.st_dev);
    int num2 = minor(info.st_dev);
    printf("major=%d,minor=%d \n",num1,num2);

    //文件类型、文件权限
    printf("mode : %lu\n",info.st_mode);
    print_type(&info);
    print_perm(&info);

    //文件索引号
    printf("ino : %lu\n",info.st_ino);

     //引用计数
    printf("nlink : %lu\n",info.st_nlink);

     //文件所有者的 UID
    printf("uid : %lu\n",info.st_uid);

    //文件所属组的 GID
    printf("gid : %lu\n",info.st_gid);

    //特殊文件的设备号
    printf("rdev : %lu\n",info.st_rdev);

    //文件大小
    printf("size : %lu\n",info.st_size);

    //文件所占数据块数目
    printf("st_blocks : %lu\n",info.st_blocks);

    //最近访问时间
    
    printf("st_atime : %s",ctime(&info.st_atime));
    //最近修改时间
    printf("st_mtime : %s",ctime(&info.st_mtime));
    //printf("st_mtimensec : %lu\n",info.st_mtimensec);
    //最近属性更改时间
    printf("st_ctime : %s",ctime(&info.st_ctime));
    //printf("st_ctimensec : %lu\n",info.st_ctimensec);

    // 写数据块建议值
    printf("st_blksize : %lu\n",info.st_blksize);
    

    //uid相关
    struct passwd *usr_info = getpwuid(info.st_uid);
    printf("usr_info->pw_name:%s \n",usr_info->pw_name);

     printf("usr_info->pw_uid:%d \n",usr_info->pw_uid);   

    //gid相关
    


return 0;

}
