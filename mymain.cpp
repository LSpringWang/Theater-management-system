# include<iostream.h>
# include<string.h>
# include<stdlib.h>
# include<conio.h>
# include<iomanip.h>
# include<fstream.h>
# include"cinema.h"
# include"customer.h"
void w(char *name ,char *add);
int identify_pass(char * f);
int identify_password(char *f);
void vip_mem();              //订票vip
void con_mem();               //订票-------普通用户
void adm();                  //管理员入口
void book();                 //订票
void films();               //影片信息查看
void cinm();                //影院信息查看
void c_worker();
void m_worker1();
void m_worker();
int main()
{   
        cout<<endl<<endl<<endl<<endl<<endl; 
        cout<<"             ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆            "<<endl;
		cout<<"            ☆ ☆                                     ☆           "<<endl;
		cout<<"           ☆   ☆            C++ 课程设计：           ☆          "<<endl;
		cout<<"          ☆     ☆                                     ☆         "<<endl;
		cout<<"         ☆       ☆        电影院信息管理系统           ☆        "<<endl;
		cout<<"        ☆         ☆                                     ☆       "<<endl;
		cout<<"       ☆           ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆     "<<endl;
		cout<<"       ☆           ☆☆☆☆                          ☆☆☆☆     "<<endl;
        cout<<"       ☆           ☆☆☆☆  程序设计人：王立春      ☆☆☆☆     "<<endl;
        cout<<"       ☆           ☆☆☆☆                          ☆☆☆☆     "<<endl;
	    cout<<"       ☆           ☆☆☆☆                          ☆☆☆☆     "<<endl;
	    cout<<"       ☆           ☆☆☆☆   学号：161110112        ☆☆☆☆     "<<endl;
	    cout<<"       ☆           ☆☆☆☆                          ☆☆☆☆     "<<endl;
        cout<<"       ☆           ☆☆☆☆                          ☆☆☆☆     "<<endl;
        cout<<"       ☆           ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆     "<<endl;
		cout<<endl<<endl;
		cout<<"                                按任意键进入系统                   "<<endl;
        getch();
        system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                            欢迎进入影院管理系统                     "<<endl<<endl<<endl;
		cout<<"                如需管理员密码，或其他密码，请到文档的附录里寻找     "<<endl;
		getch();
		int a,i;
	for(i=0;;i++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl;
		cout<<"                                   ************                                "<<endl;
		cout<<"              *********************<请选择菜单>*********************           "<<endl;
		cout<<"              **                *********************              **           "<<endl;
		cout<<"              **               § 1.工作人员窗口    §             **           "<<endl;
		cout<<"              **             §   2.预(退)定影票窗口   §          **           "<<endl;
		cout<<"              **           §     3.影片信息查看窗口     §        **           "<<endl;
		cout<<"              **             §   4.影院信息查看窗口   §          **           "<<endl;
		cout<<"              **               § 0.退出系统窗口    §             **           "<<endl;
		cout<<"              ******************************************************            "<<endl;
		      
		cin>>a;
		switch(a)
		{
		case 1: 
		   adm();                   
			break;
		case 2:
			book();
			break;
		case 3:
			films();
			break;
		case 4:
			cinm();
			break;
		case 0:
			{
			  system("cls");
			  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			  cout<<setw(40)<<"谢谢使用本系统"<<endl<<endl;
			  cout<<setw(40)<<"如有任何建议，请输入(#结束) :";
			  char a;
			  fstream file("advice.txt",ios::app);
			  cin>>a;
			  while(a!='#')
			  {
				  file.put(a);
				  cin>>a;
			  }
			  file.put('\n');
			  file.close();
			  exit(0);
			}

		}
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////影院信息查看
void cinm()
{
	
	cinema a;
	a.file_open();
	cout<<endl<<endl<<endl;
	cout<<"                          按任意键返回上一级"<<endl;
	getch();
}
void adm()
{
	int i,a=0;
	for(i=0;a!=3;)
	{
        system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择***********"<<endl;
		cout<<"                       **    1.管理人员           **"<<endl;
		cout<<"                       **    2.普通工作人员       **"<<endl;
		cout<<"                       **   3.返回上一级菜单      **"<<endl;
		cout<<"                       *****************************"<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
				int a=0,i,b=0;
				for(i=0;;i++)
				{
					a=identify_password("administrator.dat");
					//a=1;
					if(a==1)
					{                      
						m_worker();
						break;
					}
					else
					{
						system("cls");
		                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
						cout<<"             *******************************************************"<<endl;
                        cout<<"             *姓名与密码不符请重新输入,三次输入错误将返回上一级菜单*"<<endl;
						cout<<"             *******************************************************"<<endl;
						b++;
						if(b==3)
						break;
					}
				}
				break;
			}
			
		case 2:
			{
				int a=0,i,b=0;
				for(i=0;;i++)
				{
					a=identify_password("worker.dat");
					if(a==1)
					{                      
						c_worker();
						break;
					}
					else
					{
						system("cls");
		                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
						cout<<"             *******************************************************"<<endl;
                        cout<<"             *姓名与密码不符请重新输入,三次输入错误将返回上一级菜单*"<<endl;
						cout<<"             *******************************************************"<<endl;
						b++;
						if(b==3)
						break;
					}
				}
				break;
			}
		case 3: 
			break;
		}
	}
}
///////////////////////////////////////////////////////////////////////////普通工作人员

void c_worker()
{
	int i,a=0;
	for(i=0;a!=7;)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择***********    "<<endl;
		cout<<"                       **       1.设置自己信息    **    "<<endl;
		cout<<"                       **       2.修改自己信息    **    "<<endl;
		cout<<"                       **       3.设置影片信息    **    "<<endl;
		cout<<"                       **       4.修改影片信息    **    "<<endl;
		cout<<"                       **       5.设置影院信息    **    "<<endl;
		cout<<"                       **       6.查看已订票人员  **    "<<endl;                 
		cout<<"                       **       7.返回上一级菜单  **    "<<endl;
		cout<<"                       *****************************    "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
			worker worker1;
			worker1.set_my_information();                           //设置自己信息
   		    break;
			}
		case 2:
			{
			worker worker1;
			worker1.change_my_information();                          //修改自己信息
			break;
			}
		case 3:
			{
			film film1;
			film1.set_film();                                     //设置影片信息
			break;
			}
		case 4:
			{
				film film2;
				film2.change_film();    
				break;
			}
		case 5:
			{
				worker worker1;
				worker1.set_cinema();                                //设置影院信息
			break;
			}
		case 6:
			{
				customer customer1;
				customer1.look_all();
			break;
			}
		case 7:
			break;
		}

	}

}
////////////////////////////////////////////////////////////管理人员
void m_worker1()
{    
	int a; 
	for(;a!=4;)
	{ 
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择***********    "<<endl;
		cout<<"                       **     1.重新设置自己信息  **    "<<endl;
		cout<<"                       **     2.修改自己信息      **    "<<endl;
		cout<<"                       **     3.显示自己信息      **    "<<endl;
		cout<<"                       **     4.返回上一级菜单    **    "<<endl;
		cout<<"                       *****************************    "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
				{
				administrator administrator1;
				administrator1.set_my_information();                           //设置自己信息
   				break;
				}
		case 2:
				{
				administrator administrator1;
				administrator1.set_my_information();                          //修改自己信息
				break;
				}
		case 3:
				{
					administrator administrator1;
					administrator1.show_admion();
					break;
				}
		case 4:
			break;
			}
	}
}
void m_worker()
{
    int i,a;
	for(i=0;a!=6;i++)
	{   
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择***********    "<<endl;
		cout<<"                       **    1.设置自己信息       **    "<<endl;
		cout<<"                       **    2.添加影片信息       **    "<<endl;
		cout<<"                       **    3.设置影院信息       **    "<<endl;
		cout<<"                       **    4.员工信息设置       **    "<<endl;
		cout<<"                       **    5.增加管理员         **    "<<endl;
		cout<<"                       **    6.返回上一级菜单     **    "<<endl;
	    cout<<"                       *****************************    "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
                m_worker1();
				break;
			}
		
		case 2:
			{
			film film1;
			film1.set_film();                                     //设置影片信息
			break;
			}
		case 3:
			{
			administrator administrator1;
			administrator1.set_cinema();                                //设置影院信息
			break;
			}
		case 4:
			{
				administrator administrator1;
				administrator1.ad_staff();
				break;
			}
		case 5:
			{
				administrator administrator1;
                administrator1.add_administrator();
				break;
			}
		case 6:
			break;
		
		}

	}
}
////////////////////////////////////////////////////////////影片信息查看
void films()
{
	int i,a;
	for(i=0;a!=3;i++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择*************  "<<endl;
		cout<<"                       **    1.按片名查询           **  "<<endl;
		cout<<"                       **    2.影院全部上映影片查询 **  "<<endl;
		cout<<"                       **    3.返回上一级菜单       **  "<<endl;
		cout<<"                       *******************************  "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
				film film1;
				film1.find_film();
				break;
			}
		case 2:
			{
				film film1;
				film1.find_films();
				break;
			}

		case 3:
			break;
		}
	}

}
////////////////////////////////////////////////////////////////////////////////////订票窗口
void book()
{
	int a,i;
	for(i=0;a!=4;i++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择*************     "<<endl;
		cout<<"                       **      1.会员  订票窗口     **     "<<endl;
		cout<<"                       **      2.非会员订票窗口     **     "<<endl;
		cout<<"                       **      3.退票窗口           **     "<<endl;
		cout<<"                       **      4.返回上一级菜单     **     "<<endl;
		cout<<"                       *******************************     "<<endl;
		cin>>a;
		switch(a)
		{
		case 1: 
			vip_mem();
			break;
		case 2:
			con_mem();
			break;
		case 3:
			{
			customer customer1;
			customer1.vip_unbook();
			break;
			}
		case 4:
			break;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////订票有关函数
void vip_mem()
{
     int a=0,i,b=0;
	 for(i=0;;i++)
	 {
		a=identify_pass("vip_customer.dat");
		if(a==1)
		{                      
			customer vip;
			vip.vip_mem();
			break;
		}
		else
		{
			system("cls");
		    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"             *******************************************************"<<endl;
            cout<<"             *姓名与密码不符请重新输入,三次输入错误将返回上一级菜单*"<<endl;
			cout<<"             *******************************************************"<<endl;
			b++;
			if(b==3)
			break;
		}
	}
}
void con_mem()
{
	int i,a;
	for(i=0;a!=3;i++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择*************       "<<endl;
		cout<<"                       **        1.注册会员         **       "<<endl;
		cout<<"                       **        2.直接订票         **       "<<endl;
		cout<<"                       **        3.返回上一级菜单   **       "<<endl;
		cout<<"                       *******************************       "<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
				customer customer1;
				customer1.regist();
				break;
			}
		case 2:
			{
			customer customer1;
            customer1.order();
		    break;
			}
		case 3:
			break;
		}
	}

}


////////////////////////////////////////////////////////////////////////////////////密码验证函数
int identify_password(char * f)
{
	int i,a=0;
    char name[20];
	char password[15];
	cin.ignore();
	cout<<setw(35)<<"请输入姓名:";
	cin.getline(name,20);
	cout<<setw(35)<<"请输入密码:";
	cin.getline(password,15);
	fstream file;
	file.open(f,ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"worker文件打开失败";
		exit(0);
	}
	worker workers;
	for(i=0;!file.eof();i++)
	{
		  file.read((char*)&workers,sizeof(worker));
		  if(strcmp(workers.show_name(),name)==0)                   //此处有误将name改成id了
		  {
			  if(strcmp(workers.show_password(),password)==0)
			  {
				  file.close();
				  a=1;
			  }
		  }
	}
	if(a==1)
	  return 1;
	else
	{
		file.close();
	    return 0;
	}
	
}
/////////////////////////////////////////////////////////
int identify_pass(char * f)
{
	int i,a=0;
    char name[20];
	char password[15];
	cin.ignore();
	cout<<setw(35)<<"请输入姓名:";
	cin.getline(name,20);
	cout<<setw(35)<<"请输入密码:";
	cin.getline(password,15);
	fstream file;
	file.open(f,ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"worker文件打开失败";
		exit(0);
	}
	customer customers;
	for(i=0;!file.eof();i++)
	{
		  file.read((char*)&customers,sizeof(customer));
		  if(strcmp(customers.showname(),name)==0)                   //此处有误将name改成id了
		  {
			  if(strcmp(customers.showpassword(),password)==0)
			  {
				  file.close();
				  a=1;
			  }
		  }
	}
	if(a==1)
	  return 1;
	else
	{
		file.close();
	    return 0;
	}
	
}
