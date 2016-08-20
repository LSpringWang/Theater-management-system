# include<iostream.h>
# include<iomanip.h>
# include<string.h>
# include<stdlib.h>
# include<conio.h>
# include<fstream.h>
# include"administrator.h"
administrator::administrator()
{};
administrator::administrator(char * name1,char * home_add1):worker(name1,home_add1)
{};

void administrator::find_password()
{
	fstream file;
	file.open("password.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败"<<endl;
		exit(0);
	}
}
void administrator::ad_staff()
{
	int a;
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                       ************请选择***********      "<<endl;
	cout<<"                       **     1.增加员工信息      **      "<<endl;
	cout<<"                       **     2.修改员工信息      **      "<<endl;
	cout<<"                       **     3.查找员工信息      **      "<<endl;
	cout<<"                       **     4.删除员工信息      **      "<<endl;
	cout<<"                       *****************************      "<<endl;
	cin>>a;
	switch(a)
	{
	case 1:
		{
		administrator ad;
		ad.add_staff();
		break;
		}
	case 2:
		{
	    administrator ad;
		ad.change_my_information();
		break;
		}
	case 3:
		{
         find_staff();
		 break;
		}
	case 4:
	    del_staff();
		break;
	}
}
void administrator::add_staff()
{
	administrator a;
	a.set_information();
}
///////////////////////////////////////////////////////////////////////增加员工信息
void administrator::set_information()
{
	int a=0;
	cin.ignore();
    fstream file1;
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<setw(35)<<"下面进行设置  :"<<endl<<endl;
	char names[20],add[40];
	cout<<setw(35)<<"请输入姓名  :";
	cin.getline(names,20);
	cout<<setw(35)<<"请输入家庭住址  :";
	cin.getline(add,40);
	worker work(names,add);
	work.get_job();
	work.get_info();
	work.get_passward();
	fstream file;
	file.open("worker.dat",ios::in|ios::out|ios::binary);
	file.seekg(0L,ios::end);
	if(file.fail())
	{
		cout<<"对不起“worker”文件打开失败";
		exit(0);
	}
	file.write((char *)&work,sizeof(worker));
	file.close ();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"恭喜你，设置成功"<<endl<<endl<<endl;
	cout<<setw(42)<<"按任意键返回上一级菜单"<<endl;
	getch();
}
//////////////////////////////////////////////////////////查找员工信息
void administrator::find_staff()
{
   double num;
   int i,a=0;
   worker worker1;
   cin.ignore();
   cout<<"请输入员工号";
   cin>>num;
   //cout<<"请输入密码";
   //cin.getline(num,15);
   fstream file;
   file.open("worker.dat",ios::in|ios::out|ios::binary);
   if(file.fail())
   {
	   cout<<"文件打开失败";
	   exit(0);
   }
   file.read((char*)&worker1,sizeof(worker));
   for(i=0;!file.eof();i++)
   {
	   
	   if(worker1.show_work_num()==num)
	   {
		  worker1.show_self();
		  a=1;
	   }
	   file.read((char*)&worker1,sizeof(worker));
   }
   if(a==0)
   {
	   cout<<"对不起，您寻找的人不存在";
   }
   file.close();
   cout<<"按任意键继续"<<endl;
   getch();
}
////////////////////////////////////////显示自己信息
void administrator::show_admion()
{
	double num;
	int i,a=0;
	administrator administrator1;
	cout<<"请输入工号"<<endl;
	cin>>num;
	fstream file("administrator.dat",ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败";
		exit(0);
	}
	for(i=0;!file.eof();i++)
	{
		file.read((char*)&administrator1,sizeof(administrator));
		if(administrator1.show_work_num()==num)
		{
			
			administrator1.show_self();
		    a++;
			break;
		}
	}
	if(a==0)
	{
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                          没有您要寻找人"<<endl;
	}
	cout<<endl<<endl<<"                            输入任意键继续"<<endl;
	getch();
}
//////////////////////////////////////////////////////////////////删除员工信息
void administrator::del_staff()
{
	double num;
	cout<<setw(40)<<"请输入欲删除的员工号";
	cin>>num;
	worker *head;
	worker a;
    head=a.create ();
	a.del(head,num);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"恭喜你，删除成功"<<endl<<endl;
	cout<<setw(40)<<"按任意键继续"<<endl;
	getch();
}
////////////////////////////////////////////////////修改自己信息
void administrator::set_my_information()
{
	int a=0,i;
	char num[15];
	double n;
	cin.ignore();
	cout<<"下面进行身份验证"<<endl;
	cout<<setw(35)<<"请输入工号  :";
	cin>>n;
	cin.ignore();
	cout<<setw(35)<<"请输入密码  :";
	cin.getline(num,15);
    administrator administrator1;
    fstream file1;
	file1.open("administrator.dat",ios::in|ios::out|ios::binary);
	if(file1.fail())
	{
		cout<<"对不起“worker”文件打开失败";
		exit(0);
	}
	for(i=0;;i++)
	{
		file1.read((char*)&administrator1,sizeof(administrator));
		if(administrator1.show_work_num()==n)
		{
			if(strcmp(administrator1.show_password(),num)==0)
			{
			  break;
			}
		}
	else 
			a++;
	}
	file1.close();
	cout<<"下面进行重新设置  :"<<endl;
	char names[20],add[50];
	cout<<setw(35)<<"请输入姓名 :";
	cin.getline(names,20);
	cout<<setw(35)<<"请输入家庭住址  :";
	cin.getline(add,50);
	administrator administrator2(names,add);
	administrator2.get_job();
	administrator2.get_info();
	administrator2.get_passward();
	fstream file;
	file.open("administrator.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"对不起“worker”文件打开失败";
		exit(0);
	}
	file.seekg(a*sizeof(administrator),ios::beg);
	file.write((char *)&administrator2,sizeof(administrator));
	file.close ();
}
/////////////////////////////////////////////////增加管理员
void administrator::add_administrator()
{
	int a=0;
	cin.ignore();
    fstream file1;
	system("cls");
	cout<<endl<<endl;
	cout<<setw(40)<<"请输入添加管理员的信息  :"<<endl;
	char names[20],add[40];
	cout<<setw(35)<<"请输入姓名  :";
	cin.getline(names,20);
	cout<<setw(35)<<"请输入家庭住址  :";
	cin.getline(add,40);
	administrator administrator1(names,add);
	administrator1.get_job();
	administrator1.get_info();
	administrator1.get_passward();
	fstream file;
	file.open("administrator.dat",ios::in|ios::out|ios::binary);
	file.seekg(0L,ios::end);
	if(file.fail())
	{
		cout<<"对不起“administrator1”文件打开失败";
		exit(0);
	}
	file.write((char *)&administrator1,sizeof(administrator));
	file.close ();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"恭喜你，添加管理员成功"<<endl;
	cout<<setw(38)<<"按任意键继续"<<endl;
	getch();
}






