#include <stdio.h>

#define PI 3.14
#define  max(a,b) \
( {\
    int _a = a;\
    int _b = b;\
        ((_a)>(_b)?(_a):(_b));\
 })

int main()
{
    printf("line :%d \n",__LINE__);
    printf("%s \n",__FUNCTION__);
    printf("%s \n",__FILE__);
    printf("%s \n",__DATE__);
    printf("%s \n",__TIME__);

    float a = PI;
    printf("a:%f \n",a);
    int b = 30,d = 40;
    printf("max:%d \n",max(b|1,++d));

#ifdef PI
    printf("line :%d \n",__LINE__);
#else
    printf("line :%d \n",__LINE__);
#endif

#ifndef PI
    printf("line :%d \n",__LINE__);
#else
    printf("line :%d \n",__LINE__);
#endif

#if 0
	printf("%d\n", __LINE__);
#else
	printf("line: %d\n", __LINE__);
#endif
    return 0;

}



