#include "account.h"

void freesome(struct one_kernel_list *head)
{
	struct one_kernel_list *tmp;
	struct list_head *pos, *n;
	
	list_for_each_safe(pos, n, &(head->my_list))
	{
	    //由小结构体地址求得大结构体地址
		tmp = list_entry(pos, struct one_kernel_list, my_list);
		free(tmp);
		tmp = NULL;
		
	}
	free(head);
	head = NULL;
	return;
}