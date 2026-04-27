#include "main.h"


//声明链表的头和尾
STUNODE* g_pHead = NULL;//全局变量链表头
STUNODE* g_pEnd = NULL;


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







