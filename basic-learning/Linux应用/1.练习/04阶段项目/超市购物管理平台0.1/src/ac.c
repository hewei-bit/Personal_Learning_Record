


#include "account.h"


struct one_kernel_list *init_node(char *type,char *name,unsigned int count,float orprice,float cuprice,float discount)
{
	struct one_kernel_list *new 
	= (struct one_kernel_list *)malloc(sizeof(struct one_kernel_list));
	
	if(new != NULL)
	{
											
		strcpy(new->name, name);
											
		new->my_list.next = NULL;
		new->my_list.prev = NULL;
		
		strcpy(new->type,type);
		new->count = count;
		new->orprice = orprice;
		new->cuprice = cuprice;
		new->discount = discount;
		
		return new;
	}
	
	return NULL;
}

// struct one_kernel_list_staty *init_node_staty(char *name,unsigned int count,float orprice,float cuprice,float discount)
// {
	// struct one_kernel_list_staty *new 
	// = (struct one_kernel_list_staty *)malloc(sizeof(struct one_kernel_list_staty));
	
	// if(new != NULL)
	// {
		
		// strcpy(new->name, name);
		// new->my_list.next = NULL;
		// new->my_list.prev = NULL;
		
		// new->count = count;
		// new->orprice = orprice;
		// new->cuprice = cuprice;
		// new->discount = discount;
		
		// return new;
	// }
	
	// return NULL;
// }

/* 删除商品 */
struct one_kernel_list *del_node(struct one_kernel_list *head, char *name)
{
	struct one_kernel_list *tmp;
	struct list_head *pos, *n;

	/*#define list_for_each_safe(pos, n, head) \
	 for (pos = (head)->next, n = pos->next; pos != (head); \
	pos = n, n = pos->next)*/
	list_for_each_safe(pos, n, &(head->my_list))
	{
	    //由小结构体地址求得大结构体地址
		tmp = list_entry(pos, struct one_kernel_list, my_list);
		
		if(!strcmp(tmp->name,name))
		{   
			printf("\n");
			printf("商品名字:%8s  库存:%8.2u   原价:%8.2f  现价:%8.2f  折扣:%8.2f\n",tmp->name,tmp->count,tmp->orprice,tmp->cuprice,tmp->discount);
			printf("\n");
			
			list_del(pos);	
			// free(pos);                  //重复使用了free貌似
			printf("删除商品成功~\n");
			printf("\n");
			return tmp;
		}
		
	}
	printf("没找到你要删除的商品\n");
	printf("\n");
	printf("\n");
	return NULL;
}


struct one_kernel_list *find(struct one_kernel_list *head, char *name)
{
	struct one_kernel_list *tmp;
	struct list_head *pos, *n;
	
	list_for_each_safe(pos, n, &(head->my_list))
	{
	    //由小结构体地址求得大结构体地址
		tmp = list_entry(pos, struct one_kernel_list, my_list);
		
		if(!strcmp(tmp->name,name))
		{   
			return tmp;
		}
		
	}
	printf("\n");
	return NULL;
}

// struct one_kernel_list_staty *find_staty(struct one_kernel_list_staty *head, char *name)
// {
	// struct one_kernel_list_staty *tmp;
	// struct list_head *pos, *n;
	
	// list_for_each_safe(pos, n, &(head->my_list))
	// {
	    // 由小结构体地址求得大结构体地址
		// tmp = list_entry(pos, struct one_kernel_list_staty, my_list);
		
		// if(!strcmp(tmp->name,name))
		// {   
			// return tmp;
		// }
		
	// }
	// printf("\n");
	// return NULL;
// }

double show_food(struct one_kernel_list *head)
{
	printf(RED "食品:\n" NONE);
	// printf("[%2u]" RED "RED " L_RED "L_RED\n" NONE, __LINE__);
	double sumfood=0;
	struct one_kernel_list *tmp;
	struct list_head *pos;

	list_for_each(pos, &(head->my_list))
	/*#define list_for_each(pos, head) \
		for (pos = (head)->next; pos != (head); \
		pos = pos->next)*/
	{
		/*#define list_entry(ptr, type, member) \
		((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))*/
		tmp = list_entry(pos, struct one_kernel_list, my_list);
		// FILE *w = fopen("food.txt","a+");
		// if(w == NULL)
		// {
			// printf("存取食品信息失败~\n");
			// return;
		// }
		// fprintf(w,"%s %f %f %f\n",tmp->name,tmp->orprice,tmp->cuprice,tmp->discount);
		// fclose(w);
		printf( L_RED "商品名字:%8s  库存:%8.2u  原价:%8.2f 元  现价:%8.2f 元  折扣:%8.2f 折\n"NONE,tmp->name,tmp->count,tmp->orprice,tmp->cuprice,tmp->discount);
		sumfood = sumfood+tmp->cuprice * tmp->count;
		printf("\n");
		printf("\n");
	}
	return sumfood;
}

double show_staty(struct one_kernel_list *head)
{
	printf(GREEN "文具:\n" NONE);
	double sumstaty=0;
	struct one_kernel_list *tmp;
	struct list_head *pos;

	list_for_each(pos, &(head->my_list))
	/*#define list_for_each(pos, head) \
		for (pos = (head)->next; pos != (head); \
		pos = pos->next)*/
	{
		/*#define list_entry(ptr, type, member) \
		((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))*/
		tmp = list_entry(pos, struct one_kernel_list, my_list);
		// FILE *w = fopen("staty.txt","a+");
		// if(w == NULL)
		// {
			// printf("存取文具信息失败~\n");
			// return 0;
		// }
		// fprintf(w,"%s %f %f %f\n",tmp->name,tmp->orprice,tmp->cuprice,tmp->discount);
		// fclose(w);
		printf( L_GREEN"商品名字:%8s  库存:%8.2u  原价:%8.2f 元  现价:%8.2f 元  折扣:%8.2f 折\n" NONE,tmp->name,tmp->count,tmp->orprice,tmp->cuprice,tmp->discount);
		sumstaty = sumstaty+tmp->cuprice * tmp->count;
		printf("\n");
		printf("\n");
	}
	return sumstaty;
}


void show_r_add(struct one_kernel_list *head,char *s)           //以覆盖的的模式写入
{
    struct one_kernel_list *tmp;
	struct list_head *pos;
	char pwd[15]="../TXT/";        //貌似传入的话路径会丢，要加上
	strcat(pwd,s);
	                                									
	FILE *w = fopen(pwd,"r+"); 
	if(w == NULL)
	{
		printf("打开%s文件失败\n",pwd);
		return;
	}
	list_for_each(pos, &(head->my_list))
	/*#define list_for_each(pos, head) \
		for (pos = (head)->next; pos != (head); \
		pos = pos->next)*/
	{
		/*#define list_entry(ptr, type, member) \
		((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))*/
		tmp = list_entry(pos, struct one_kernel_list, my_list);
		
		if(w == NULL)
		{
			printf("存取食品信息失败~\n");
			return ;
		}
		fprintf(w,"%s %s %u %f %f %f\n",tmp->type,tmp->name,tmp->count,tmp->orprice,tmp->cuprice,tmp->discount);					 //将更新后的链表中的数据更新到TXT中		
	                                         
	}
	fflush(w);
	fclose(w);
}

void show_a_add(struct one_kernel_list *head,char *s)           //以追加的的模式写入,在文件尾写入
{
    struct one_kernel_list *tmp;
	struct list_head *pos;
	char pwd[15]="../TXT/";        //貌似传入的话路径会丢，要加上
	strcat(pwd,s);
                                  
								  
	FILE *w = fopen(pwd,"a"); 
	if(w == NULL)
	{
		printf("打开%s文件失败\n",pwd);
		return;
	}
	list_for_each(pos, &(head->my_list))
	/*#define list_for_each(pos, head) \
		for (pos = (head)->next; pos != (head); \
		pos = pos->next)*/
	{
		/*#define list_entry(ptr, type, member) \
		((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))*/
		tmp = list_entry(pos, struct one_kernel_list, my_list);
		
		if(w == NULL)
		{
			printf("存取食品信息失败~\n");
			return;
		}
		fprintf(w,"%s %s %u %f %f %f\n",tmp->type,tmp->name,tmp->count,tmp->orprice,tmp->cuprice,tmp->discount);					 //将更新后的链表中的数据更新到TXT中		
	    
	}
	fflush(w);
	fclose(w);
}
//函数：打开管理员快照文件加入链表

struct one_kernel_list *read_list(char *s,char *type)
{
	char pwd[15]="../TXT/";        //貌似传入的话路径会丢，要加上
	strcat(pwd,s);
	FILE *fp = fopen(pwd,"r");
	if(fp == NULL)
	{
		printf("打开%s文件失败\n",s);
		return NULL;
	}
	 
	
		struct one_kernel_list *head = init_list();
		if(head == NULL)
		{
			printf("堆异常!\n");
			return NULL;
		}
		while(1)
		{                                                               //printf("%d\n",__LINE__);
			struct one_kernel_list *new = (struct one_kernel_list *)malloc(sizeof(struct one_kernel_list));
			if(new == NULL)
				{
					printf("新节点建立失败\n");
					return NULL;
				}
			new->my_list.next = NULL;
		    new->my_list.prev = NULL;
			
			if(fscanf(fp,"%s %s %u %f %f %f",new->type,new->name,&new->count,&(new->orprice),&(new->cuprice),&(new->discount)) == EOF)
			{  fflush(fp);
		       if(!(strcmp(new->type,type)))              //读到最后一个类型相同才插入，否则释放new
			   {
				                                                             //printf("%d\n",__LINE__);
				   list_add(&(new->my_list), &(head->my_list)); 
				   break;
			   }
				else
				{                                                             //printf("%d\n",__LINE__);
					free(new);
					new = NULL;
					break;
				}
			}
			else if(!(strcmp(new->type,type)))         //未读到最后一个，类型相同插入，否则释放new
			{                                                                 //printf("%d\n",__LINE__);
				list_add(&(new->my_list), &(head->my_list)); 
				continue;
			}
			else
			{
				free(new);
				new = NULL;
				continue;
			}	
			       
		}	
		    fflush(fp);
			fclose(fp);
		                                                                       //printf("%d\n",__LINE__);
	
	return head;     //返回链表头节点
}		

//函数：管理员各存储文件比较
void compare_admin(struct one_kernel_list *head_old,struct one_kernel_list *head_new,char *id)  //old为当前管理员，new为其它管理员头节点
{                         																		//id为其它管理员id
		struct one_kernel_list *tmp_new;
	    struct list_head *pos_new;
		list_for_each(pos_new,&(head_new->my_list))
		{
			tmp_new = list_entry(pos_new,struct one_kernel_list,my_list);//求得其它管理员的大结构体地址
		    
			struct one_kernel_list *tmp_old;
			struct list_head *pos_old;
			
			list_for_each(pos_old,&(head_old->my_list))                    
			{                                                      
				tmp_old = list_entry(pos_old,struct one_kernel_list,my_list);    // //求得当前管理员大结构体地址
			
			    if(!strcmp(tmp_new->name,tmp_old->name))   //若配对上，则查看库存和折扣,
				{
					if(!(tmp_old->count == tmp_new->count))  //查看库存
					{	                                        //printf("tmp_old->count:%u  tmp_new->count:%u\n",tmp_old->count,tmp_new->count);     
						tmp_old->count = tmp_new->count;
			           	printf("请注意 管理员%s已修改商品:%s 库存为:%u\n",id,tmp_new->name,tmp_new->count);											 
					    break;
					}
					if(!(tmp_old->discount == tmp_new->discount))       // 折扣
					{
						tmp_old->discount = tmp_new->discount;
						printf("请注意 管理员%s已修改商品:%s 折扣为:%f\n",id,tmp_new->name,tmp_new->discount);
					    break;
					}
				   break;      //配对上且库存和折扣未变化跳出循环
				} 			
			 }
             //内循环到头，外循环还未结束，表示该商品为新品
			if(pos_old == &(head_old->my_list)) 
			{
				 struct one_kernel_list *new = (struct one_kernel_list *)malloc(sizeof(struct one_kernel_list));
				 if(new == NULL)
				{
					printf("新节点建立失败\n");
					return ;
				}
				 new->my_list.next = NULL;
				 new->my_list.prev = NULL;
				 // strcpy(new->type,tmp_new->type);
				 strcpy(new->name,tmp_new->name);
				 
				 new->count=tmp_new->count;
				 new->orprice=tmp_new->orprice;
				 new->cuprice=tmp_new->cuprice;
				 new->discount=tmp_new->discount;
				 list_add(&(new->my_list), &(head_old->my_list));
                 printf("管理员%s 新上架商品 %8s 库存 %8u 原价 %8.2f 现价 %8.2f 折扣 %8.2f\n",id,tmp_new->name,tmp_new->count,tmp_new->orprice,tmp_new->cuprice,tmp_new->discount);				 
			}
		 }
		 //外循环到头而内循环未到头，表示除了配对的商品，其它商品均已下架,需要反过来排除原管理员多余的商品
        struct one_kernel_list *tmp_old;
		struct list_head *pos_old,*n;
		list_for_each_safe(pos_old,n,&(head_old->my_list))
		{
			tmp_old = list_entry(pos_old,struct one_kernel_list,my_list);//求得其它管理员的大结构体地址
		    struct one_kernel_list *tmp_new;
	        struct list_head *pos_new;
			
			list_for_each(pos_new,&(head_new->my_list))                    
			{                                                      
				tmp_new = list_entry(pos_new,struct one_kernel_list,my_list);    // //求得当前管理员大结构体地址
			
			    if(!strcmp(tmp_new->name,tmp_old->name))   //若配对上，则跳出
				{
				    break;
				}
			}
		    if(pos_new == &(head_new->my_list))     //若有一节点内层循环遍历完外循环没有遍历完，表示该节点需要删除
			{
				printf("请注意 管理员%s 已下架商品:%s  \n",id,tmp_old->name);
				struct one_kernel_list *k=del_node(head_old,tmp_old->name);
				
				free(k);
				                       //删除节点后再遍历出现断错误，safe
				k = NULL;
			}
		}	
}

//结账文件与管理员账户比较  现在管理员账户是他上一次退出时商品的列表,比较完其他管理员的商品列表后
//用户结账是直接从最新的商品列表里扣的，那么管理员登录时他保存的是上一次的商品列表，管理员比完还要与最新的商品列表比，从而知道上一个用户是否结账是否被其他管理员计入
void compare_list(struct one_kernel_list *head_old,struct one_kernel_list *head_new)
{                         
		struct one_kernel_list *tmp_new;
	    struct list_head *pos_new;
		list_for_each(pos_new,&(head_new->my_list))
		{
			tmp_new = list_entry(pos_new,struct one_kernel_list,my_list);//new为最新商品列表
		    
			struct one_kernel_list *tmp_old;         //超市空——管理员登录，增加商品，退出，保存当前超市商品列表-—(用户登录,选购商品结账,最新超市商品变动)
			                                         //————其它管理员登录管理员id文件为空,对比其它adminid，提示其它管理员的操作,和最新商品LIST对比，提示用户操作
			struct list_head *pos_old;			                                                                 //用户操作导致商品库存减少唯一情况
			
			list_for_each(pos_old,&(head_old->my_list))                      //当前管理员最新列表-最新商品列表=最近一个用户结账对超市的操作
			{                                                      
				tmp_old = list_entry(pos_old,struct one_kernel_list,my_list);    // //old为当前管理员list最新商品列表
			
			    if(!strcmp(tmp_new->name,tmp_old->name))   //若配对上，则查看库存和折扣,
				{
					if(!(tmp_old->count == tmp_new->count))  //查看库存
					{	                                             						
			           	printf("有用户已购买商品 %s 库存已减少为:%u\n",tmp_new->name,tmp_new->count);											 
					    break;
					}
					
				   break;      //配对上且库存和折扣未变化跳出循环
				} 			
			 }
		}  
}

int ac(struct one_kernel_list *head_staty,struct one_kernel_list *head_food,char *s) //s为管理员登录标识符
 {                                          
		printf("欢迎进入管理员模式\n");	
        printf("更新信息中..........\n");
		admins b;	
		char food[15]="food";
		char staty[15]="staty";
		  
          	// char pwd[20]="../TXT/";
	        // strcat(pwd,s);	  
	      struct one_kernel_list *head_admin_food = read_list(s,food);   //调用read_list函数,从管理员文本中读取信息
          if(head_admin_food == NULL)                                    //其实可以和商品列表对比即可，但是这样就不知道哪个管理员操作
			{
				printf("头节点建立失败\n");
			    return 0;
			}
		  struct one_kernel_list *head_admin_staty = read_list(s,staty);
			if(head_admin_staty == NULL)
			{
				printf("头节点建立失败\n");
			    return 0;
			}
			FILE *fp = fopen("../TXT/admins.txt","r");  //获取其它管理员id
			    if(fp == NULL)
				{
					printf("打开文件admins.txt失败\n");
				}
			
		while(1)
		{			
			fread(&b, sizeof(struct The_admins), 1, fp); //与其他管理员账户统计消息 b.id 管理员账号
		   
		   if(!strcmp(b.id,s))          //若是自己的账号判断
		   {
			   if(feof(fp))
				   break;
			   else
				   continue;				//若是末尾跳出循环，不是末尾下一次循环
		   }	   
			struct one_kernel_list *head_compare_food = read_list(b.id,food);
			
			if(head_compare_food == NULL)
			{
				printf("头节点建立失败\n");
			    return 0;
			}
			compare_admin(head_admin_food,head_compare_food,b.id);
			free(head_compare_food);
			//比较文具
			// char pwdstaty[20]="../TXT/";
		    // strcat(pwdstaty,b.id);
			struct one_kernel_list *head_compare_staty = read_list(b.id,staty);
			if(head_compare_staty == NULL)
			{
				printf("头节点建立失败\n");
				return 0;
			}
			compare_admin(head_admin_staty,head_compare_staty,b.id);
			freesome(head_compare_staty);                 //比较完释放
			
			if (!feof(fp))            //
				continue;
			else                       //若不相同且到了文件末尾,feof文件到达末尾返回真
				break;

		}
         fclose(fp);
         fp = NULL;
		 //比较最新商品列表，提示库存变化
		 compare_list(head_admin_food,head_food);
		 compare_list(head_admin_staty,head_staty);
		
		 //释放管理员链表
				freesome(head_admin_staty);
				freesome(head_admin_food);
		 
			
		int ret;
	    char name[10];
		float orprice;
		float cuprice;
		float discount;	
		
		while(1)
		{
            printf("            |---------------------------|\n");
			printf("            |     欢迎管理员            |\n");
			printf("            |      请输入序号选择       |\n");
			printf("            |---------------------------|\n");
			printf("            |   1     添加商品          |\n");
			printf("            |   2     下架商品          |\n");
			printf("            |   3     查看商品          |\n");
			printf("            |   4     修改商品折扣      |\n");
			printf("            |   5     修改账户信息      |\n");
			printf("            |   6     退出管理员模式    |\n");	
			
			int num;
			while(1)
			{ 
				printf("            输入序号：");
				ret=scanf("%d",&num);											//增加提示
				if (ret != 1)
				{
					while (getchar() != '\n');
					continue;
				}
				else
					break;	
			}
			while(getchar()!='\n');

			if(num == 1)
			{       
		            unsigned int count;
					printf("\n");
					printf("请输入要添加的商品类型：1 食品 2 文具 3 日用品 ");
					
					int type;
					
					ret=scanf("%d",&type);
					while (ret != 1)
				    {
					  while (getchar() != '\n');
					  printf("请重新输入\n");
					 ret = scanf("%d",&type);
				    }
					while(getchar()!='\n');
					
						switch(type)
						{
							case 1:
							{
								
								printf("请输入食品类商品名字  ");
								
								ret=scanf("%s",name);
								while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请输入食品类商品名字  ");
										ret = scanf("%s",name);
									}
								while(getchar()!='\n');
							
							char type[10] ="food"; 
                             printf("请输入要添加的数量\n");
							 ret = scanf("%d",&count);
								while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入  ");
										ret = scanf("%d",&count);
									}
								while(getchar()!='\n');
							 
						   struct one_kernel_list *tmp1 = find(head_food,name);
						   if(tmp1)                             //若有该商品，数量加，
						   {
							   tmp1->count+=count;
							   // show_food_save(head);									//刷新库存
						   }  
						   else                              //否则新建链表节点count
							  {
								 
								printf("请输入食品类商品价格  ");
								
								ret=scanf("%f",&orprice);
								while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入\n");
										ret = scanf("%f",&orprice);
									}
									while(getchar()!='\n');

								cuprice = orprice;
								discount = cuprice/orprice*10;
								struct one_kernel_list *new_food = init_node(type,name,count,orprice,cuprice,discount);
										
								if(new_food == NULL)
								{
									printf("添加食品商品失败~\n");
									return -2;
								}
								list_add(&(new_food->my_list), &(head_food->my_list));
								
							  }	
				    
							}	
							break;
							
							case 2:
							{
								
								printf("请输入文具类商品名字  ");
								
								ret = scanf("%s",name);
								while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请输入文具类商品名字  ");
										ret = scanf("%s",name);
									}
									while(getchar()!='\n');
							    struct one_kernel_list* tmp2 = find(head_staty,name);	
								unsigned int count;
								char type[10]="staty";
                                printf("请输入要添加的数量\n");
							    ret = scanf("%d",&count);
								while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入  ");
										ret = scanf("%d",&count);
									}
								while(getchar()!='\n');
								
								if(tmp2)
	                           { 							
    							tmp2->count+=count;
								// show_staty_save(head_staty);
							   }
							   else
							   {	   
								printf("请输入文具类商品价格  ");
								ret=scanf("%f",&orprice);
								while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入\n");
										ret = scanf("%f",&orprice);
									}
								while(getchar()!='\n');
								cuprice = orprice;
								discount = cuprice/orprice*10;
								struct one_kernel_list *new_staty  = init_node(type,name,count,orprice,cuprice,discount);
											
								if(new_staty == NULL)
								{
									printf("添加文具商品失败~\n");
									return -2;
								}
								list_add(&(new_staty->my_list), &(head_staty->my_list));
							   }
								
							}	
							break;
							case 3:
							{
								printf("暂不提供支持\n");
								break;
							}
							default:
							{
						
								  printf("请重新输入\n");
								  break;
							}	
						}
			}
			else if(num == 2)						//下架商品
			{
				char name[20];
				int  type;
				
				printf("请输入要删除的商品的类型：1 食品 2 文具 3 返回上一级  ");
				
				ret=scanf("%d",&type);
				while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入\n");
										ret = scanf("%d",&type);
									}
									while(getchar()!='\n');
				
				switch(type)
				{   
				   case 1:
				   {
					printf("请输入要删除的食品类商品的名字 ");
					
					ret=scanf("%s",name);
					while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入\n");
										ret = scanf("%s",name);
									}
									while(getchar()!='\n');
					
					struct one_kernel_list *k=del_node(head_food,name);
					if(!k)
						break;
					else
					{ 
				     free(k);
					 k = NULL;
					 // show_food_save(head);
					 break;
					}
				  }
				case 2:
				{
					printf("请输入要删除的文具类商品的名字 ");
					
					ret=scanf("%s",name);
					while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入\n");
										ret = scanf("%s",name);
									}
									while(getchar()!='\n');
					
					struct one_kernel_list *k=del_node(head_staty,name);
					if(!k)
						break;
					else
					{	
					free(k);
					k = NULL;
					
					break;
					}
				}
				case 3:
				      break;
				default:
				      printf("输入错误，请重新选择\n");
			  }
			} 
			else if(num == 3)
			{       
		                double sumfood = show_food(head_food);      //商品列表
						printf("食品现价总价为:%f\n",sumfood);
				        double sumstaty = show_staty(head_staty);	
						printf("文具现价总价为:%f\n",sumstaty);
						printf(REVERSE"合计总价为:%f\n"NONE,sumfood+sumstaty);
						printf("\n");
					while(1)
					{	
                        
						printf("输入序号选择 1 商品名字检索 2 退出商品列表 \n");
						printf("请输入： ");
						int num;
						ret=scanf("%d",&num);
						while (ret != 1)
						{
							while (getchar() != '\n');
							printf("请输入： ");
							ret = scanf("%d",&num);
						}
						while(getchar()!='\n');
						
					    if(num == 1)
						{	
						    printf("输入商品名字  ");
							char name[20];
							
							ret=scanf("%s",name);
							while (ret != 1)
											{
												while (getchar() != '\n');
												printf("请重新输入\n");
												ret = scanf("%s",name);
											}
											while(getchar()!='\n');
							
							struct one_kernel_list *tmp1 = find(head_food,name);
							struct one_kernel_list* tmp2 = find(head_staty,name);
							if(tmp1)
							{  
							    
							    printf("商品名字:%8s  库存:%8.2u  原价:%8.2f 元  现价:%8.2f 元  折扣:%8.2f 折\n",tmp1->name,tmp1->count,tmp1->orprice,tmp1->cuprice,tmp1->discount);
							    printf("现价总价:%f\n",tmp1->count * tmp1->cuprice);
								printf("\n");
							}  
							
							else if(tmp2)
							{
								printf("商品名字:%8s  库存:%8.2u  原价:%8.2f 元  现价:%8.2f 元  折扣:%8.2f 折\n",tmp2->name,tmp2->count,tmp2->orprice,tmp2->cuprice,tmp2->discount);
								printf("现价总价:%f\n",tmp2->count * tmp2->cuprice);
								printf("\n");
							}	
							else 
							  {
								 printf("不存在该商品\n");
							  }
						  }	
						 else if(num ==2)
							 break;
				   } 
			  }	
			
			else if(num == 4)
			{
			  while(1)
			  {
			    printf("请输入你要修改的商品类型1 食品 2 文具  3 返回上一级  ");
				
				int type;
				
				ret=scanf("%d",&type);
				while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入\n");
										ret = scanf("%d",&type);
									}
									while(getchar()!='\n');
				
				if(type == 1)
				{
					char name[20];
					float discount;
					
					printf("请输入要修改的食品类商品名字 ");
					
					ret=scanf("%s",name);
					while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入\n");
										ret = scanf("%s",name);
									}
									while(getchar()!='\n');
					struct one_kernel_list *tmp = find(head_food,name);
                    if(!tmp)
					{
						printf("没找到该商品\n");
						break;
					}						
					
					
				while(1)
				{	printf("请输入要修改的商品折扣 ");				
					ret=scanf("%f",&discount);
					if(discount < 0 || discount >10)
					{
						while(getchar()!='\n');
						continue;
					}
					else if  (ret != 1)
									{
										while (getchar() != '\n');
										continue;
									}
					else 
						break;
					
				}
				while(getchar()!='\n');
				
					tmp->discount = discount;
					tmp->cuprice = discount/10*(tmp->orprice);
					printf("\n");
					printf( YELLOW "修改后 商品名字:%8s  库存%8.2u  原价:%8.2f 元  现价:%8.2f 元  折扣:%8.2f 折\n" NONE,tmp->name,tmp->count,tmp->orprice,tmp->cuprice,tmp->discount);
					printf("现价总价:%f\n",tmp->count * tmp->cuprice);
					printf("\n");
					// show_food_save(head);
					
					break;
				}
				else if(type == 2)
				{
					char name[20];
					float discount;
					
					printf("请输入要修改的文具类商品名字 ");
					
					ret=scanf("%s",name);
					while (ret != 1)
									{
										while (getchar() != '\n');
										printf("请重新输入\n");
										ret = scanf("%s",name);
									}
									while(getchar()!='\n');
					struct one_kernel_list *tmp = find(head_staty,name);				
					if(!tmp)
					{
						printf("没找到该商品\n");
						break;
					}						
					while(1)
				   {
						printf("请输入要修改的商品折扣 ");				
						ret=scanf("%f",&discount);
						if(discount < 0 || discount >10)
						{
							while(getchar()!='\n');
							continue;
						}
						else if (ret != 1)
										{
											while (getchar() != '\n');
											continue;
										}
						else 
							break;
									
					
				    }
				     while(getchar()!='\n');
					
					tmp->discount = discount;
					tmp->cuprice = discount/10*(tmp->orprice);
					printf("\n");
					printf( YELLOW "修改后 商品名字:%8s  库存:%8.2u  商品原价:%8.2f 元  商品现价:%8.2f 元 商品折扣:%8.2f 折\n" NONE,tmp->name,tmp->count,tmp->orprice,tmp->cuprice,tmp->discount);
					printf("现价总价:%f\n",tmp->count * tmp->cuprice);
					printf("\n");
					// show_staty_save(head_staty);
					
					break;
				}
				
				else if(type == 3)
					break;
				else
					printf("不存在该商品类型\n");
			  }	
				
			}
			else if(num == 5)						//修改管理员密码和电话号码
			{
				FILE *fp;
				char tmp[SIZE];
				admins a,b;
				int flag;
		
                strcpy(a.id,s);   //复制原来的账号
				 
			   fp = fopen("../TXT/admins.txt","r"); 
			   while(1)
				 {	    int i;
						printf("请输入新的5位电话号码\n");
						for(i = 0;i<=4;i++)
									{
									  scanf("%c",&a.phone[i]);
									  if(a.phone[i] == '\n')           //a.id[i]都正确的收到了数据退出循环
									  {								//输入1234\n，a.id[4]为换行
										  i = -1;                    //输入123\n，a.id[3]为\n;再输入1234，第五位，a[4]='\n',i=-1 是让他从零开始
										  printf("请重新输入5位账号\n");
									  }
									}					//
		                                                //注意if执行顺序
					if(getchar() == '\n' )  //第6位接收换行符,输入正确
																
					{   
					   break;
					}
					while(getchar() != '\n');					//第6位且不为换行,清空数据并重新输入。                 						
                                     
		       }							
		 
		      a.phone[5]='\0';								//长度为6的字符数组末尾添\0
								
         while (1)
         {    
             if (strcmp(a.phone,b.phone)) /*如果两串不相等*/
             {
                 if (!feof(fp))    /*如果未到文件尾*/                                
                                        
                 {
                     fread(&b, sizeof(struct The_admins), 1, fp);     //fp每次读完后移动一个结构体大小
                 }
                 else
				 {				 
				     fclose(fp);                  
					 flag = 1;
					 break;
				 }
			 }
             else

             {   
                 printf("此电话已被注册或未更改电话号码！\n"); 
                 fclose(fp);
				 flag = 0;
                 break;    
             }
         }
			   if(flag == 1)	 
			   { 	 while(1)
					 {    int i;
						  printf("请输入新的5位密码\n");
						  for(i = 0;i<=4;i++)
												{
													scanf("%c",&a.pwd[i]);
													if (a.pwd[i] == '\n')
													{
													   i = -1;
													   printf("输入格式有误，请重新输入\n");
													  
													}
													
												}
					   if(getchar() == '\n')
						break;
						while(getchar() != '\n');
					 }	
			         a.pwd[5]='\0';
		 
		 
					 while(1)
					 {    int i;
						  printf("请确认5位密码\n");
						  for(i = 0;i<=4;i++)
												{
													scanf("%c",&tmp[i]);
													if (tmp[i] == '\n')
													{
													   i = -1;
													   printf("输入格式有误，请重新输入\n");
													  
													}
													
												}
					   if(getchar() == '\n')
						break;
						while(getchar() != '\n');
					 }	
					 tmp[5]='\0';	
		             fp = fopen("../TXT/admins.txt","r+");
					 if(fp == NULL)
					{
						printf("文件打开失败~\n");
						return -4;
					}
					 
					 do
					 {
						if(!strcmp(a.pwd,tmp))             //两次密码一致为1 可以写入
						{    
						   while(1)
						   {   
					         fread(&b,sizeof(struct The_admins),1,fp);									//读入一个到b中
		                     fflush(fp);
							 							 
							 if(!strcmp(a.id,b.id))                     //若账号相同，则写入fp指向的前一个结构体的位置
							  {    
							     fseek(fp,sizeof(struct The_admins),SEEK_CUR);
								 fwrite(&a, sizeof(struct The_admins), 1, fp);  //以r+的形式由a写到fp中
							     
								 fflush(fp);
								 printf("账号修改成功！\n");
								 fclose(fp);
								 break;
							 }	 
							 else if(!feof(fp))
								 continue;  //否则再读一次，直到账户所在位置
							 else
							 {
								fclose(fp);
								printf("修改失败\n");
								break;
						     } 
						   }
						   
						   break;
						}  
					   else
						{
							printf("两次密码不匹配！请重新输入密码！\n");
						 
							while(1)
							 {    int i;
								  printf("请输入5位密码\n");
								  for(i = 0;i<=4;i++)
														{
															scanf("%c",&a.pwd[i]);
															if (a.pwd[i] == '\n')
															{
															   i = -1;
															   printf("输入格式有误，请重新输入\n");
															  
															}
															
														}
								   if(getchar() == '\n')
									break;
									while(getchar() != '\n');
							}	
							a.pwd[5]='\0';
		
							while(1)
								  {   int i;
									  printf("请确认5位密码\n");
									  for(i = 0;i<=4;i++)
													{
														scanf("%c",&tmp[i]);
														if (tmp[i] == '\n')
														{
														   i = -1;
														   printf("输入格式有误，请重新输入\n");
														  
														}		
													}
								   if(getchar() == '\n')
									break;
									while(getchar() != '\n');
								 }	
								 tmp[5]='\0';					 
			          }
		            }while(1);
			   }			  
			}
			
			else if(num == 6)
			{    
				char pwd[20]="../TXT/";
				strcat(pwd,s);
				       											//快照写入对应管理员TXT
				FILE *w = fopen(pwd,"w");              //先截断为0，
	            if (w == NULL)
				{
					printf("打开%s文件失败\n",pwd);
				}
			    fclose(w);
				show_r_add(head_food,s);    //然后以r+形式写入覆盖0，每次写后地址都增加 ，所以不会覆盖
				show_a_add(head_staty,s);           //以追加的的模式写入,在文件尾写入
				
				break;
			}			
		}
	return 0;
}