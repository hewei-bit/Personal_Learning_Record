#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int process =0;

int cp_file_to_file(char *file_src,char *file_dest)
{
    //打开读取文件
   FILE *fd_src = fopen(file_src,"r+");
    //打开写入文件
    FILE *fd_dest = fopen(file_dest,"w+");
    if(fd_dest == NULL|| fd_src == NULL)
    {
        perror("fopen");
        return -1;
    }
    char buf[500] = {0};
    int nread;
    long start,end;
    int total_size = 0;

    while(1)
    {
        bzero(buf,500);//清空数组
        start = ftell(fd_src);//获取文件偏移量
        nread  = fread(buf,100,5,fd_src);//从原文件读取数据
        if(nread == 5)//读满500字节
        {
            fwrite(buf,100,5,fd_dest);//将500字节写入目标文件
            total_size += 500;
        }
        else //不满500字节
        {
            if(feof(fd_src))//读到文件末尾
            {
                end = ftell(fd_src);//获取文件偏移量
                fwrite(buf,end-start,1,fd_dest);//将剩下不足500字节写入目标文件
                total_size += end -start;
                printf("总共复制%d字节 \n",total_size);
                break;
            }
            if(ferror(fd_src))//读数据出错
            {
                break;
            }
        }
    }
    return 0;
}

int cp_file_to_dir(char *file_src,char *dir_dest)
{
    char file_path[100] = {0};
    sprintf(file_path,"%s/%s",dir_dest,file_src);
    cp_file_to_file(file_src,file_path);
}

int cp_dir_to_dir(char *dir_src,char *dir_dest)
{
    char dir_path[100] = {0};
    if(access(dir_dest,F_OK))//目录不存在
    {
        mkdir(dir_dest,0x777);//创建目录
    }
    else
    {
        sprintf(dir_path,"%s/%s",dir_dest,dir_src);
    }

    DIR *dp = NULL;
    struct dirent *ep = NULL;

    dp = opendir(dir_src);//打开源目录
    if(dp == NULL)
    {
        perror("opendir");
        return -1;
    }

    char src_path[100] = {0};
    char dest_path[100] = {0};
    struct stat buf;

    while(1)
    {
        ep = readdir(dp);
        if(ep == NULL)//无文件则退出
            break;
        if(strncmp(ep->d_name,".",1) == 0)//排除隐藏文件
            continue;
        sprintf(src_path,"%s/%s",dir_src,ep->d_name);
        sprintf(dest_path,"%s/%s",dir_dest,ep->d_name);

        printf("%d \n",__LINE__);
        printf("src:%s,dest:%s \n",src_path,dest_path);

        stat(src_path,&buf);
        if(S_ISDIR(buf.st_mode))//判断是否是目录
        {
            mkdir(dest_path,0777);
            cp_dir_to_dir(src_path,dest_path);
        }
        else
        {
            printf("%d \n",__LINE__);
            printf("src:%s,dest:%s \n",src_path,dest_path);
            cp_file_to_file(src_path,dest_path);
        }
    }
}

int main(int argc,char **argv)
{
    printf("begin \n");

    int ret;
    //检查输入有效性
    if(argc != 3)
    {
        printf("输入程序名 要复制的目录 复制后的目录\n");
        
        return -1;
    }
    //判断文件是否存在
    if(access(argv[1],F_OK))
    {
        printf("无法获取%s的文件状态（stat）:没有那个文件或目录 \n",argv[1]);
        return -1;
    }
    //获取第一个参数的文件属性
    struct stat buf;
    stat(argv[1],&buf);
    //第一个参数是文件
    if(S_ISREG(buf.st_mode))
    {
        //第二个参数不存在
        if(access(argv[2],F_OK))
        {
            cp_file_to_file(argv[1],argv[2]); //文件到文件复制
        }
        //第二个参数存在
        else
        {
            bzero(&buf,sizeof(buf));
            //获取第二个参数的文件属性
            stat(argv[2],&buf);
            //第二个是文件
            if(S_ISREG(buf.st_mode))
            {
               cp_file_to_file(argv[1],argv[2]); //文件到文件复制
            }
            //第二个是目录
            else if(S_ISDIR(buf.st_mode))
            {
                //文件到目录复制
                cp_file_to_dir(argv[1],argv[2]);
            }    
        }
    }    
    //第一个参数是目录
    else if(S_ISDIR(buf.st_mode))
    {
        cp_dir_to_dir(argv[1],argv[2]);
    }
    return 0;
}