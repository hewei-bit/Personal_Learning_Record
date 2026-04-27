#ifndef _MYHEAD_H_
#define _MYHEAD_H_

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
#include <semaphore.h>

//线程
#include <pthread.h>
#include "thread_pool.h"

//socket
#include <sys/socket.h>
#include <arpa/inet.h>

#include "list.h"

#endif