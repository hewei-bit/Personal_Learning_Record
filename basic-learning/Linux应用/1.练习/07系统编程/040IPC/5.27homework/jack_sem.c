//文件IO
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <dirent.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <pwd.h>
#include <grp.h>
#include <linux/input.h>

//进程
#include <sys/wait.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SIZE 1024
#define DATA 0
#define SPACE 1

char *p = NULL;
int shmid = -1;
int semid = -1;

union semun 
{
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
};

//初始化资源
void seminit(int semid, int semnum, int val)
{
	union semun a;
	a.val = val;
	semctl(semid, semnum, SETVAL, a);
}

//P操作
void sem_p(int semid, int semnum)
{
	struct sembuf a[1];
	a[0].sem_num = semnum;
	a[0].sem_op = -1;
	a[0].sem_flg = 0;
	semop(semid, a, 1);
}

//V操作
void sem_v(int semid, int semnum)
{
	struct sembuf a[1];
	a[0].sem_num = semnum;
	a[0].sem_op = 1;
	a[0].sem_flg = 0;
	semop(semid, a, 1);
}


int main(int argc, char **argv)
{
	//1.获取共享内存ID
	shmid = shmget(ftok(".", 1), SIZE, IPC_CREAT|0666);
	if(-1 == shmid)
	{
		perror("shmget() failed:");
		exit(1);
	}
	
	//2.映射共享内存
	p = shmat(shmid, NULL, 0);
	if(NULL == p)
	{
		perror("shmat() failed:");
		exit(1);
	}
	
	//3.获取信号量ID
	semid = semget(ftok(".", 2), 2, IPC_CREAT|IPC_EXCL|0666);
	if(semid > 0)
	{
		seminit(semid, DATA, 0);//设置数据资源的初始值为0
		seminit(semid, SPACE, 1);//设置空间资源的初始值为1
	}
	else
	{
		semid = semget(ftok(".", 2), 2, 0666);
	}
	
	while(1)
	{
		sem_p(semid, SPACE);
		if(strlen(p) != 0)
			printf("from rose: %s\n", p);
		

		printf("jack:");
		fgets(p, SIZE, stdin);
		if(strncmp(p,"exit",4)==0)
            break;
		sem_v(semid, DATA);
	}
	
	
	
	return 0;
}









