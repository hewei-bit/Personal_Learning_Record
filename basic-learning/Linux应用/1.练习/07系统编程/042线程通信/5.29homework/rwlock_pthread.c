#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char s = 'X';
pthread_rwlock_t rw;

void *routine(void * arg)
{
    sleep(1);
    printf("before read lock \n");
    pthread_rwlock_rdlock(&rw);
    int i = 10;
    while(i>0)
    {
        sleep(1);
        fprintf(stderr,"[%c:%s]\n",s,(char *)arg);
        i--;
    }
    pthread_rwlock_unlock(&rw);
     pthread_exit(0);
}

//加写锁
void *wr_lock(void *arg)
{
    // sleep(3);
    printf("before write lock \n");
    pthread_rwlock_wrlock(&rw);
    s = 'B';
    int i = 4;
    while(i>0)
    {
        
        fprintf(stderr,"[%c:%s]\n",s,(char *)arg);
        i--;
    }
    pthread_rwlock_unlock(&rw);
     pthread_exit(NULL);
}
//加读锁
void *rd_lock(void *arg)
{
    sleep(5);
    printf("before read lock \n");
    pthread_rwlock_rdlock(&rw);
    int i = 4;
    while(i>0)
    {
        fprintf(stderr,"[%c:%s]\n",s,(char *)arg);
        i--;
    }
    pthread_rwlock_unlock(&rw);
     pthread_exit(NULL);
}

int main(int argc,char **argv)
{
    pthread_rwlock_init(&rw,NULL);

    pthread_t t1,t2,t3,t4;
    pthread_create(&t1,NULL,routine,(void *)"1");
    pthread_create(&t2,NULL,wr_lock,(void *)"2");
    pthread_create(&t3,NULL,wr_lock,(void *)"3");
    pthread_create(&t3,NULL,rd_lock,(void *)"4");


    pthread_exit(0);
    return 0;

}