#define GPIOCOUT		(*(volatile unsigned int *)0xC001C000)
#define GPIOCOUTENB		(*(volatile unsigned int *)0xC001C004)
#define GPIOCALTFN0		(*(volatile unsigned int *)0xC001C020)
#define GPIOCALTFN1		(*(volatile unsigned int *)0xC001C024)

#define GPIOEOUT		(*(volatile unsigned int *)0xC001E000)
#define GPIOEOUTENB		(*(volatile unsigned int *)0xC001E004)
#define GPIOEALTFN0		(*(volatile unsigned int *)0xC001E020)

void delay(void);

void _start(void)
{
	//配置GPIOE13为GPIO模式
	GPIOEALTFN0&=~(3<<26);		//将GPIOEALTFN0[27:26]清零
	
	//配置GPIOE13为输出功能
	GPIOEOUTENB|=1<<13;			//将GPIOEOUTENB[13]置1，将bit13设置为1
	
	//GPIOE13输出低电平
	GPIOEOUT&=~(1<<13);			//将GPIOEOUT[13]清零
	
	
	
	//配置GPIOC17为GPIO模式
	GPIOCALTFN1&=~(3<<2);		//将GPIOCALTFN1[3:2]清零
	GPIOCALTFN1|=  1<<2;		//将GPIOCALTFN1[2]置1    01
	
	//配置GPIOC17为输出功能
	GPIOCOUTENB|=1<<17;			//将GPIOCOUTENB[17]置1，将bit17设置为1
	
	//GPIOC17输出低电平
	GPIOCOUT&=~(1<<17);			//将GPIOCOUT[17]清零	
	
	while(1)
	{
		//灯全亮
		GPIOEOUT&=~(1<<13);
		GPIOCOUT&=~(1<<17);
		
		//延时一会
		delay();
		
		//灯全灭
		GPIOEOUT|=(1<<13);
		GPIOCOUT|=(1<<17);
		
		//延时一会
		delay();		
	}
}

void delay(void)
{
	volatile unsigned int i=0x2000000;
	
	while(i--);	
}


