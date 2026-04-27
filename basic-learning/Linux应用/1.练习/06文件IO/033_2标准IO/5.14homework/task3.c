#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//文件完整复制，断点续传
int copy_file_continue(char *src,char *dest)
{
    //打开被复制文件文件
    int fd_src = open(src,O_RDONLY);
    if(-1  == fd_src)
    {
        printf("open src error \n");
        return -1;
    }
    printf("fd_src: %d \n",fd_src);
    //打开目标文件
    int  fd_dest = open(dest,O_RDWR|O_CREAT,0777);
    if (-1 == fd_dest)
    {
        printf("open src error \n");
        return -1;
    }
    printf("fd_dest: %d \n",fd_dest);
    //求临时文件大小
    int dest_size = lseek(fd_dest,0,SEEK_END);
    //将被复制文件位置外后偏移
    lseek(fd_src,dest_size,SEEK_SET);
    //循环从src中读取数据，写到dest
    int ret =0 ;
    int buf_read[10000] = {0};
   
   while(1)
   {
       ret = read(fd_src,buf_read,sizeof(buf_read));
       if(ret == -1)
       {
           printf(" read err \n");
           return -1;
       }

       if ( ret == 0)
       {
           break; 
       }

       ret = write(fd_dest,buf_read,ret);
        if(ret == -1)
       {
           printf(" write err \n");
           return -1;
       }
   }
   
    //关闭文件src
    ret = close(fd_src);
    if(-1 == ret)
    {
        printf("close err \n");
    }
    //关闭文件dest
    ret = close(fd_dest);
    if(-1 == ret)
    {
        printf("close err \n");
    }
}

int main(int argc,char **argv)
{
    if(argc != 3)
    {
        printf("输入程序名 要复制文件 复制后文件名\n");
        return -1;
    }
    char file_name[30] = {0};


    //判断b是否存在
    int fd_b = open(argv[2],O_RDWR|O_EXCL,0777);
    //b存在
    if(fd_b !=-1)
    {
        
        char flag;
        printf("文件%s已经存在，是否继续复制： \n",argv[2]);
        scanf("%c",&flag);

        //不复制，直接退出程序
        if('N' == flag)
        {
            return 0;
        }
        //复制，将文件b清空，写入a文件的内容（将文件b删除，新建文件b.tmp开始复制）
        else if('Y' == flag)
        {
            remove(argv[2]);

            sprintf(file_name,"%s.tmp",argv[2]);
            printf("file_name:%s \n",file_name);

            copy_file_continue(argv[1],file_name);
        }
        else
        {
            printf("输入有误 \n");
            return -1;
        }
    }
    //b不存在，检测b.tmp是否存在
    else
    {
        sprintf(file_name,"%s.tmp",argv[2]);
        printf("file_name:%s \n",file_name);

        int fd_tmp = open(file_name,O_RDWR);
        //b.tmp存在 断点续传
        if(fd_tmp != -1)
        {
            copy_file_continue(argv[1],file_name);      
        }
        //b.tmp不存在
        else
        {
            copy_file_continue(argv[1],file_name);

            close(fd_tmp);
        }
        close(fd_b);
    }
    //文件更名b.tmp-->b
    rename(file_name,argv[2]);

    return 0;
}



