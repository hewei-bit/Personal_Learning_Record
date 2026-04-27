#ifndef __IO_H
#define __IO_H

#include "main.h"

//保存用户的信息到文件中
void SaveUserToFile(USER head);
//读取文件中用户的信息
void ReadUserFromFile(USER head);

#endif