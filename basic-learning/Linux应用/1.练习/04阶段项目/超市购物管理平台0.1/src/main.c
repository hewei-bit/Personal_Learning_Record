#include "main.h"
#define SIZE 6
#define ECHOFLAGS (ECHO | ECHOE | ECHOK | ECHONL)
struct one_kernel_list *init_list(void)                     //食品
{
	struct one_kernel_list *head=(struct one_kernel_list *)malloc(sizeof(struct one_kernel_list));

	if( head != NULL)
	{
		INIT_LIST_HEAD( & (head->my_list));
		return head;
	}
	
	return NULL;
}


/*管理员注册账号*/ 
void admins_reg()  //按结构体的大小，一次写入或者读入1个结构体大小
     {    
        
		 FILE *fp;
         char tmp[SIZE];
		 // int ret;
		 admins a,b;
		  
		 
         
         printf("欢迎来到管理员注册界面！\n");
		 
    
         fp = fopen("../TXT/admins.txt","r");
		 if(fp == NULL)
			{
				printf("文件打开失败~\n");
				return ;
			}
         
         fread(&b, sizeof(struct The_admins), 1, fp); //读入一个结构体块 到b,txt
       
	     while(1)
		 {	    int i;
		        printf("请输入5位账号\n");
                for(i = 0;i<=4;i++)
									{
									  scanf("%c",&a.id[i]);
									  if(a.id[i] == '\n')           //a.id[i]都正确的收到了数据退出循环
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
		 
		 a.id[5]='\0';								//长度为6的字符数组末尾添\0
								
         while (1)
         {    
             if (strcmp(a.id,b.id)) /*如果两串不相等*/
             {
                 if (!feof(fp))    /*如果未到文件尾*/                                
                     
                     
                 {
                     fread(&b, sizeof(struct The_admins), 1, fp);     //fp每次读完后移动一个结构体大小
                 }
                 else
				 {				 
				     fclose(fp);                   //
					 
					 break;
				 }
			 }
             else

             {   
                 printf("此管理员已存在！请重新注册！\n"); 
                 fclose(fp);
                 return;      
             }
         }
       fp = fopen("../TXT/admins.txt","r"); 
       while(1)
		 {	    int i;
		        printf("请输入5位电话号码\n");
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
				     fclose(fp);                   //
					 
					 break;
				 }
			 }
             else

             {   
                 printf("此电话已注册！\n"); 
                 fclose(fp);
                 return;      
             }
         }
		
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
        
		 do{
         	if(!strcmp(a.pwd,tmp))
			{
         		 
				 
				 // char admin[20]="admin";
				 // strcat(admin,a.id);
				 char pwd[20]="../TXT/";
				 strcat(pwd,a.id);
				
				 // char *p="a.id";
				 FILE *admin = fopen(pwd,"a");       //创建与管理员对应的新文件
				 if(admin == NULL)
				 {
					 printf("创建管理员库存失败\n");					
					 return ;
				 }
				 fclose(admin);
				 
				 fp = fopen("../TXT/admins.txt","ab");
				 if(fp == NULL)
				 {
					 printf("打开管理员账号存储TTX失败\n");
					 fclose(fp);
					 return ;
				 }
		         fwrite(&a, sizeof(struct The_admins), 1, fp);
				 fflush(fp);
		         printf("账号注册成功，请登录！\n"); 
		         
		         fclose(fp);
				 fp = NULL;
				 return;
			 }
			 else
			 {
				printf("两次输入密码不匹配，请重新输入\n");
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

	/*用户注册账号*/ 
void users_reg()  //按结构体的大小，一次写入或者读入1个结构体大小
     {    
                                                      
         char temp[SIZE];								                
		 // int ret;
         users  d,c;		 
         
         printf("欢迎来到注册界面！\n");
    
         FILE *fguest = fopen("../TXT/users.txt","r");
		 if(fguest == NULL)
			{
				printf("文件打开失败~\n");
				return ;
			}
         
         fread(&c, sizeof(struct The_users), 1, fguest); //读入一个结构体字符块 到c
         
		 while(1)
		 {	 
		   printf("请输入5位账号\n");
           for(int i = 0;i<=4;i++)
									{
										scanf("%c",&d.id[i]);
										if (d.id[i] == '\n')
										{
											i = -1;
										  printf("输入格式有误，请重新输入\n");
										}
										
									}
         if(getchar() == '\n')
			 break;
		 while(getchar() != '\n');
		 }   									
		d.id[5]='\0';
									
         
         while (1)
         {    
             if (strcmp(d.id, c.id)) /*如果两串不相等*/
             {
                 if (!feof(fguest))    /*如果未到文件尾*/                                
                     
                     
                 {
                     fread(&c, sizeof(struct The_users), 1, fguest);
                 }
                 else                              //没有相同的id并且到了文件尾,在判断是否有相同的电话号码
				 {   fclose(fguest);
				     		 
					 break;              
				 }	 
             }
             else

             {   
                 printf("此用户已存在！请重新注册！\n"); 
                 fclose(fguest);
                 return;      
             }
         }
         
		 fguest = fopen("../TXT/users.txt","r");
		 if(fguest == NULL)
			{
				printf("文件打开失败~\n");
				return ;
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
				     		 
					 break;              
				 }	 
             }
             else

             {   
                 printf("此电话号码已注册！\n"); 
                 fclose(fguest);
                 return;      
             }
         }
	
		 
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

		 do{
         	if(!strcmp(d.pwd,temp))
			{				 
				     char settle[20]="../TXT/settle";
					 strcat(settle,d.id);
				     FILE *fset = fopen(settle,"a");       	//结账文件				                                                     //创建与用户对应的结账文件
					 if(fset == NULL)
					 {
						 printf("创建结账文件是失败\n");						 
						 return ;
					 }
					 fclose(fset);
					 
					 char shop[20]="../TXT/shop";
					 strcat(shop,d.id);
					 FILE *fshop = fopen(shop,"a");          //创建与用户对应的购物车新文件
					 if(fshop == NULL)
					 {
						 printf("创建购物车文件失败\n");
						 
						 return ;
					 }
					 fclose(fshop);
					 
					 char list[20]="../TXT/list";
					 strcat(list,d.id);
				     FILE *flist = fopen(list,"a") ;  //用户商品列表文件与最新商品比较
                    if(flist == NULL)
					{
						printf("创建用户商品列表文件失败\n");
						return ;
					}
					 fclose(flist); 
				
         		 FILE* fp = fopen("../TXT/users.txt","a");
				 if(fp == NULL)
				 {
					 printf("存入账号信息时错误\n");
					 return ;
				 }
		         fwrite(&d, sizeof(struct The_users), 1, fp);
				 fflush(fp);
				 fclose(fp);
				 fp = fset = flist = fshop = NULL;
				 
				 printf("用户账号注册成功，请登录！\n"); 
					         
				 return;
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

//函数set_disp_mode用于控制是否开启输入回显功能  
//如果option为0，则关闭回显，为1则打开回显  
int set_disp_mode(int fd,int option)  
{  
   int err;  
   struct termios term;  
   if(tcgetattr(fd,&term)==-1){  
     perror("Cannot get the attribution of the terminal");  
     return 1;  
   }  
   if(option)  
        term.c_lflag|=ECHOFLAGS;  
   else  
        term.c_lflag &=~ECHOFLAGS;  
   err=tcsetattr(fd,TCSAFLUSH,&term);  
   if(err == -1 && err==EINTR){  
        perror("Cannot set the attribution of the terminal");  
        return 1;  
   }  
   return 0;  
}  
	 
/*用户登录系统*/ 
void  login_users(struct one_kernel_list *head_staty,struct one_kernel_list *head_food)
{
    users d,c;//定义结构体The_users别名
    FILE *fp;
    printf("欢迎来到登录界面！\n");
         
    fp = fopen("../TXT/users.txt","r");
    
    fread(&c, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 写入c
    
	 while(1)
		 {	 
		   printf("请输入5位账号\n");
           for(int i = 0;i<=4;i++)
									{
										scanf("%c",&d.id[i]);
										if (d.id[i] == '\n')
										{
											i = -1;
										  printf("输入格式有误，请重新输入\n");
										}
										
									}
         if(getchar() == '\n')
			 break;
		 while(getchar() != '\n');
		 }   									
		d.id[5]='\0';
		
             while (1)
           {   
	           if (strcmp(d.id, c.id)==0)         //如果有此用户名
	           {
	               break;       
	           }
	           
	           else 
	           {
	               if (!feof(fp))  //如果文件没有读完                            
	            
	               {
	                   fread(&c, sizeof(struct The_users), 1, fp);
	               }
	               
	               else
	               {
	                   printf("此用户名不存在，请重新输入！\n");
	                   fclose(fp);  
					   return;              
	               }
	           }
       }
	   //首先关闭输出回显，这样输入密码时就不会显示输入的字符信息  
       set_disp_mode(STDIN_FILENO,0);
	   
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
		
   
		if (strcmp(d.pwd, c.pwd)==0)            /*如果密码匹配*/
	           
	       {  
	          fclose(fp);
	          printf("登录成功,欢迎使用!\n");
			  set_disp_mode(STDIN_FILENO,1);	
			                           //用户登录！！！
			  guest(head_staty,head_food,c.id);                         
												//用于提示超市商品信息更改，通过TXT完成
	          return;
	       }
	       else  
	       {    printf("密码不正确!请重新登录\n");
	            set_disp_mode(STDIN_FILENO,1);
	       		return ;        
	       }
       
}
 
//管理员登录
void  login_admins(struct one_kernel_list *head_staty,struct one_kernel_list *head_food)
{
    FILE *fp;
	admins a,b;
    printf("欢迎来到登录界面！\n");
        
    fp = fopen("../TXT/admins.txt","r");
    
    fread(&b, sizeof(struct The_admins), 1, fp); //读入一个结构体字符块 写入b
    while(1)
		 {	    int i;
		        printf("请输入5位账号\n");
                for(i = 0;i<=4;i++)
									{
									  scanf("%c",&a.id[i]);
									  if(a.id[i] == '\n')           //防止中间出现换行
									  {								//输入1234\n，a.id[4]为换行
										  i = -1;                    //输入123\n，a.id[3]为\n，再输入1234，i已经+1
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
		 
		 a.id[5]='\0';								//长度为6的字符数组末尾添\0
             while (1)
           {   
	           if (strcmp(a.id,b.id)==0)         //如果有此用户名
	           {
	               break;       
	           }
	           
	           else 
	           {
	               if (!feof(fp))  //如果文件没有读完                            
	            
	               {
	                   fread(&b, sizeof(struct The_admins), 1, fp);    //每次读取后f_pos会自动加
	               }
	               
	               else
	               {
	                   printf("此用户名不存在,请重新输入！\n");
	                   fclose(fp);  
					   return;              
	               }
	           }
          }
		  
	   set_disp_mode(STDIN_FILENO,0);
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
		   if (strcmp(a.pwd, b.pwd)==0)            /*如果密码匹配*/      
	       {  
	          fclose(fp);
	          printf("登录成功,欢迎使用!");
			  set_disp_mode(STDIN_FILENO,1);		//管理员登录
			  
			  ac(head_staty,head_food,b.id);                                 //管理员需要收集其它管理员变动的信息和用户购物车的信息
	         
	          return;
	       }
	       else  
	       {    printf("密码不正确!请重新登录\n");
	            set_disp_mode(STDIN_FILENO,1);
	       		return ;        
	       }
}

void admins_find()
{
	FILE *fp;
	admins a,b;
    fp = fopen("../TXT/admins.txt","r");  
    fread(&b, sizeof(struct The_admins), 1, fp); //读入一个结构体字符块 写入b
	
                while(1)
				 {	    int i;
						printf("请输入5位电话号码\n");
						for(i = 0;i<=4;i++)
											{
											  scanf("%c",&a.phone[i]);
											  if(a.phone[i] == '\n')           //a.id[i]都正确的收到了数据退出循环
											  {								//输入1234\n，a.id[4]为换行
												  i = -1;                    //输入123\n，a.id[3]为\n;再输入1234，第五位，a[4]='\n',i=-1 是让他从零开始
												  printf("格式不正确，请重新输入5位电话号码\n");
											  }
											}					//
																//注意if执行顺序
					if(getchar() == '\n' )  //第6位接收换行符,输入正确																
					{   
					   break;
					}
					while(getchar() != '\n');					//第6位且不为换行,清空数据并重新输入。                 						
											 
				 }							
		    while (1)
           {   
	           if (!strcmp(a.phone,b.phone))         //如果有此电话号码
	           {
	              printf("你的账号为:%s  你的密码为:%s \n",b.id,b.pwd);
				  return;
	           }
	           
	           else 
	           {
	               if (!feof(fp))  //如果文件没有读完                            	            
	               {
	                   fread(&b, sizeof(struct The_admins), 1, fp);    //每次读取后f_pos会自动加
	               }              
	               else
	               {
	                   printf("找不到匹配信息,请重试！\n");
	                   fclose(fp);  
					   return;              
	               }
	           }
          }
}

void users_find()
{
	FILE *fp;
	users c,d;
	
    fp = fopen("../TXT/users.txt","r");  
    fread(&c, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 写入c
	
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
	           if (!strcmp(d.phone,c.phone))       
	           {
	              printf("你的账号为:%s  你的密码为:%s \n",c.id,c.pwd);
				  return;
	           }
	           
	           else 
	           {
	               if (!feof(fp))  //如果文件没有读完                            
	            
	               {
	                   fread(&c, sizeof(struct The_users), 1, fp);    //每次读取后f_pos会自动加
	               }
	               
	               else
	               {
	                   printf("找不到匹配信息,请重试！\n");
	                   fclose(fp);  
					   return;              
	               }
	           }
          }
}

int main()
{                                   
        char food[10]="food";
		char staty[10]="staty";
        char food_list[20]="../TXT/food";
		char staty_list[20]="../TXT/staty";
		FILE *fp = fopen(food_list,"a");
		if(fp == NULL)
			printf("新建文件失败\n");
		fclose(fp);
										
		fp = fopen (staty_list,"a");
		if(fp == NULL)
			printf("新建文件失败\n");
		fclose(fp);
		struct one_kernel_list *head_food = read_list(food,food);  //读商品
		if(head_food == NULL)
			printf("读文件失败\n");
		struct one_kernel_list *head_staty = read_list(staty,staty);
		if(head_staty == NULL)
			printf("读文件失败\n");
		// show_food(head_food);
		// show_staty(head_staty);
		
		while(1) 						
		{									
			printf("            |---------------------------—---|\n");
			printf("            |       欢迎光临乐购            |\n");
			printf("            |        请输入序号选择         |\n");
			printf("            |-------------------------------|\n");
			printf("            |      1         登录           |\n");
			printf("            |      2         新用户注册     |\n");
			printf("            |      3         找回账号密码   |\n");
			printf("            |      4         退出程序       |\n");  //退出程序商品入库
			
			int n,ret;
			while(1)
			{	printf("            输入序号：");               //增加了提示 确保输入缓冲区的正确
				ret = scanf("%d",&n);
				if (ret != 1)
				{
					while(getchar()!='\n');
					continue;
				}
				else
					break;
			}
			while(getchar()!='\n');
			if(n == 4)										//退出程序，释放堆中的商品信息
			{                                       
				 char food[20]="food";
				 
		         char staty[20]="staty";	
				 
				 FILE *w = fopen("../TXT/food","w");              //先截断为0，
	             fclose(w);
			        //然后以r+形式写入覆盖0，每次写后地址都增加 ，所以不会覆盖
				                                        
				 w = fopen("../TXT/staty","w");              //先截断为0，
	             fclose(w);
				 
				 if(head_staty == NULL)
					 return 0;
				 if(head_food == NULL)
					 return 0;
				 show_r_add(head_staty,staty);
     				 
                 show_r_add(head_food,food);                                        
				 freesome(head_food);                //超市关闭，保存数据释放堆内存
				 freesome(head_staty);
				break;
			}
			else
			switch(n)
			{
				case 1:
				     {  
					   while(1)
					   {	
								int numguest;
			
								printf("请输入：1 管理员登录 2 普通用户登录 3 返回上一级 \n");
							while(1)
							{
								printf("输入序号： ");
								ret = scanf("%d",&numguest);
								if (ret != 1)
								{
									while (getchar() != '\n');
									printf("请重新输入:  \n");
									continue;
								}
								else 
									break;
							}
								while(getchar()!='\n');
								if(numguest == 1)
								{
									login_admins(head_staty,head_food);
								}
								
								else if(numguest == 2)
								{
									login_users(head_staty,head_food);	
						        }
								else if(numguest == 3)
									break;	
					   }	
					 }
					 break;
				case 2:
				{	
						int num;
						
				        printf("请输入：1 管理员注册 2 普通用户注册 3 返回上一级\n");
					while(1)
					{   printf("请输入序号:  ");
                        ret = scanf("%d",&num);
						if (ret != 1)
							{
								while (getchar() != '\n');  
								continue;
							}
						else
							break;
					}
					while (getchar() != '\n');
						if(num == 1)					//管理员注册
						{
							admins_reg();
							
							break;
						}
						else if(num == 2)							//用户注册
						{
							users_reg();
							break;
						}
						else
							break;
				}
				case 3:
				{   
				    printf("1 找回管理员账户 2 找回用户账户 \n");
				    int numfind;
				  while(1)
				  {		
					printf("请输入: ");
					
					ret = scanf("%d",&numfind);
						if (ret != 1)
							{
								while (getchar() != '\n');
								printf("请重新输入:  \n");
								continue;
							}
						 else 
							 break;
				  }	 
							while(getchar()!='\n');
				   if(numfind == 1)					//管理员找回
						{
							admins_find();
							break;
						}
						else if(numfind == 2)							//用户找回
						{
							users_find();
							break;
						}
						else
							break;			
				}
				default:
				{
					printf("请重新输入:  \n");
				}	
			}
		}
		return 0;
}