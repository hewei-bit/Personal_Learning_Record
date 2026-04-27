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

    //组织消息
    struct msgbuf data= {3,"abcde"};
    // data.mtype = 2
    // strcpy(data.mtext,"abcde");

    //将数据发送到消息队列
    msgsnd(msg_id,&data,5,0);

    printf("write_pid:%d \n",getpid());

    return 0;
}