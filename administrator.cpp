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
		cout<<"�ļ���ʧ��"<<endl;
		exit(0);
	}
}
void administrator::ad_staff()
{
	int a;
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                       ************��ѡ��***********      "<<endl;
	cout<<"                       **     1.����Ա����Ϣ      **      "<<endl;
	cout<<"                       **     2.�޸�Ա����Ϣ      **      "<<endl;
	cout<<"                       **     3.����Ա����Ϣ      **      "<<endl;
	cout<<"                       **     4.ɾ��Ա����Ϣ      **      "<<endl;
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
///////////////////////////////////////////////////////////////////////����Ա����Ϣ
void administrator::set_information()
{
	int a=0;
	cin.ignore();
    fstream file1;
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<setw(35)<<"�����������  :"<<endl<<endl;
	char names[20],add[40];
	cout<<setw(35)<<"����������  :";
	cin.getline(names,20);
	cout<<setw(35)<<"�������ͥסַ  :";
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
		cout<<"�Բ���worker���ļ���ʧ��";
		exit(0);
	}
	file.write((char *)&work,sizeof(worker));
	file.close ();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"��ϲ�㣬���óɹ�"<<endl<<endl<<endl;
	cout<<setw(42)<<"�������������һ���˵�"<<endl;
	getch();
}
//////////////////////////////////////////////////////////����Ա����Ϣ
void administrator::find_staff()
{
   double num;
   int i,a=0;
   worker worker1;
   cin.ignore();
   cout<<"������Ա����";
   cin>>num;
   //cout<<"����������";
   //cin.getline(num,15);
   fstream file;
   file.open("worker.dat",ios::in|ios::out|ios::binary);
   if(file.fail())
   {
	   cout<<"�ļ���ʧ��";
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
	   cout<<"�Բ�����Ѱ�ҵ��˲�����";
   }
   file.close();
   cout<<"�����������"<<endl;
   getch();
}
////////////////////////////////////////��ʾ�Լ���Ϣ
void administrator::show_admion()
{
	double num;
	int i,a=0;
	administrator administrator1;
	cout<<"�����빤��"<<endl;
	cin>>num;
	fstream file("administrator.dat",ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"�ļ���ʧ��";
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
		cout<<"                          û����ҪѰ����"<<endl;
	}
	cout<<endl<<endl<<"                            �������������"<<endl;
	getch();
}
//////////////////////////////////////////////////////////////////ɾ��Ա����Ϣ
void administrator::del_staff()
{
	double num;
	cout<<setw(40)<<"��������ɾ����Ա����";
	cin>>num;
	worker *head;
	worker a;
    head=a.create ();
	a.del(head,num);
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"��ϲ�㣬ɾ���ɹ�"<<endl<<endl;
	cout<<setw(40)<<"�����������"<<endl;
	getch();
}
////////////////////////////////////////////////////�޸��Լ���Ϣ
void administrator::set_my_information()
{
	int a=0,i;
	char num[15];
	double n;
	cin.ignore();
	cout<<"������������֤"<<endl;
	cout<<setw(35)<<"�����빤��  :";
	cin>>n;
	cin.ignore();
	cout<<setw(35)<<"����������  :";
	cin.getline(num,15);
    administrator administrator1;
    fstream file1;
	file1.open("administrator.dat",ios::in|ios::out|ios::binary);
	if(file1.fail())
	{
		cout<<"�Բ���worker���ļ���ʧ��";
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
	cout<<"���������������  :"<<endl;
	char names[20],add[50];
	cout<<setw(35)<<"���������� :";
	cin.getline(names,20);
	cout<<setw(35)<<"�������ͥסַ  :";
	cin.getline(add,50);
	administrator administrator2(names,add);
	administrator2.get_job();
	administrator2.get_info();
	administrator2.get_passward();
	fstream file;
	file.open("administrator.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"�Բ���worker���ļ���ʧ��";
		exit(0);
	}
	file.seekg(a*sizeof(administrator),ios::beg);
	file.write((char *)&administrator2,sizeof(administrator));
	file.close ();
}
/////////////////////////////////////////////////���ӹ���Ա
void administrator::add_administrator()
{
	int a=0;
	cin.ignore();
    fstream file1;
	system("cls");
	cout<<endl<<endl;
	cout<<setw(40)<<"��������ӹ���Ա����Ϣ  :"<<endl;
	char names[20],add[40];
	cout<<setw(35)<<"����������  :";
	cin.getline(names,20);
	cout<<setw(35)<<"�������ͥסַ  :";
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
		cout<<"�Բ���administrator1���ļ���ʧ��";
		exit(0);
	}
	file.write((char *)&administrator1,sizeof(administrator));
	file.close ();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"��ϲ�㣬��ӹ���Ա�ɹ�"<<endl;
	cout<<setw(38)<<"�����������"<<endl;
	getch();
}






