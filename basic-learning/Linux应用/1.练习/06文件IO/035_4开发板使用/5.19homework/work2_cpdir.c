#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int cp_file(char **file_src,char **file_dest)
{
    //声明变量
    int fd1,fd2;
    int ret;
    
    //打开读取文件
    fd1 = open(*file_src,O_RDONLY,0777);
    if(fd1 ==-1)
    {
        printf("open %s err\n",*file_src);
        return -1;
    }
    printf("fd1 :%d\n",fd1);
    //打开写入文件
    fd2 = open(*file_dest,O_CREAT|O_RDWR|O_EXCL,0777);
    if(fd1 ==-1)
    {
        printf("open %s err\n",*file_dest);
        return -1;
    }
    printf("fd2 :%d\n",fd2);
    //循环从src读取，写入dest

    int read_buf[10000] = {0};
    while(1)
    {
        //开始读
        ret = read(fd1,read_buf,sizeof(read_buf));
        if(ret == -1)
        {    
            printf("read %s err",*file_src);
            break;
        }
        //如果ret==0代表读完了
        if(ret == 0)
        {
            break;
        }
        //读到多少写多少
        ret = write(fd2,read_buf,ret);
        if(ret == -1)
        {    
            printf("read %s err",*file_dest);
            break;
        }
        printf("file %s copy success \n",*file_src);
        //printf("read_buf :%ls\n",read_buf);
    }

    //关闭文件
    ret = close(fd1);
    if(ret == -1)
    {
        printf("close err\n");
        return -1;
    }
    //关闭文件
    ret = close(fd2);
    if(ret == -1)
    {
        printf("close err\n");
        return -1;
    }

    return 0;
}


int main(int argc,char **argv)
{
    int ret;
    //检查输入有效性
    if(argc != 3)
    {
        printf("输入程序名 要复制的目录 复制后的目录\n");
        //return -1;
    }
    /*
    ret = mkdir(argv[2],0x777);
    if(ret != 0)
    {
        printf("mkdir err \n");
        return -1;
    }*/
  
    /*
    ret = cp_file(&argv[1],&argv[2]);
    if(ret != 0)
    {
        printf("copy_file err \n");
        return -1;
    }*/
    char new[20] = {0}; 
    DIR *dir = opendir(argv[1]);
    while(1)
    {
        //读取目录项
        struct dirent *dp = readdir(dir);
        if(dp ==NULL)
            break;
        //跳过上级目录和下级目录
        if(strcmp(dp->d_name,"..")==0 ||strcmp(dp->d_name,".")==0)
            continue; 
        
        //sprintf(new,"1%s",dp->d_name);
        ret = cp_file(&dp->d_name,&new);
        if(ret != 0)
        {
            printf("copy_file err \n");
            return -1;
        }
        printf("%s  ",dp->d_name);
    }
    putchar('\n');

    return 0;

    
}