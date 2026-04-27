#include <stdio.h>

int main()
{
    printf("请输入一个字母:");
    char letter;
    scanf("%c",&letter);
    // fflush();
    if(65<= letter && letter<=90)
    {
        int i,j,k;
        for(i =65;i<letter;i++)
        {
            for(j = letter-i;j>0;j--)
            {
                printf(" ");
            }
            for(k = 65;k<=i;k++)
            {
                printf("%c",k);
            }
            for(k = i-1;k>=65;k--)
            {
                printf("%c",k);
            }
            printf("\n");
        }
    }
    else
    {
        printf("error! \n");
    }

   return 0;
}
