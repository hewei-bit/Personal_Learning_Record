#define GPIOEOUT		(*(volatile unsigned int *)0xC001E000)
#define GPIOEOUTENB		(*(volatile unsigned int *)0xC001E004)
#define GPIOEALTFN0		(*(volatile unsigned int *)0xC001E020)


void _start(void)
{
	//配置GPIOE13为GPIO模式
	GPIOEALTFN0&=~(3<<26);		//将GPIOEALTFN0[27:26]清零
	
	
	//配置GPIOE13为输出功能
	GPIOEOUTENB|=1<<13;			//将GPIOEOUTENB[13]置1，将bit13设置为1
	
	//GPIOE13输出低电平
	GPIOEOUT&=~(1<<13);			//将GPIOEOUT[13]清零
	
	while(1);
}