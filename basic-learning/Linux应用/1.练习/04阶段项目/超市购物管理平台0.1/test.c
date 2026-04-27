#include <stdio.h>
#include <string.h>
int main()
{
	char name[15]="./TXT/abcde.txt";
	// char txt[10] =".txt";
    // strcat(name,txt);	
	FILE *fp = fopen(name,"ab");
	if ( fp == NULL )
      printf("file not exist!");
	else
		fclose(fp);
	 fp = NULL;
	return 0;
}