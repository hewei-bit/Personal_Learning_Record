#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc,char **argv)
{
    if(argc < 2)
    {
        printf("请输入文件名 目录名");
        return -1;
    }
    DIR *dir = opendir(argv[1]);

    
    while(1)
    {
        struct dirent *dp = readdir(dir);
        if(dp ==NULL)
            break;
        printf("dp->d_name :%s \n",dp->d_name);
        /*
        printf("dp->d_ino :%lu \n",dp->d_ino);
        //目录名
        
        //目录偏移量
        printf("dp->d_off :%d \n",dp->d_off);
        //该目录项大小
        printf("dp->d_reclen :%d \n",dp->d_reclen);
        //文件类型
        printf("dp->d_type :%d \n",dp->d_type);
        printf("\n");
        */
       /*
        char *p  = strstr(dp->d_name,".c");
        if(p != NULL)
        {
            printf("dp->d_name :%s \n",dp->d_name);
        }*/
        /*
        int i =0;
        int num = strlen(dp->d_name);
        
        for(i=0;i<num;i++);

        if(dp->d_name[i-2] == '.' && dp->d_name[i-1] == 'c')
        {
            printf("dp->d_name :%s \n",dp->d_name);
        }
        */
    }    

    return 0;
}


