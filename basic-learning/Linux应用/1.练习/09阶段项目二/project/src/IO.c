#include "IO.h"
#include "user.h"

//声明链表的头和尾
// extern STUNODE* g_pHead;//全局变量链表头
// extern STUNODE* g_pEnd;

//保存学生的信息到文件中
void SaveUserToFile(USER head)
{
    //判断链表是否为空
    FILE *pFlie = NULL;

	struct list_head *q;
    char name_buf[20] = {0};
    char passwd_buf[20] = {0};
	char strbuf[40] = {0};

    if(NULL == head)
    {
        printf("没有学生信息\n");
        return;
    }

    //打开文件
    pFlie = fopen("image/user.txt","wb+");
    if (NULL == pFlie)
    {
        printf("文件打开失败\n");
        return;
    }

    //操作文件指针
    list_for_each(q, &(head->list))
	{
		USER tmp;
		tmp = list_entry(q,User,list);
        //用户名复制
        strcpy(strbuf,tmp->username);
        strcat(strbuf,".");
        //密码复制
        strcat(strbuf,tmp->password);
		strcat(strbuf,".");
        fwrite(strbuf, 1, strlen(strbuf), pFlie );
        fwrite("\r\n",1,strlen("\r\n"),pFlie);
	}
    

    //关闭文件
    fclose(pFlie);
}

//读取文件中学生的信息
void ReadUserFromFile(USER head)
{
	// printf("%d",__LINE__);

    FILE* pFile = fopen("image/user.txt", "rb+"); //
	if (NULL == pFile)
	{
		printf("文件打开失败\n");
		return ;
	}
	// printf("%d",__LINE__);
	char strBuf[40] = {0};
	char name_buf[20] = {0};
    char passwd_buf[20] = {0};


	int nCount = 0;
	int j = 0;
    int n = 0;
	
	//操作指针，读取函数
	while( NULL !=  fgets(strBuf, 40, pFile))  //EOF  feof   3部分
	{                           
        n = 0;
		int i =0;
		nCount = 0;
		j = 0;
		bzero(name_buf,20);
		bzero(passwd_buf,20);

		for (i = 0; strBuf[i] != '\r'; i++)
		{
			if(0 == nCount) //没到'.'
			{
				name_buf[i] = strBuf[i];
				if ('.' == strBuf[i])
				{
					name_buf[i] = '\0';
					nCount++;
				}
			}
			else if (1 == nCount) //第一个'.'
			{
				passwd_buf[j] = strBuf[i];
				j++;	
				if ('.' == strBuf[i])
				{
					passwd_buf[--j] = '\0';
					nCount++;
					j = 0;
				}		
			}
		}

		//插入到链表
		USER new = new_user_node(name_buf,passwd_buf);
		tail_insert_user(head,new);
	}

	fclose(pFile);
}

