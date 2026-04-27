#include <stdio.h>


int main()
{
    double x,y;
    char z;
    int ret;
    /* 如果要循环多次，考虑输入缓冲区在数据出错的情况下的处理，
    用什么条件结束循环 */
    printf("请输入1+1这样的式子：\n");
    /* 对于scanf函数输入出错的处理 
		1、类型不匹配，只取类型匹配的值，不匹配的就出错
		2、末尾多加了其它的数据，不影响当前数据获取*/
    ret = scanf("%lf%c%lf",&x,&z,&y);
    //针对末尾多输入数据
    if(getchar() != '\n')
    {
        printf("data err \n");
        return -1;
    }
    //正常取得数据
    if(ret == 3)
    {
        switch (z)
        {
        case '+':   /* 用int类型的最大值减去x，得到的数就是y的最大界限，
							如果y超过了这个界限，那么运算就会溢出 */
                            printf("结果是：%lf\n",x+y);     break;
        case '-':     printf("结果是：%lf\n",x-y);    break;
        case '*':     printf("结果是：%lf\n",x*y);    break;
        case '/':      
        if(y == 0)
        {
            printf("除数不能为零\n");
            break;
        }
        printf("结果是：%lf\n",x/y);   break;
        case '%': /*三种方式，
							强制转换，
							浮点数报错（输入必须是字符串，然后检测是整型还是浮点型），
							自己写一个浮点的取余运算
						*/  
                    if(y == 0)
        {
            printf("除数不能为零\n");
            break;
        }
        printf("结果是：%d\n",(int)x%(int)y);      break;
        default :printf("不支持该运算符！ \n");break;
        }
    }
    else{
         printf("data err \n");
         return -2;
    }
}