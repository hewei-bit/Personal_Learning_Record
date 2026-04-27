#include "account.h"



double pay(struct one_kernel_list *head,struct one_kernel_list *head_cart)
{
	    double foodsum = 0;                           
		struct one_kernel_list *tmp_cart;
	    struct list_head *pos_cart;
		list_for_each(pos_cart,&(head_cart->my_list))
		{
			tmp_cart = list_entry(pos_cart,struct one_kernel_list,my_list);//求得购物车大结构体地址
		    struct one_kernel_list *tmp;
			struct list_head *pos;
			
			list_for_each(pos,&(head->my_list))                    //购物车商品与超市商品循环配对
			{
				tmp = list_entry(pos,struct one_kernel_list,my_list);    // //求得商店大结构体地址
			
			    if(!strcmp(tmp_cart->name,tmp->name))   //若配对上，则查看库存,否则继续遍历
				{
					if(tmp_cart->count <= tmp->count)
					{
						tmp->count-=tmp_cart->count;       //减少超市库存
						foodsum = foodsum + tmp_cart->count*tmp_cart->cuprice; //购物车商品计价
					    printf("商品 %s 计价成功 数量 %u 价格 %f\n",tmp_cart->name,tmp_cart->count,foodsum);
					    break;
					}
					else
					{
						printf("超市商品%s库存不足，可能已被其他用户抢购,请检查购物车\n",tmp_cart->name);
						break;        //匹配完商品进行下一次匹配
					}
				}
			}
           //内循环到头，外循环还未结束，表示该商品已被其他人结账
			if(pos == &(head->my_list)) 
			{
				printf("商品 %s 可能已被其他人选购，请检查购物车\n",tmp_cart->name); 	 
			}   			
		}
	
	return foodsum;
}

void user_compare(struct one_kernel_list *head_old,struct one_kernel_list *head_new)
{                         
		struct one_kernel_list *tmp_new;          //old为用户快照，new为当前超市商品       
	    struct list_head *pos_new;
		list_for_each(pos_new,&(head_new->my_list))
		{
			tmp_new = list_entry(pos_new,struct one_kernel_list,my_list);//求得当前超市商品的大结构体地址
		    struct one_kernel_list *tmp_old;
			struct list_head *pos_old;
			
			list_for_each(pos_old,&(head_old->my_list))                    
			{                                                      
				tmp_old = list_entry(pos_old,struct one_kernel_list,my_list);    //内循环，快照大结构体地址
			
			    if(!strcmp(tmp_new->name,tmp_old->name))   //若配对上表示商品没有下架查看库存和折扣
				{
					if(!(tmp_old->count == tmp_new->count))  //查看库存
					{	
						tmp_old->count = tmp_new->count;
			           	printf("请注意 已修改商品:%s 库存为:%u\n",tmp_new->name,tmp_new->count);											 
					    break;
					}
					if(!(tmp_old->discount == tmp_new->discount))       // 折扣
					{   
					    tmp_old->discount = tmp_new->discount;
						printf("请注意 已修改商品:%s 折扣为:%f\n",tmp_new->name,tmp_new->discount);
					    break;
					}
				   break;      //配对上且库存和折扣未变化跳出循环
				} 			
			 }
             // 内循环到头，外循环还未结束，表示该商品为新品
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
				 strcpy(new->type,tmp_new->type);
				 strcpy(new->name,tmp_new->name);
				 
				 new->count=tmp_new->count;
				 new->orprice=tmp_new->orprice;
				 new->cuprice=tmp_new->cuprice;
				 new->discount=tmp_new->discount;
				 list_add(&(new->my_list), &(head_old->my_list));
				
				printf("请注意 新上架商品: %s\n",tmp_new->name); 	 
			}
		}
		 // 外循环到头而内循环未到头，表示除了配对的商品，其它商品均已下架,需要反过来排除原管理员多余的商品
        struct one_kernel_list *tmp_old;
		struct list_head *pos_old,*n;
		list_for_each_safe(pos_old,n,&(head_old->my_list))
		{
			tmp_old = list_entry(pos_old,struct one_kernel_list,my_list);//求得其它管理员的大结构体地址
		    
			 struct one_kernel_list *tmp_new;          //old为用户快照，new为当前超市商品       
	         struct list_head *pos_new;
			list_for_each(pos_new,&(head_new->my_list))                    
			{                                                      
				tmp_new = list_entry(pos_new,struct one_kernel_list,my_list);    // //求得当前管理员大结构体地址
			
			    if(!strcmp(tmp_new->name,tmp_old->name))   //若配对上，
				{
				    break;
				}
			}
		    if(pos_new == &(head_new->my_list))     //若有一节点内层循环遍历完，表示该节点需要删除
			{
				printf("请注意 已下架商品:%s  \n",tmp_old->name);
				struct one_kernel_list *k=del_node(head_old,tmp_old->name);
				
				free(k);
				                       // 删除节点后再遍历出现断错误，safe
				k = NULL;
			}
		}	
}


int guest(struct one_kernel_list *head_staty,struct one_kernel_list *head_food,char *s)
{                                                               //s 为用户标识
	    printf("欢迎进入普通用户模式\n");
	    int ret;
	    
		while(1)
		{
            printf("            |---------------------------|\n");
			printf("            |     欢迎用户              |\n");
			printf("            |      请输入序号选择       |\n");
			printf("            |---------------------------|\n");
			printf("            |   1     进入商品列表      |\n");
			printf("            |   2     修改账户信息      |\n");
			printf("            |   3     退出用户模式      |\n");	
			
			int num;
			while(1)
			{   
				printf("            输入序号： ");
			    ret=scanf("%d",&num);
				if (ret != 1)
				{
					while (getchar() != '\n');
					continue;
				}
                else
					break;
			}	
			while(getchar()!='\n');
			
		if(num == 3)
					break;
		else if(num == 2)
				{
					FILE *fp;
				    char temp[SIZE];
				    int flag;
					admins d,c;
					
                    strcpy(d.id,s);   //复制原来的账号
					
		 FILE *fguest = fopen("../TXT/users.txt","r");
		 if(fguest == NULL)
			{
				printf("文件打开失败~\n");
				return 0;
			}
         
         fread(&c, sizeof(struct The_users), 1, fguest); //读入一个结构体字符块 到c
         while(1)
		 {	 
		   printf("请输入5位电话号码\n");
           for(int i = 0;i<=4;i++)
									{
										scanf("%c",&d.phone[i]);
										if (d.phone[i] == '\n')
										{
											i = -1;
										  printf("输入格式有误，请重新输入\n");
										}
										
									}
         if(getchar() == '\n')
			 break;
		 while(getchar() != '\n');
		 }   									
		d.phone[5]='\0';
									
         
         while (1)
         {    
             if (strcmp(d.phone, c.phone)) /*如果两串不相等*/
             {
                 if (!feof(fguest))    /*如果未到文件尾*/                                
                           
                 {
                     fread(&c, sizeof(struct The_users), 1, fguest);
                 }
                 else                              
				 {   fclose(fguest);
				     flag = 1;		 
					 break;              
				 }	 
             }
             else

             {   
                 printf("此电话号码已注册！\n");
				 flag = 0;
                 fclose(fguest);
                 break;      
             }
         }
				if(flag == 1) 
				{
					while(1)
					 {	 
					   printf("请输入5位数密码\n");
					
					   for(int i = 0;i<=4;i++)
												{
													scanf("%c",&d.pwd[i]);
													if (d.pwd[i] == '\n')
													{
													   i = -1;
													   printf("输入格式有误，请重新输入\n");
													}
													
													}  
						  if(getchar() == '\n')
							  break;
						  while(getchar()!='\n');
						 }
						  d.pwd[5]='\0';
						  
						  while(1)
						 {
						   
						   printf("请确认5位数密码\n");
						
						   for(int i = 0;i<=4;i++)
													{
														scanf("%c",&temp[i]);
														if (temp[i] == '\n')
														{
														   i = -1;
														   printf("输入格式有误，请重新输入\n");
														}
														
													}  
						  if(getchar() == '\n')
							  break;
						  while(getchar()!='\n');
					 }
					 temp[5]='\0';
		             fp = fopen("../TXT/users.txt","r+");
					if(fp == NULL)
					{
						printf("文件打开失败~\n");
						return -4;
					}
					 
					 do
					 {
						if(!strcmp(d.pwd,temp))
						{
                           while(1)
						   {   
					         fread(&c,sizeof(struct The_admins),1,fp);									//读入一个到c中
		                     fflush(fp);
								 
							 if(!strcmp(d.id,c.id))                     //若账号相同，则写入fp指向的前一个结构体的位置
							 {    //printf("%d\n",__LINE__);
							     fseek(fp,-sizeof(struct The_admins),SEEK_CUR);
								 fwrite(&d, sizeof(struct The_admins), 1, fp);  //以r+的形式由d写到fp中
							     //printf("%d\n",__LINE__);
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
						   }break;
						 }
					   else
						{
							printf("两次密码不匹配！请重新输入密码！\n");
						 
						    while(1)
							 {	 
							   printf("请输入5位数密码\n");
							
							   for(int i = 0;i<=4;i++)
												{
													scanf("%c",&d.pwd[i]);
													if (d.pwd[i] == '\n')
													{
													   i = -1;
													   printf("输入格式有误，请重新输入\n");
													}
													
												}  
								  if(getchar() == '\n')
									  break;
								  while(getchar()!='\n');
							   }
								   d.pwd[5]='\0';
						  
							  while(1)
							 {
							   
							   printf("请确认5位数密码\n");
						
							   for(int i = 0;i<=4;i++)
													{
														scanf("%c",&temp[i]);
														if (temp[i] == '\n')
														{
														   i = -1;
														   printf("输入格式有误，请重新输入\n");
														}
														
													}  
							   if(getchar() == '\n')
								  break;
							   while(getchar()!='\n');
							  }
							  temp[5]='\0'; 
			            }
		            }while(1);
				}
			}	
			else if(num == 1)
			{
			
		            char staty[15]="staty";		
					char food[15]="food";       //购物车头节点初始化
					struct one_kernel_list *head_food_cart = init_list();
					struct one_kernel_list *head_staty_cart = init_list();									
					
					//加载用户商品列表文件与最新商品比较
					char list[20]="list";
					strcat(list,s);
					struct one_kernel_list *user_food_head = read_list(list,food);
					struct one_kernel_list *user_staty_head = read_list(list,staty);
					user_compare(user_food_head,head_food); 
					user_compare(user_staty_head,head_staty);     //超市商品更新提示
					
					freesome(user_food_head);
					user_food_head = NULL;
					freesome(user_staty_head);
					user_staty_head = NULL;
					
					
					while(1)
					{
						
						printf("输入序号选择 1 查看商品                      \n"); 
						printf("             2 退出商店并保存购物车信息      \n");
						printf("             3 加入购物车                    \n"); 
						printf("             4 移除购物车商品                \n"); 
						printf("             5 查看购物车商品                \n");
						printf("             6 结账                          \n");
												
						int number;
						unsigned int count;  				  //数量
					
					while(1)	
					{	
					    printf("请输入： ");
						ret=scanf("%d",&number);
						if (ret != 1)
						{
							while (getchar() != '\n');
						    continue;
						}
						else
							break;
						
					}	
					while(getchar()!='\n');
					    if(number == 1)
						{	
					        show_food(head_food);
							show_staty(head_staty);
						    printf("可以输入商品名字查找:  ");
							char name[20];
							ret=scanf("%s",name);
							while (ret != 1)
											{
												while (getchar() != '\n');
												printf("请重新输入:  \n");
												ret = scanf("%s",name);
											}
											while(getchar()!='\n');
							
							struct one_kernel_list *tmp1 = find(head_food,name);
							struct one_kernel_list* tmp2 = find(head_staty,name);
							if(tmp1)
							{  
						       printf("食品: \n");
							   printf("商品名字:%8s  库存:%8.2u  原价:%8.2f 元  现价:%8.2f 元  折扣:%8.2f 折\n",tmp1->name,tmp1->count,tmp1->orprice,tmp1->cuprice,tmp1->discount);
							   printf("\n");
							}  
							
							else if(tmp2)
							{   
								printf("文具: \n");
								printf("商品名字:%8s  库存:%8.2u  原价:%8.2f 元  现价:%8.2f 元  折扣:%8.2f 折\n",tmp2->name,tmp2->count,tmp2->orprice,tmp2->cuprice,tmp2->discount);
								printf("\n");
							}	
							else 
							  {
								 printf("不存在该商品\n");
							  }
						  }	
						 else if(number ==2)
						 {
							   //退出商店，保存购物车信息
							    char shop[20]="../TXT/shop";
					            strcat(shop,s);
								FILE *w = fopen(shop,"wb");              //先截断为0，
								if (w == NULL)
								{
									printf("清空%s文件失败\n",shop);
								}
								fclose(w);
								w = NULL;						
								char pwd[20]="shop";
								strcat(pwd,s);
								show_r_add(head_food_cart,pwd);    //然后以r+形式写入覆盖0，每次写后地址都增加 ，所以不会覆盖
								show_a_add(head_staty_cart,pwd);           //以追加的的模式写入,在文件尾写入	
								
							   char list[20]="../TXT/list";
					           strcat(list,s);	
							   w = fopen(list,"wb");              //先截断为0，
							   if (w == NULL)
							   {
								   printf("清空文件%s失败\n",list);
							   }
							   fclose(w);
							   w = NULL;					//保存商品列表快照
							   
							   char shoplist[20]="list";
							   strcat(shoplist,s);
							   show_r_add(head_food,shoplist);    //然后以r+形式写入覆盖0，每次写后地址都增加 ，所以不会覆盖
							   show_a_add(head_staty,shoplist);           //以追加的的模式写入,在文件尾写入
															 
							  freesome(head_staty_cart);   	   // 释放堆内存
							  freesome(head_food_cart);
							  break;
						 }
							
						 else if(number == 3)
						 {   
					            
							 printf("请输入商品名字添加:  ");
							 
							 char name[20];
							 ret=scanf("%s",name);
							 while (ret != 1)
											{
												while (getchar() != '\n');
												printf("请重新输入:  \n");
												ret = scanf("%s",name);
											}
											while(getchar()!='\n');
							 
							  struct one_kernel_list *tmp1 = find(head_food,name);
							  struct one_kernel_list *tmp2 = find(head_staty,name);
							  
							if(tmp1)
							{  
						      int ret;
							  printf("请输入你想要的添加的数量:  ");
							  ret = scanf("%d",&count);
							  while(ret != 1)
							  {
								  while(getchar() != '\n'); 
								  printf("请重新输入 \n");
								  ret = scanf("%d",&count);
							  }
							  while(getchar()!='\n');
							  
							                          
							 struct one_kernel_list *food_cart = find(head_food_cart,name);    //查找购物者中是否有该商品
							  if(food_cart)
							  {
								  unsigned int size = food_cart->count;
								  if( size + count <= tmp1->count)       //若有该节点并且加起来小于库存
							          food_cart->count+=count;
                                  else
								  {
									  printf("超出库存,请重新选择\n");
								      continue;
								  }
							  }
								  
							  else if(count <= tmp1->count && count > 0)          //购物车无此商品
							  {
								 
								  											
									char type[20]="food"; 
								   struct one_kernel_list *new_food_cart = init_node(type,tmp1->name,count,tmp1->orprice,tmp1->cuprice,tmp1->discount);
								   if(new_food_cart == NULL)
									{
										printf("添加食品商品失败~\n");
										return -2;
									}
									
								   list_add(&(new_food_cart->my_list), &(head_food_cart->my_list));
								   printf("添加到购物车成功\n");
							  } 
								  else 
									  printf("由于您输入了错误的数量，请重新选择\n");
							}
							 
							
							else if(tmp2)
							{   
						          int ret;
								  printf("请输入你想要的添加的数量:  ");
								  ret = scanf("%d",&count);
								  while(ret != 1)
								  {
									  while(getchar() != '\n'); 
									  printf("请重新输入 \n");
									  ret = scanf("%d",&count);
								  }
								  while(getchar()!='\n');
							  
							  struct one_kernel_list* staty_cart = find(head_staty_cart,name);    //查找购物者中是否有该商品
							  if(staty_cart)
							  {
								  unsigned int size = staty_cart->count;
								  if( size + count <= tmp2->count)       //若有该节点并且加起来小于库存刷新数量
							          staty_cart->count+=count;
                                  else
								  {
									  printf("超出库存,请重新选择\n");
								      continue;
								  }
							  }
							  else if(count <= tmp2->count && count > 0)
							  {  
							     
								    char type[20]="staty";
									struct one_kernel_list *new_staty_cart  = init_node(type,tmp2->name,count,tmp2->orprice,tmp2->cuprice,tmp2->discount);
									if(new_staty_cart == NULL)
									{
										printf("添加文具商品失败~\n");
										return -2;
									}
						
									list_add(&(new_staty_cart->my_list), &(head_staty_cart->my_list));
									printf("添加到购物车成功\n");
							  }  
							   else
									printf("由于您输入了错误的数量，请重新选择\n");
							}
					
							else 
							  {
								 printf("不存在该商品\n");
							  }
						   }	 
				    else if(number == 4)
				     {
						char name[20];
				        int  type;
				
						printf("请输入要删除的商品的类型：1 食品 2 文具 3 退出删除");
						
						ret=scanf("%d",&type);
						while (ret != 1)
											{
												while (getchar() != '\n');
												printf("请重新输入:  \n");
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
												printf("请重新输入:  \n");
												ret = scanf("%s",name);
											}
											while(getchar()!='\n');
							
							struct one_kernel_list *k=del_node(head_food_cart,name);
							free(k);
							k = NULL;
							break;
						  }
						  
							case 2:
							{
								printf("请输入要删除的文具类商品的名字 ");
								
								ret=scanf("%s",name);
								while (ret != 1)
												{
													while (getchar() != '\n');
													printf("请重新输入:  \n");
													ret = scanf("%s",name);
												}
												while(getchar()!='\n');
								
								struct one_kernel_list *k=del_node(head_staty_cart,name);
								free(k);
								k = NULL;

								break;
							}
							case 3:
								  break;
							default:
							      printf("您选择了错误的类型，已退出\n");
			             }
			        } 
			    else if(number == 5)
				   {
					   printf("\n");
					   printf("\n");
					   printf("------------购物车列表头-----------\n");
					   double food = show_food(head_food_cart);
					   printf("食品现价总价为:%f\n",food);
				       double staty = show_staty(head_staty_cart);
					   printf("文具现价总价为:%f\n",staty);
					   printf(REVERSE"购物车商品总价为: %f \n"NONE,food+staty);
					   printf("------------购物车列表尾-----------\n");
					   printf("\n");
					   printf("\n");
				   }
			   else if(number == 6)								//结账，需要对应减少仓库库存
			   {	
					 char settle[20]="../TXT/settle";
					 strcat(settle,s);
					                                           
					FILE *w = fopen(settle,"w");              //先清空结账文件截断为0，
	                if(w == NULL)
				   {
					   printf("清空结账文件失败\n");
					   return 0;
				   }
					fclose(w);
					w = NULL;
					
					char pwd[20]="settle";
					strcat(pwd,s);
				    show_r_add(head_food_cart,pwd);    //写入结账文件，然后以r+形式写入覆盖0，每次写后地址都增加 ，所以不会覆盖
				    show_a_add(head_staty_cart,pwd);           //以追加的的模式写入,在文件尾写入											// 保存到结账TXT
				   
				   double food = pay(head_food,head_food_cart);      //结账计价，减少最新超市库存
			       double staty = pay(head_staty,head_staty_cart);
				   printf("合计: %f 食品总价: %f 文具总价: %f\n",food+staty,food,staty);
				   
				   char shop[20]="../TXT/shop";
				   strcat(shop,s);
				   w = fopen(shop,"w");    //清空购物车文件，
				   if(w == NULL)
				   {
					   printf("结账时清空购物车文件失败\n");
					   return 0;
				   }
				   fclose(w);
				   w = NULL;
				   //未清空list用户
				   			   
				   char shoplist[20]="list";   //保存用户商品超市
				   strcat(shoplist,s);
				   w = fopen(shoplist,"w");    //清空用户list
				   if(w == NULL)
				   {
					   printf("结账时清空用户list文件失败\n");
					   return 0;
				   }
				   fclose(w);
				   w = NULL;
				   
				   show_r_add(head_food,shoplist);    //然后以r+形式写入覆盖0，每次写后地址都增加 ，所以不会覆盖
				   show_a_add(head_staty,shoplist);           //以追加的的模式写入,在文件尾写入
				   
				   freesome(head_staty_cart);   	   // 释放购物车堆内存
				   freesome(head_food_cart);
				  printf("结账成功，欢迎下次光临\n");
				  break;
			   }
			   else
				printf("请正确输入!\n");
					
		}
	  }
     else 
        printf("请正确输入\n");		 
	}
	return -1;
}