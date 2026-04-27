#include "main.h"



//声明链表的头和尾
extern STUNODE* g_pHead;//全局变量链表头
extern STUNODE* g_pEnd;

//保存学生的信息到文件中
void SaveStuToFile()
{
    //判断链表是否为空
    FILE *pFlie = NULL;
    STUNODE *pTemp = g_pHead;
    char strbuf[30] = {0};
    char strScore[10] = {0};

    if(NULL == g_pHead || NULL == g_pEnd)
    {
        printf("没有学生信息\n");
        return;
    }

    //打开文件
    pFlie = fopen("dat.txt","wb+");
    if (NULL == pFlie)
    {
        printf("文件打开失败\n");
        return;
    }

    //操作文件指针
    while(pTemp)
    {
        //学号复制
        strcpy(strbuf,pTemp->arrStuNum);
        strcat(strbuf,".");
        //姓名
        strcat(strbuf,pTemp->arrStuName);
        strcat(strbuf,".");
        //成绩
        //itoa(pTemp->iStuScore,strScore,10);
        sprintf(strScore,"%d",  pTemp->iStuScore);
        strcat(strbuf,strScore);

        fwrite(strbuf, 1, strlen(strbuf), pFlie );
        fwrite("\r\n",1,strlen("\r\n"),pFlie);
        pTemp = pTemp->pNext;
    }

    //关闭文件
    fclose(pFlie);
}

//读取文件中学生的信息
void ReadstuFromFile()
{
    FILE* pFile = fopen("dat.txt", "rb+"); //

	char strBuf[30] = {0};

	char strStuNum[10] = {0};
	char strStuName[10] = {0};
	char strStuScore[10] = {0};

	int nCount = 0;
	int j = 0;
    int n = 0;
	if (NULL == pFile)
	{
		printf("文件打开失败\n");
		return ;
	}

	//操作指针，读取函数
	while( NULL !=  fgets(strBuf, 30, pFile))  //EOF  feof   3部分
	{
        n = 0;
		int i =0;
		nCount = 0;
		j = 0;
		for (i = 0; strBuf[i] != '\r'; i++)
		{
			if(0 == nCount) //没到'.'
			{
				strStuNum[i] = strBuf[i];
				if ('.' == strBuf[i])
				{
					strStuNum[i] = '\0';
					nCount++;
				}
			}
			else if (1 == nCount) //第一个'.'
			{
				strStuName[j] = strBuf[i];
				j++;	
				if ('.' == strBuf[i])
				{
					strStuName[--j] = '\0';
					nCount++;
					j = 0;
				}		
			}
			else  //第二个'.' 2 == nCount
			{
				strStuScore[j] = strBuf[i];
				j++;
			}
		}
        //n = atoi(strStuScore);
        //printf("string = %s integer =%d\n", strStuScore, n);
		//插入到链表
		AddStuMSG(strStuNum, strStuName, atoi(strStuScore));
	}

	fclose(pFile);
}

