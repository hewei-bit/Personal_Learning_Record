#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//学生节点
typedef struct _STU
{
    char arrStuNum[10];
    char arrStuName[10];
    int iStuScore;
    struct _STU* pNext;
}STUNODE;

//声明链表的头和尾
STUNODE* g_pHead = NULL;//全局变量链表头
STUNODE* g_pEnd = NULL;

//打印
void showData();
//指令界面
void UI();

//添加一个学生的信息(尾插)
void AddStuMSG(char *arrStuNum,char arrStuName[10],int iStuScore);
//链表头部添加一个节点(头插)
void AddStuMSGToLinkHead(char *arrStuNum,char arrStuName[10],int iStuScore);
//清空链表
void FreeLinkData();
//按学号查询
STUNODE* FindStuByNum(char *arrStuNum);
//指定位置插入
void InsertNode(STUNODE* pTemp,char *arrStuNum,char arrStuName[10],int iStuScore);
//删除指定学生的信息(姓名/学号)
void DeleteStuNode(STUNODE* pNode);

//保存学生的信息到文件中
void SaveStuToFile();
//读取文件中学生的信息
void ReadstuFromFile();

//整型转换成字符串
void itoa (int n,char s[]);


int main(void)
{
    int iOrder = -1;//
    int iflag = 1; 
    char arrStuNum[10] = {'0'};
    char arrStuName[10] = {'0'};
    int iStuScore = -1;
    STUNODE* pTemp = NULL;

    UI();
    //读取文件中学生的信息
    ReadstuFromFile();

    while(iflag)
    {
        printf("请输入指令(9、查看指令)：\n");
        scanf("%d",&iOrder);
        switch(iOrder)
        {
            case 1:
                //添加一个学生的信息(尾插)
                printf("输入学号：\n");
                scanf("%s",arrStuNum);
                printf("输入姓名：\n");
                scanf("%s",arrStuName);
                printf("输入成绩：\n");
                scanf("%d",&iStuScore);
                AddStuMSG(arrStuNum, arrStuName, iStuScore);
                break;
            case 11:
                //添加一个学生的信息(头插)
                printf("输入学号：\n");
                scanf("%s",arrStuNum);
                printf("输入姓名：\n");
                scanf("%s",arrStuName);
                printf("输入成绩：\n");
                scanf("%d",&iStuScore);
                AddStuMSGToLinkHead(arrStuNum,arrStuName,iStuScore);
            break;
            case 111://中间添加
                printf("请输入需要查询的学号：\n");
                scanf("%s",arrStuNum);
                pTemp = FindStuByNum(arrStuNum);
                if(NULL != pTemp)
                {
                    //TODO:插入
                    printf("输入学号：\n");
                    scanf("%s",arrStuNum);
                    printf("输入姓名：\n");
                    scanf("%s",arrStuName);
                    printf("输入成绩：\n");
                    scanf("%d",&iStuScore);

                    InsertNode(pTemp,arrStuNum, arrStuName, iStuScore);
                }
                break;
            case 2:
                //查找指定学生的信息(学号)
                //输入一个学号
                printf("输入一个学号：\n");
                scanf("%s",arrStuNum);
               //查找
                pTemp = FindStuByNum(arrStuNum);
                //打印
                if(NULL != pTemp)
                {
                    printf("\t学号：%s,姓名：%s,分数：%d\n",pTemp->arrStuNum,pTemp->arrStuName,pTemp->iStuScore);
                }
                break;
            case 3:
                //修改指定学生的信息
                //输入一个学号
                printf("输入一个学号：\n");
                scanf("%s",arrStuNum);
               //查找
                pTemp = FindStuByNum(arrStuNum);
                //打印
                if(NULL != pTemp)
                {
                    printf("\t学号：%s,姓名：%s,分数：%d\n",pTemp->arrStuNum,pTemp->arrStuName,pTemp->iStuScore);
                    //修改学号
                    printf("请修改学号\n");
                    scanf("%s",arrStuNum);
                    strcpy(pTemp->arrStuNum,arrStuNum);
                    //修改名字
                    printf("请修改名字\n");
                    scanf("%s",arrStuName);
                    strcpy(pTemp->arrStuName,arrStuName);
                    //修改成绩
                    printf("修改成绩:\n");
                    scanf("%d",&iStuScore);
                    pTemp->iStuScore = iStuScore;
                }
                break;
            case 4:
                //保存学生的信息到文件中
                SaveStuToFile();
                break;
            case 5:
                //读取文件中学生的信息
                ReadstuFromFile();
                break;
            case 6:
                //删除指定学生的信息
                //输入一个学号
                printf("输入一个学号：\n");
                scanf("%s",arrStuNum);
               //查找
                pTemp = FindStuByNum(arrStuNum);
                //打印
                if(NULL != pTemp)
                {
                    //调用删除学生函数
                    DeleteStuNode(pTemp);
                }
                break;
            case 7:
                //恢复释放
                FreeLinkData();
                g_pHead = NULL;
                g_pEnd = NULL;
                //回复，添加节点
                ReadstuFromFile();
                break;
            case 8:
                //打印学生信息
                showData();
                break;
            case 9:
                //查看指令
                UI();
                break;
            case 0:
                iflag = 0;
                printf("退出系统\n");
                break;
            default:
                printf("你输入的信息不对\n");
        }
    }
    //保存
    SaveStuToFile();
    
    FreeLinkData();
    
    system("pause");
    return 0;
}




//指令界面
void UI()
{
    printf("\t****************学生信息管理系统******************\n");
    printf("\t***          1、增加一个学生的信息(尾插)       ***\n");
    printf("\t***         11、增加一个学生的信息(头插)       ***\n");
    printf("\t***       111、增加一个学生的信息(指定位置插入)***\n");
    printf("\t***          2、查找指定学生的信息(学号)  ***\n");
    printf("\t***          3、修改指定学生的信息             ***\n");
    printf("\t***          4、保存学生的信息到文件中         ***\n");
    printf("\t***          5、读取文件中学生的信息           ***\n");
    printf("\t***          6、删除指定学生的信息             ***\n");
    printf("\t***          7、恢复删除的学生信息             ***\n");
    printf("\t***          8、显示所有学生的信息             ***\n");
    printf("\t***          9、显示所有指令                   ***\n");
    printf("\t***          0、退出系统                       ***\n");
    printf("\t**************************************************\n");
    return;
}

//显示全部学生信息
void showData()
{
    STUNODE *pTemp = g_pHead;
    while(pTemp != NULL)
    {
        //打印
         printf("\t学号：%s,姓名：%s,学号：%d\n",pTemp->arrStuNum,pTemp->arrStuName,pTemp->iStuScore);
        //向下一个节点
        pTemp = pTemp->pNext;
    }
}


/*
//整型转换成字符串
void itoa (int n,char ss[],int a)
{
    int i,j,k,sign;
    char s[];
    if((sign=n)<0)//记录符号
        n=-n;//使n成为正数
    i=0;
    do{
        s[i++]=n%10+'0';//取下一个数字
    }while ((n/=10)>0);//删除该数字
    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    for(j=i;j>=0;j--)//生成的数字是逆序的，所以要逆序输出
    {
        printf("%c",s[j]);
    }
       
} 

//字符串转换成整型
int atoi (char s[])
{
int i,n,sign;
for(i=0;isspace(s[i]);i++)//跳过空白符;
sign=(s[i]=='-')?-1:1;
if(s[i]=='+'||s[i]==' -')//跳过符号
  i++;
for(n=0;isdigit(s[i]);i++)
       n=10*n+(s[i]-'0');//将数字字符转换成整形数字
return sign *n;
}
*/






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

//增加一个学生信息
void AddStuMSG(char *arrStuNum,char arrStuName[10],int iStuScore)
{
    //检查参数合法性
    if(arrStuNum == NULL || arrStuName == NULL || iStuScore < 0)
    {
        printf("学生信息输入错误\n");
        return ;
    }
    //逻辑
    //创建一个节点
    STUNODE* pTemp = malloc(sizeof(STUNODE));
    //节点成员赋初始值
    strcpy(pTemp->arrStuNum,arrStuNum);
    strcpy(pTemp->arrStuName,arrStuName);
    pTemp->iStuScore = iStuScore;
    pTemp->pNext = NULL;
    
    if(NULL == g_pHead || NULL == g_pEnd)
    {
        g_pHead = pTemp;
        g_pEnd = pTemp;
    }
    else
    {
        g_pEnd->pNext = pTemp;
        g_pEnd = pTemp; 
    }
}

//链表头部添加一个节点
void AddStuMSGToLinkHead(char *arrStuNum,char arrStuName[10],int iStuScore)
{
    //检测合法性
    if(NULL == arrStuName || NULL == arrStuName || iStuScore < 0)
    {
        printf("学生信息输入有误\n");
        return;
    }
    //创建一个节点
    STUNODE *pTemp = malloc(sizeof(STUNODE));
    //节点赋值
    strcpy(pTemp->arrStuName,arrStuName);
    strcpy(pTemp->arrStuNum,arrStuNum);
    pTemp->iStuScore = iStuScore;
    pTemp->pNext = NULL;
    
    if(NULL == g_pHead || NULL == g_pEnd)
    {
        //链表为空
        g_pEnd = pTemp;
        g_pHead = pTemp;
    }
    else
    {
        pTemp->pNext = g_pHead;
        g_pHead = pTemp;
    }
}

//按学号查询
STUNODE* FindStuByNum(char *arrStuNum)
{
    //检测参数的合法性
    if (NULL == arrStuNum)
    {
        printf("学生信息输入有误\n");
        return NULL;
    }
    //判断链表是否为空
    if(NULL == g_pHead || NULL == g_pEnd)
    {
        printf("链表为空\n");
        return NULL;
    }

    STUNODE* pTemp = g_pHead;
    //遍历链表
    while(pTemp != NULL)
    {
        if(0 == strcmp(pTemp->arrStuNum,arrStuNum))
        {
            return pTemp;
        }
        pTemp = pTemp->pNext;
    }
    printf("查无此节点\n");
    return NULL;
}


//指定位置插入
void InsertNode(STUNODE* pTemp,char *arrStuNum,char arrStuName[10],int iStuScore)
{
    //创建节点
    STUNODE *new = malloc(sizeof(STUNODE));
    //成员赋值
    strcpy(new->arrStuNum,arrStuNum);
    strcpy(new->arrStuName,arrStuName);
    new->iStuScore = iStuScore;
    new->pNext = NULL;

    //插入
    if(pTemp == g_pEnd)
    {
        g_pEnd->pNext = new;
        g_pEnd = new;
    }
    else
    {
        new->pNext = pTemp->pNext;
        pTemp->pNext = new;
    }
}

//删除指定学生的信息(姓名/学号)
void DeleteStuNode(STUNODE* pNode)
{
    //只有一个节点
    if(g_pHead == g_pEnd)
    {
        free(g_pHead);
        g_pHead = NULL;
        g_pEnd = NULL;
    }
    //两个节点
    else if(g_pHead->pNext == g_pEnd)
    {
        if(g_pHead == pNode)
        {
            free(g_pHead);
            g_pHead = g_pEnd;
        }
        else
        {
            free(g_pEnd);
            g_pEnd = g_pHead;
            g_pHead->pNext = NULL;//释放节点
        }
    }
    //三个节点
    else // >=3
	{
		STUNODE* pTemp = g_pHead;
		//判断头
		if(g_pHead == pNode)
		{
			//记住头
			pTemp = g_pHead;
			g_pHead = g_pHead->pNext;
			free(pTemp);
			pTemp = NULL;
			return ;  //结束
		}

		while(pTemp)
		{
			if(pTemp->pNext == pNode)
			{
				//删除
				if (pNode == g_pEnd)
				{
					free(pNode);
					pNode = NULL;
					g_pEnd = pTemp;
					g_pEnd->pNext = NULL;
					return ;
				}
				else
				{
					//记住要删除的节点
					STUNODE* p = pTemp->pNext;
					//链接
					pTemp->pNext = pTemp->pNext->pNext;
					//释放节点
					free(p);
					p = NULL;
					return ;
				}
			}

			pTemp = pTemp->pNext;
		}
	}
}

//释放链表
void FreeLinkData()
{
    STUNODE* pTemp = g_pHead;
    while(g_pHead != NULL)
    {
        //记录节点
        pTemp =g_pHead;
        //向后移动了一个
        g_pHead = g_pHead->pNext;
        //删除节点
        free(pTemp);
    }
}
