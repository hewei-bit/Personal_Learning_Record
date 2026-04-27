#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>


int main(void)
{
	/* 获取键值 */
	key_t key = ftok(".", 2);
	printf("key:%d\n", key);
	
	/* 创建一个共享内存 */
	int shm_id = shmget(key, 1024, IPC_CREAT|0666);
	if(shm_id == -1)
	{
		perror("msgget");
		return -1;
	}
	
	/* 将共享内存映射到进程的虚拟空间中 */
	char *addr = shmat(shm_id, NULL, 0);
	bzero(addr, 1024);
	char arr[5] = {"12345"};
	char i = 0;
	
	/* 创建两个信号量 */
	sem_t *data = sem_open("/data", O_CREAT, 0666, 0);
	sem_t *space =sem_open("/space", O_CREAT, 0666, 1);
	
	while(1)
	{
		/* 申请空间资源 P操作 */
		sem_wait(space);
		
		scanf("%s", addr);
		
		/* 释放数据资源 V操作 */
		sem_post(data);
		
		if(!strcmp(addr, "quit"))
			break;
	}

	shmdt(addr);
	sem_close(data);
	sem_close(space);
	
	return 0;
}














