# include"customer.h"
//# include"film.h"
# include<fstream.h>
# include<string.h>
# include<iomanip.h>
# include<conio.h>
# include<stdlib.h>
///////////////////设置购票的场次
void customer::get_b(int a)
{
       b=a;
}
//////////////////////////////////////////////显示自己信息
void customer::show_self()
{
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<setw(45)<<"个人信息显示如下 :"<<endl<<endl;
	cout<<setw(40)<<"姓名  :";
	cout<<name<<endl;
	cout<<setw(40)<<"身份证号  :";
	cout<<id_num<<endl;
	cout<<setw(40)<<"电话  :";
	cout<<tel<<endl;
	cout<<setw(40)<<"电子邮件  :";
	cout<<email<<endl;
	cout<<setw(40)<<"家庭住址  :";
	cout<<home_add<<endl;
}
void customer::show_have_book()
{
	cout<<setw(35)<<"已订购的电影  :";
	cout<<have_book<<endl;
}
void customer::vip_mem()
{
	int a;
	for(;a!=5;)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择*************       "<<endl;
		cout<<"                       **   1.查看自己信息          **       "<<endl;
		cout<<"                       **   2.修改自己信息          **       "<<endl;
		cout<<"                       **   3.查看影片信息          **       "<<endl;
		cout<<"                       **   4.订票                  **       "<<endl;
		cout<<"                       **   5.返回上一级菜单        **       "<<endl;
		cout<<"                       *******************************       "<<endl;
		cin>>a;
		switch(a)
		{
			case 1:
			{
				int i;
				customer customer1;
				fstream file("vip_customer.dat",ios::in|ios::binary);
				if(file.fail())
				{
					cout<<"文件打开失败";
					exit(0);
				}
				char num[20];
				cin.ignore();
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(28)<<"请输入身份证号:";
				cin.getline(num,20);
				file.read((char*)&customer1,sizeof(customer));
				for(i=0;!file.eof();i++)
				{
					if(strcmp(customer1.show_id(),num)==0)
					{
						customer1.show_self();
						customer1.show_have_book();
						cout<<endl<<endl;
						cout<<"                          《按回车键返回上一级菜单》";
						char ch;
						cin.get(ch);
					    break;
					}
					file.read((char*)&customer1,sizeof(customer));
				}
				break;
			}
			case 2:
				{
					cin.ignore();
					change_self();
					break;
				}
			case 3:
				{
				customer customer1;
				customer1.find_film();
				break;
				}
			case 4:
				{
				customer customer1;
				customer1.vip_book();
				break;
				}
			case 5:
				break;
		}
	}
}
void customer::find_film()
{
	int i,a;
	for(i=0;a!=3;i++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择*************       "<<endl;
		cout<<"                       **       1.按片名查询                 "<<endl;
		cout<<"                       **       2.影院全部上映影片查询       "<<endl;
		cout<<"                       **       3.返回上一级菜单             "<<endl;
		cout<<"                       *******************************       "<<endl;
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
/////////////////////////////////////     设置一定票的时间
void customer::get_time(char *a)
{
	strcpy(book_film_time1,a);

}
////////////////////////////////////////////////     vip订票
void customer::set_have_book(char *p)
{
   strcpy(have_book,p);
}
void customer::vip_book()
{
	int i,b;
	char name[20];
	film film1;
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cin.ignore();
    cout<<"                请输入欲购票的电影名称 :";
	cin.getline(name,20);
	cout<<"                请输入欲购买的场次     :";
	cin>>b;
	fstream file("film.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"film文件打开失败"<<endl;
		exit(0);
	}
	for(i=0;!file.eof();i++)
	{
		file.read((char *)&film1,sizeof(film));
		if(strcmp(film1.show_name(),name)==0)
		{
			break;
		}
	}
	if(!file.eof())
	{
		if(b==1)
		{
			if(film1.show_ticket1()==0)
			{
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(30)<<"对不起此电影票已售完";
			}
			else
			   film1.left_ticket_1();                       //余票减一
		}
		if(b==2)
		{
			if(film1.show_ticket2()==0)
			{
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(30)<<"对不起此电影票已售完";
			}
			else
				film1.left_ticket_2();
		}
		if(b==3)
		{
			if(film1.show_ticket3()==0)
			{
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(30)<<"对不起此电影票已售完";
			}
			else
			   film1.left_ticket_3();
		}
		file.seekg(-sizeof(film),ios::cur);
		file.write((char*)&film1,sizeof(film));
		file.close();
		///////////////////////////////////////////////////////vip会员信息更改订票后在文件中更改
		char num[20];
		cout<<endl<<endl;
		cin.ignore();
		cout<<setw(35)<<"请输入你的身份证号  :";
		cin.getline(num,20);
		fstream file1("vip_customer.dat",ios::in|ios::out|ios::binary);
		fstream file2("order_people.dat",ios::in|ios::out|ios::binary);
		if(file1.fail())
		{
			cout<<"vip_customer文件打开失败";
			exit(0);
		}
		if(file2.fail())
		{
			cout<<"order_people文件打开失败";
			exit(0);
		}
		customer customer1;
		for(i=0;;i++)
		{
			file1.read((char*)&customer1,sizeof(customer));
			if(strcmp(customer1.show_id(),num)==0)
			{
				break;
			}
		}
		customer1.set_have_book(name);                       ////设置订购者的影片时间
		customer1.get_b(b);
		if(b==1)
		customer1.get_time(film1.show_time1());
		if(b==2)
		customer1.get_time(film1.show_time2());
		if(b==3)
		customer1.get_time(film1.show_time3());
		file1.seekg(-sizeof(customer),ios::cur);
		file2.seekg(0L,ios::end);
		file1.write((char*)&customer1,sizeof(customer));
		file2.write((char*)&customer1,sizeof(customer));
		file1.close();
		file2.close();
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                          恭喜你订票成功"<<endl;
		char e;
		cout<<"                     请输入回车键返回上一级菜单";
		cin.get(e);
	}
	else
	{
		cout<<"               对不起，没有此影片    "<<endl;
	    cout<<"                回车键键继续         "<<endl;
	    char e;
	    cin.get(e);
	}
}

void customer::get_book_1()
{
	strcpy(have_book,"您暂时没有订购影票");
}
/////////////////////////////////////////////////////////////修改自己的信息
void customer::change_self()
{
	char a[20];
	int b, i;
	customer customer1; 
	fstream file("vip_customer.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败";
		exit(0);
	}
	cout<<setw(35)<<"请输入身份证号  :";
	cin.getline(a,20);
	file.read((char *)&customer1,sizeof(customer));
	for(i=0;!file.eof();i++)
	{
		if(strcmp(customer1.show_id(),a)==0)
		{
			customer customer2=customer1;
			system("cls");
		    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		    cout<<"                       ************请选择*******************   "<<endl;
			cout<<"                       **      1.修改姓名                 **   "<<endl;
			cout<<"                       **      2.修改家庭住址             **   "<<endl;
			cout<<"                       **      3.修改电话，身份证号,邮箱  **   "<<endl;
			cout<<"                       **      4.修改密码                 **   "<<endl;
			cout<<"                       **************************************  "<<endl;
			cin>>b;
			switch(b)
			{
			case 1:
				customer2.get_name();
				break;
			case 3:
				customer2.get_info();
				break;
			case 2:
				customer2.get_add();
				break;
			case 4:
				customer2.get_passward();
				break;
			}
			customer2.get_book_1();
			file.seekg(-sizeof(customer),ios::cur);
			file.write((char *)&customer2,sizeof(customer));
            system("cls");
		    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<setw(35)<<"恭喜您，修改成功"<<endl;
			break;
		}
		file.read((char *)&customer1,sizeof(customer));
	}
	if(file.eof())
	{
		cout<<endl<<endl;
		cout<<setw(30)<<"对不起，没有此人"<<endl;
	}
	cout<<endl<<endl;
	cout<<setw(30)<<"按任意键继续"<<endl;
	getch();
}

//////////////////////////////////////////////注册会员
void customer::regist()
{
	customer customer2;
	customer2.get_name();
	cin.ignore ();
	customer2.get_info();
	customer2.get_add();
	customer2.get_passward();
    customer2.get_book_1();
	fstream file("vip_customer.dat",ios::app|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败";
		exit(0);
	} 
	file.write((char*)&customer2,sizeof(customer));
	file.close();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                             恭喜你，会员注册成功"<<endl<<endl;
	cout<<"                      如果想继续订票，请返回会员订票窗口"<<endl;
	cout<<"                              按任意键继续"<<endl;
	getch();
}
////////////////////////////////////////////////////////////////////
void customer::get_add()
{
	//cin.ignore();
	cout<<setw(35)<<"请输入地址  :";
	cin.getline(home_add,40);
}
////////////////////////////////////////////////订票
void customer::order()
{
	int i,b;
	char name[20];
	film film1;
	cin.ignore();
	system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<setw(30)<<"请输入欲购票的电影名称  :";
	cin.getline(name,20);
	cout<<setw(30)<<"请输入欲购买的场次  :";
	cin>>b;
	fstream file("film.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"film文件打开失败"<<endl;
		exit(0);
	}
	file.read((char *)&film1,sizeof(film));
	for(i=0;!file.eof();i++)
	{
		if(strcmp(film1.show_name(),name)==0)
		{
			break;
		}
		file.read((char *)&film1,sizeof(film));
		if(file.eof())
		{
			break;
		}
	}
	if(file.eof())
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<setw(35)<<"对不起没有您要找的影片"<<endl;
	}
	else
	{
		if(b==1)
		{
			if(film1.show_ticket1()==0)
			{
				system("cls");
		        cout<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(30)<<"对不起此电影票已售完";
			}
			else
			   film1.left_ticket_1();                       //余票减一
		}
		if(b==2)
		{
			if(film1.show_ticket2()==0)
				{
				system("cls");
		        cout<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(30)<<"对不起此电影票已售完";
			}
			else
				film1.left_ticket_2();
		}
		if(b==3)
		{
			if(film1.show_ticket3()==0)
				{
				system("cls");
		        cout<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(30)<<"对不起此电影票已售完";
			}
			else
			   film1.left_ticket_3();
		}
		file.seekg(-sizeof(film),ios::cur);
		file.write((char*)&film1,sizeof(film));
		file.close();

		fstream file1("order_people.dat",ios::app|ios::binary);
		if(file1.fail())
		{
			cout<<"order_people文件打开失败";
			exit(0);
		}
		customer customer2;
		customer2.get_name();
		cin.ignore();
		customer2.get_info();
		customer2.set_have_book(name);
		customer2.get_b(b);
	    if(b==1)
	    customer2.get_time(film1.show_time1());
        if(b==2)
	    customer2.get_time(film1.show_time2());
        if(b==3)
	    customer2.get_time(film1.show_time3());
		file1.write((char*)&customer2,sizeof(customer));
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<setw(30)<<"恭喜你，购票成功"<<endl;
	}
	cout<<endl;
	cout<<setw(34)<<"按任意键返回上一级菜单"<<endl;
	getch();
}
//////////////////////////////////////////////////////////退票
void customer::vip_unbook()
{
	char id[20];
	int b=0;
    customer customer1;
	customer customer2;
	fstream file("order_people.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"order_people文件打开失败";
		exit(0);
	}
	cin.ignore();
	cout<<endl;
	cout<<setw(35)<<"请输入身份证号  :";
	cin.getline(id,20);
	file.read((char*)&customer1,sizeof(customer));
	for(;!file.eof();)
	{
		if(strcmp(customer1.id_num,id)==0)
		{
			customer2=customer1;
			file.close();
			customer *head;
			head=create();
			del(head,id);
			b=1;
			break;
		}
		file.read((char*)&customer1,sizeof(customer));
	}
	if(b==0)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<setw(30)<<"对不起没有您的订票信息";
	}
	fstream file1("vip_customer.dat",ios::in|ios::out|ios::binary);
	if(file1.fail())
	{
		cout<<"文件打开失败";
		exit(0);
	}
	file1.read((char*)&customer1,sizeof(customer));
	for(;!file1.eof();)
	{
		if(strcmp(customer1.id_num,id)==0)
		{
			customer1.get_book_1();
			file1.seekg(-sizeof(customer),ios::cur);
			file1.write((char*)&customer1,sizeof(customer));
			file1.close();
			break;
		}
		file1.read((char*)&customer1,sizeof(customer));

	}
	/////////////////////////////////////////////////////////////////////////////
	int i;
	film film1;
	fstream file2("film.dat",ios::in|ios::out|ios::binary);                  
	if(file2.fail())                                                          
	{
		cout<<"film文件打开失败"<<endl;
		exit(0);
	}
	file2.read((char *)&film1,sizeof(film));
	for(i=0;!file.eof();i++)
	{
		if(strcmp(film1.show_name(),customer2.have_book)==0)
		{
			break;
		}
		file2.read((char *)&film1,sizeof(film));
	}
	int c=customer2.b;
	
	if(c==1)
	{
		film1.add_left_ticket_1();
	}
	if(c==2)
	{
		film1.add_left_ticket_2();
	}
	if(c==3)
	{
		film1.add_left_ticket_3();
	}

	file2.seekg(-sizeof(film),ios::cur);
	file2.write((char*)&film1,sizeof(film));
	file2.close();
}
void customer::look_all()
{
	char e;
	system("cls");
	customer customer1;
	fstream file("order_people.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"customer文件打开失败";
		exit(0);
	}
	cin.ignore();
	file.read((char*)&customer1,sizeof(customer));
	for(;!file.eof();)
	{
		cout<<endl<<endl;
		customer1.show_name();
		customer1.show_have_book();
		customer1.show_b();
		customer1.show_book_time1();
		file.read((char*)&customer1,sizeof(customer));
		cout<<setw(38)<<"按回车键继续"<<endl;
		cin.get(e);
		//cout<<endl;
	}
	cout<<endl<<endl;
	cout<<setw(38)<<"以上为全部的订票人员"<<endl;
	cout<<setw(35)<<"按任意键继续";
	cin.get(e);
	file.close();
}

//////////////////////////////////////////////////////////////////////////////////////////链表
///////////////////////链表的建立
customer * customer::create()
{
   customer *head,*current,*last;
   head=current=new customer;	
   last=new customer;   	
   fstream file("order_people.dat",ios::in|ios::binary);
   file.read((char*)last,sizeof(customer));
   while(!file.eof())
   {  	
	current->next=last;
	current=last;
	last=new customer;	
	file.read((char*)last,sizeof(customer));
   }
   current->next=NULL;
   free(last);
   file.close();
   return head; 	
}
/////////////////////////////////////////////链表的删除
void customer::del(customer *head,char*id)
{
	fstream file("order_people.dat",ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败";
		exit(0);
	}
	customer *p;
  	p=head->next;
  	while(p!=NULL)
	{
	   
	   if(strcmp(p->id_num,id)!=0)
	   {
	   file.write((char*)p,sizeof(customer));
	   }
	   p=p->next;
	}
	file.close();

}
