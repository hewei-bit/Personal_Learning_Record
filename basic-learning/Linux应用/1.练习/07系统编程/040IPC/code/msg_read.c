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
#include <time.h>


struct msgbuf
{
    long mtype;
    char mtext[10];
};

int main(int argc,char **argv)
{
    //获取键值
    key_t key = ftok(".",2);
    printf("key : %d\n",key);

    //创建一个消息队列
    int msg_id = msgget(key,IPC_CREAT|0666);
    if(msg_id == -1)
    {
        perror("msgget");
        return -1;
    }
    //定义消息格式
    struct msgbuf data;

    //从消息队列读数据  
    msgrcv(msg_id,&data,10,2,0);
    printf("data.mtext:%s \n",data.mtext);

    //获取消息队列属性
    struct msqid_ds info;
    msgctl(msg_id,IPC_STAT,&info);
    printf("info.msg_rtime:%s\n", ctime(&info.msg_rtime));
	printf("info.msg_lspid:%d\n", info.msg_lspid);

    //删除消息队列
    msgctl(msg_id,IPC_RMID,NULL);
    return 0;
}