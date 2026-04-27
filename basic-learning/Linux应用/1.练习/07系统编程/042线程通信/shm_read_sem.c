#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <semaphore.h>



int main(void)
{
	/* 获取键值 */
	key_t key = ftok(".", 2);
	printf("key:%d\n", key);
	
	/* 创建一个共享内存 */
	int shm_id = shmget(key, 1024, IPC_CREAT|0666);
	if(shm_id == -1)
	{
		perror("shmget");
		return -1;
	}
	
	/* 将共享内存映射到进程的虚拟空间中 */
	char *addr = shmat(shm_id, NULL, 0);

	/* 创建一个信号量 */
	sem_t *data = sem_open("/data", O_CREAT, 0666, 0);
	sem_t *space =sem_open("/space", O_CREAT, 0666, 1);
	
	while(1)
	{
		/* 申请数据资源 P操作 */
		sem_wait(data);
		
		if(!strcmp(addr, "quit"))
			break;
		printf("addr:%s\n", addr);
		
		/* 释放空间资源 V操作 */
		sem_post(space);
		
	}
	
	shmdt(addr);

	/* 删除共享内存 */
	shmctl(shm_id, IPC_RMID, NULL);
	sem_close(data);
	sem_close(space);
	
	sem_unlink("/data");
	sem_unlink("/space");
	
	return 0;
}












