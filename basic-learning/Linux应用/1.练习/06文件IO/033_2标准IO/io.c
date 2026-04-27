#include <stdio.h>




int main(int argc,char **argv)
{
    //getchar();

    //putchar('\n');

    FILE *fp;
    // 打开文件
    fp = fopen("a.txt","a+");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
   /* 
    char ch = getc(fp);
    printf("ch:%c \n",ch);

    fputc('a',fp);
    putc('b',fp);
    
    char buf[10] = {"12\n45"};
    fputs(buf,fp);

    char buf[10] = {0};
    fgets(buf,10,fp);
    printf("buf: %s",buf);
    */
    int age = 24;
    char name[10] = {0};
    char arr[30] = {"age:10,name:list"};

    //fprintf(fp,"age: %d,name:%s",age,name);
    //snprintf(arr,30,"age:%d,name:%s",age,name);
    //printf("arr:%s\n",arr);

    //fscanf(fp,"age:%d,name:%s",&age,name);
    sscanf(arr,"age:%d,name:%s",&age,name);
    printf("age:%d,name:%s",age,name);

   /* 
    //读文件
    char buf[10] = {0};
    int ret = fread(buf,1,10,fp);
    printf("ret:%d\n",ret);
    printf("buf: %s \n",buf);
    if(ret < 10)
    {
        //文件到末尾
        if(feof(fp))
        {
            printf("文件已经到末尾\n");
        }
        else
        {
            printf("fread err\n");
            return -1;
        }
    }
    
    //写入数据
    char buf_write[20] = {"123456"};
    ret = fwrite(buf_write,1,6,fp);
    if(ret < 3)
    {
        printf("write err\n");
        return -1;
    }
        
    fflush(fp);

    sleep(8);
*/
    //关闭文件
    int ret = fclose(fp);
    if(EOF == ret)
    {
        perror("fclose");
        return -1;
    } 






    return 0;
}
