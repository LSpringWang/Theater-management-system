# include<iostream.h>
# include<iomanip.h>
# include<fstream.h>
# include<string.h>
# include<stdlib.h>
# include<ctype.h>
# include<conio.h>
# include"worker.h"
# include"cinema.h"
worker::worker(char * name1,char * home_add1):people(name1,home_add1)
{};
worker::worker():people()
{};
//////////////////////////////////////////////////////////////////////////影片设置
void worker::get(char * name1,char * home_add1)
{
    strcpy(name,name1);
	strcpy(home_add,home_add1);
}
void worker::set_film()
{
	int i;
	char c;
	char a[20],b[50];
	fstream file;
	file.open("film.dat",ios::app|ios::binary);
		if(file.fail())
		{
			cout<<"文件打开失败";
			exit(0);
		}
	cout<<setw(35)<<"正在进行影片设置"<<endl;
	for(i=0;c!='N';i++)
	{
		cout<<setw(35)<<"请输入影片名称:";
		cin.getline (a,20);
		cin.ignore();
		cout<<setw(35)<<"请输入影片主演:";
		cin.getline(b,50);
		film film1(a,b);
		film1.set_main_info();                  //设置     影片信息 （包括 片名 导演 地区 时长 票价
		film1.set_show_time();                   //设置放映时间
		film1.set_synopsis ();                    //设置            影片剧情
		film1.set_ticket();
		file.write((char *)&film1,sizeof(film1));
		cout<<"继续输入请按Y，退出请按N";
		cin>>c;
		c=toupper(c);
	}

}
void worker::get_job()
{
	cout<<setw(35)<<"请输入职务  :";
	cin.getline(job,10);
	cout<<setw(35)<<"请输入工号  :";
	cin>>work_num;
	cin.ignore();
}
void worker::show_self()
{
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"                           显示您的信息如下"<<endl<<endl<<endl;
	cout<<"                         姓名       :"<<name<<endl;
	cout<<"                         工号       :"<<setprecision(10)<<work_num<<endl;
	cout<<"                         职务       :"<<job<<endl;
	cout<<"                         电话       :"<<tel<<endl;
	cout<<"                         身份证号码 :"<<id_num<<endl;
	cout<<"                         邮箱       :"<<email<<endl;
	cout<<"                         家庭住址   :"<<home_add<<endl;
	//cout<<"密码"<<password<<endl;
}

////////////////////////////////////////////////////////////修改自己信息的子函数
void worker::change1()
{
	char a[20];
   cin.ignore();
   cout<<setw(35)<<"请输入修改后的姓名  :";
   cin.getline(a,20);
   strcpy(name,a);
}
void worker::change2()
{
	cout<<setw(35)<<"请输入修改后的工号  :";
	cin>>work_num;
	
}
void worker::change3()
{
	char a[10];
	cin.ignore();
	cout<<setw(35)<<"请输入修改后的职务  :";
	cin.getline(a,10);
	strcpy(job,a);
}
void worker::change4()
{
	char a[11];
	cin.ignore();
	cout<<setw(35)<<"请输入修改后的电话  :";
	cin.getline(a,11);
	strcpy(tel,a);
}
void worker::change5()
{
   char a[20];
   cin.ignore();
   cout<<setw(35)<<"请输入修改后的身份证号  :";
   cin.getline(a,20);
   strcpy(id_num,a);
}
void worker::change6()
{   
	char a[20];
	cin.ignore();
	cout<<setw(35)<<"请输入修改后的邮箱  :";
	cin.getline(a,20);
	strcpy(email,a);
}
void worker::change7()
{
	char a[50];
	cin.ignore();
	cout<<setw(35)<<"请输入修改后的家庭住址  :";
	cin.getline(a,50);
	strcpy(home_add,a);
 }
void worker::change8()
{
	cin.ignore();
	char a[15];
	char b[15];
	int i,c=0;
	for(i=0;;i++)
	{
		cout<<setw(35)<<"请输入修改后的密码  :"<<endl;
		cin.getline(a,15);
		cout<<setw(35)<<"请再次输入修改后的密码  :"<<endl;
		cin.getline(b,15);
		if(strcmp(a,b)==0)
		{
			strcpy(password,a);
			//c=1;
			break;
		}
		else
		{
			cout<<endl;
			cout<<setw(35)<<"输入密码不一致，请重新输入"<<endl;
		}
	}
}
////////////////////////////////////////////////按习项修改自己信息
void worker::change_self()
{
	int a;
	system("cls");
	show_self();
	cout<<endl<<endl;
	cout<<"                                   ************                                "<<endl;
	cout<<"                        ***********<请选择修改项>*********                     "<<endl;
    cout<<"                        **        1.姓名                **                     "<<endl;
	cout<<"                        **        2.工号                **                     "<<endl;
	cout<<"                        **        3.职务                **                     "<<endl;
	cout<<"                        **        4.电话                **                     "<<endl;
	cout<<"                        **        5.身份证号码          **                     "<<endl;
	cout<<"                        **        6.邮箱                **                     "<<endl;
	cout<<"                        **        7.家庭住址            **                     "<<endl;
	cout<<"                        **        8.密码                **                     "<<endl;
	cout<<"                        **********************************                     "<<endl;
	cin>>a;
	switch(a)
	{
		case 1:  change1();
			break;
		case 2:  change2();
			break;
		case 3:  change3();
			break;
		case 4:  change4();
			break;
		case 5:  change5();
			break;
		case 6:  change6();
			break;
		case 7:  change7();
			break;
		case 8:  change8();
			break;
	}

}
/////////////////////////////////////////////////////设置自己信息
void worker::set_my_information()
{
	int a=0,i;
	char id[20],num[15];
	cin.ignore();
	cout<<"下面进行身份验证"<<endl;
	cout<<setw(35)<<"请输入身份证号  :";
	cin.getline (id,20);
	cout<<setw(35)<<"请输入密码  :";
	cin.getline(num,15);
	worker worker1;
    fstream file1;
	file1.open("worker.dat",ios::in|ios::out|ios::binary);
	if(file1.fail())
	{
		cout<<"对不起“worker”文件打开失败";
		exit(0);
	}
	for(i=0;!file1.eof();i++)
	{
		file1.read((char*)&worker1,sizeof(worker1));
		if(strcmp(worker1.show_id(),id)==0)
		{
			break;
		}
		else 
			a++;
	}
	file1.close();
	cout<<"下面进行重新设置"<<endl;
	char names[20],add[50];
	cout<<setw(35)<<"请输入姓名  :";
    cin.getline(names,20);
	cout<<setw(35)<<"请输入家庭住址  :";
	cin.getline(add,50);
	worker work(names,add);
	work.get_job();
	work.get_info();
	work.get_passward();
	fstream file;
	file.open("worker.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"对不起“worker”文件打开失败";
		exit(0);
	}
	file.seekg((a)*sizeof(worker),ios::beg);
	file.write((char *)&work,sizeof(work));
	file.close ();
}
/////////////////////////////////////////////////////////返回姓名
char * worker::show_id()
{
	return id_num;
}
///////////////////////////////////////////////////////////返回密码
char * worker::show_password()
{
	return password;
}
///////////////////////////////////////////////////////影院信息设置
void worker::set_cinema()
{
	cinema cinema1;
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<setw(35)<<"下面设置影院信息"<<endl<<endl<<endl;
	cin>>cinema1;
	cinema1.set_info();
	fstream file;
	file.open("cinema.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败";
		exit(0);
	}
	file.write((char*)&cinema1,sizeof(cinema1));
	file.close();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"恭喜你，设置成功"<<endl<<endl;
	cout<<setw(42)<<"按回车键返回上一级菜单"<<endl;
	char e;
	cin.get(e);
}
/////////////////////////////////////////////////////////////////修改自己信息
void worker::change_my_information()
{
	int a=0,i,b=0;
	long double worknum;
	cin.ignore();
	cout<<setw(35)<<"请输入员工号  :";
	cin>>worknum;
	worker worker1;
    fstream file1;
	file1.open("worker.dat",ios::in|ios::out|ios::binary);
	if(file1.fail())
	{
		cout<<"对不起“worker”文件打开失败";
		exit(0);
	}
	for(i=0;!file1.eof();i++)
	{
		file1.read((char*)&worker1,sizeof(worker1));
		if(worker1.show_work_num()==worknum)
		{
			a++;
			break;
		}
		b++;
	}
	if(a!=0)
	{
	worker1.change_self();
	file1.seekg(b*sizeof(worker),ios::beg);
	file1.write((char*)&worker1,sizeof(worker));
	system("cls");
	cout<<setw(40)<<"恭喜你，修改成功"<<endl<<endl;
	cout<<setw(40)<<"按任意键，返回"<<endl;
	getch();
	}
	file1.close();
}
//////////////////////////////////////////////////////////////////////////////////////////链表
///////////////////////链表的建立
worker * worker::create()
{
   worker *head,*current,*last;
   head=current=new worker;	
   last=new worker;   	
   fstream file("worker.dat",ios::in|ios::binary);
   file.read((char*)last,sizeof(worker));
   while(!file.eof())
   {  	
	current->next=last;
	current=last;
	last=new worker;	
	file.read((char*)last,sizeof(worker));
   }
   current->next=NULL;
   free(last);
   file.close();
   return head; 	
}
////////////链表的输出
void  worker::print(worker * head)
{ 	worker *p;
    p=head->next;
  	if(p!=NULL)
	{
       	cout<<"\tEnter Num & score :";
       	while(p!=NULL)
		{
	        cout<<p->work_num<<"  ";
  	    	p=p->next;
       	}
  	}
}
/////////////////////////////////////////////链表的删除
void worker::del(worker *head,double num)
{
	fstream file("worker.dat",ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败";
		exit(0);
	}
	worker *p;
  	p=head->next;
  	while(p!=NULL)//&&  p->next->work_num  != num)
	{
	   
	   if(p->work_num!=num)
	   {
	   file.write((char*)p,sizeof(worker));
	   }
	   p=p->next;
	}
	file.close();

}
