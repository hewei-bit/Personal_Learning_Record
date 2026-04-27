#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define j2r 1
#define r2j 2


struct msgbuf
{
    long mtype;
    char mtext[10];
};

//线程例程,往消息队列写数据
void *fun(void *arg)
{
    int msg_id = (int)arg;
    struct msgbuf data;
    data.mtype = j2r;
    while(1)
    {
        printf("jack to rose \n");
        scanf("%s",data.mtext);
        //将数据发送到消息队列
        msgsnd(msg_id,&data,10,0);   
    }
}

int main()
{
    //获取键值
    key_t key = ftok(".",1);

    //创建消息队列
    int msg_id = msgget(key,IPC_CREAT|0666);
    if(msg_id == -1)
    { 
        perror("msgget");
        return -1;
    }

    //创建线程
    pthread_t tid;
    pthread_create(&tid,NULL,fun,(void *)msg_id);
    //消息
    struct msgbuf data;

    while(1)
    {
        bzero(&data,sizeof(data));
        //从消息队列读出消息
        msgrcv(msg_id,&data,10,r2j,0);
        printf("rose to jack:%s \n",data.mtext);
        if(strncmp(data.mtext,"quit",4)==0)
        {
            //删除消息队列
            msgctl(msg_id,IPC_RMID,NULL);
            break;
        }
    }
    return 0;
}