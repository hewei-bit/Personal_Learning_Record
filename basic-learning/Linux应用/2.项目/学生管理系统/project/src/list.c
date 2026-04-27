#include  "main.h"


//声明链表的头和尾
extern STUNODE* g_pHead;//全局变量链表头
extern STUNODE* g_pEnd;

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
