#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc,char **argv)
{
    /* 打开一个文件 */
	int fd_a = open("a.txt", O_RDWR);
	if(fd_a == -1)
	{
		printf("open err!\n");
		return -1;
	}
	printf("a.txt fd_a:%d\n", fd_a);
	
	/* 映射文件 */
    char *p = mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,fd_a,0);
    if(p == (void *)-1)
    {
        printf("mmap err!\n");
        return -1;
    }
    printf(" p: %s \n",p);

    lseek(fd_a,-1,SEEK_END);
    write(fd_a,"hewei wqe",9);

    printf("p : %s \n",p);

    //memset(p ,0 ,29);

    munmap(p, 100);
	
	/* 关闭一个文件 */
	int ret = close(fd_a);
	if(ret == -1)
	{
		printf("close err!\n");
		return -1;
	}
	
	
	
	return 0;


}