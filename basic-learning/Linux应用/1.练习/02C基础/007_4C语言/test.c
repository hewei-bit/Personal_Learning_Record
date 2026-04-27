#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i = 0;
	
	while(1)
	{
		printf("i:%d", i++);
		sleep(1);
		
		if(i == 10)
			break;
	}
	
	return 0;
}