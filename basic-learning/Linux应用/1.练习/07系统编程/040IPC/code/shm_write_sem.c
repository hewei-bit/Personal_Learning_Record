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

#include <sys/sem.h>

#define SPACE 0
#define DATA  1

union semun
{
    int val;/* 当 cmd 为 SETVAL 时使用 */
    struct semid_ds *buf;/* 当 cmd 为 IPC_STAT 或 IPC_SET 时使用 */
    unsigned short *array; /* 当 cmd 为 GETALL 或 SETALL 时使用 */
    struct seminfo *__buf; /* 当 cmd 为 IPC_INFO 时使用 */
};





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
    bzero(addr, 1024);
	char arr[5] = {"12345"};
    char i = 0 ;

     //创建一个信号量
    int sem_id = semget(key,1,IPC_CREAT|0666);
    if(-1 == sem_id)
    {
        perror("semget");
        return -1;
    }  

    //     //初始化信号量
    // union semun arg;
    // arg.val = 1;//代表有空间
    // semctl(sem_id,SPACE,SETVAL,arg);
    // arg.val = 0;//代表无数据
    // semctl(sem_id,DATA,SETVAL,arg);


    while (1)
    {
        /* 申请空间资源 P操作 */
		struct sembuf op[1];
		op[0].sem_num = SPACE;			//代表操作信号量中的第1个元素
		op[0].sem_op = -1;			//代表进行P操作
		op[0].sem_flg = 0;			//默认
		semop(sem_id, op, 1);
		
		
		*addr = arr[i++];

        if(i == 4)
            i=0;
            sleep(1);
        
        
		
		/* 释放数据资源 V操作 */
		op[0].sem_num = DATA;		//代表操作信号量中的第2个元素
		op[0].sem_op = 1;			//代表进行V操作
		op[0].sem_flg = 0;			//默认
		semop(sem_id, op, 1);
    }
    //共享内存
    shmdt(addr);

    

    return 0;
}














