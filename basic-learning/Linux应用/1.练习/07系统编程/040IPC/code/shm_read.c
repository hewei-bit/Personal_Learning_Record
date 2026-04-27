#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <time.h>


int main(int argc,char**argv)
{
    //获取键值
    key_t key = ftok(".",2);
    printf("key:%d \n",key);
   
    //创建共享内存
    int shm_id = shmget(key,1024,IPC_CREAT|0666);
    if(-1 == shm_id)
    {
        perror("shmget");
        return -1;
    }

    //映射共享内存
    char *addr =  shmat(shm_id,NULL,0);


    //读取共享内存消息
    while (1)
    {
        printf("addr:%s\n", addr);
		sleep(1);
		if(*addr == 10)
			break;
    }

    //获取内存属性
    struct shmid_ds info;
    shmctl(shm_id,IPC_STAT,&info);
    printf("%s \n",ctime(&info.shm_ctime));
    
    //解除映射
    shmdt(addr);

    //删除共享内存
    shmctl(shm_id,IPC_RMID,NULL);

    return 0;
}














