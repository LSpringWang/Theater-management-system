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
//////////////////////////////////////////////////////////////////////////ӰƬ����
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
			cout<<"�ļ���ʧ��";
			exit(0);
		}
	cout<<setw(35)<<"���ڽ���ӰƬ����"<<endl;
	for(i=0;c!='N';i++)
	{
		cout<<setw(35)<<"������ӰƬ����:";
		cin.getline (a,20);
		cin.ignore();
		cout<<setw(35)<<"������ӰƬ����:";
		cin.getline(b,50);
		film film1(a,b);
		film1.set_main_info();                  //����     ӰƬ��Ϣ ������ Ƭ�� ���� ���� ʱ�� Ʊ��
		film1.set_show_time();                   //���÷�ӳʱ��
		film1.set_synopsis ();                    //����            ӰƬ����
		film1.set_ticket();
		file.write((char *)&film1,sizeof(film1));
		cout<<"���������밴Y���˳��밴N";
		cin>>c;
		c=toupper(c);
	}

}
void worker::get_job()
{
	cout<<setw(35)<<"������ְ��  :";
	cin.getline(job,10);
	cout<<setw(35)<<"�����빤��  :";
	cin>>work_num;
	cin.ignore();
}
void worker::show_self()
{
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"                           ��ʾ������Ϣ����"<<endl<<endl<<endl;
	cout<<"                         ����       :"<<name<<endl;
	cout<<"                         ����       :"<<setprecision(10)<<work_num<<endl;
	cout<<"                         ְ��       :"<<job<<endl;
	cout<<"                         �绰       :"<<tel<<endl;
	cout<<"                         ���֤���� :"<<id_num<<endl;
	cout<<"                         ����       :"<<email<<endl;
	cout<<"                         ��ͥסַ   :"<<home_add<<endl;
	//cout<<"����"<<password<<endl;
}

////////////////////////////////////////////////////////////�޸��Լ���Ϣ���Ӻ���
void worker::change1()
{
	char a[20];
   cin.ignore();
   cout<<setw(35)<<"�������޸ĺ������  :";
   cin.getline(a,20);
   strcpy(name,a);
}
void worker::change2()
{
	cout<<setw(35)<<"�������޸ĺ�Ĺ���  :";
	cin>>work_num;
	
}
void worker::change3()
{
	char a[10];
	cin.ignore();
	cout<<setw(35)<<"�������޸ĺ��ְ��  :";
	cin.getline(a,10);
	strcpy(job,a);
}
void worker::change4()
{
	char a[11];
	cin.ignore();
	cout<<setw(35)<<"�������޸ĺ�ĵ绰  :";
	cin.getline(a,11);
	strcpy(tel,a);
}
void worker::change5()
{
   char a[20];
   cin.ignore();
   cout<<setw(35)<<"�������޸ĺ�����֤��  :";
   cin.getline(a,20);
   strcpy(id_num,a);
}
void worker::change6()
{   
	char a[20];
	cin.ignore();
	cout<<setw(35)<<"�������޸ĺ������  :";
	cin.getline(a,20);
	strcpy(email,a);
}
void worker::change7()
{
	char a[50];
	cin.ignore();
	cout<<setw(35)<<"�������޸ĺ�ļ�ͥסַ  :";
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
		cout<<setw(35)<<"�������޸ĺ������  :"<<endl;
		cin.getline(a,15);
		cout<<setw(35)<<"���ٴ������޸ĺ������  :"<<endl;
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
			cout<<setw(35)<<"�������벻һ�£�����������"<<endl;
		}
	}
}
////////////////////////////////////////////////��ϰ���޸��Լ���Ϣ
void worker::change_self()
{
	int a;
	system("cls");
	show_self();
	cout<<endl<<endl;
	cout<<"                                   ************                                "<<endl;
	cout<<"                        ***********<��ѡ���޸���>*********                     "<<endl;
    cout<<"                        **        1.����                **                     "<<endl;
	cout<<"                        **        2.����                **                     "<<endl;
	cout<<"                        **        3.ְ��                **                     "<<endl;
	cout<<"                        **        4.�绰                **                     "<<endl;
	cout<<"                        **        5.���֤����          **                     "<<endl;
	cout<<"                        **        6.����                **                     "<<endl;
	cout<<"                        **        7.��ͥסַ            **                     "<<endl;
	cout<<"                        **        8.����                **                     "<<endl;
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
/////////////////////////////////////////////////////�����Լ���Ϣ
void worker::set_my_information()
{
	int a=0,i;
	char id[20],num[15];
	cin.ignore();
	cout<<"������������֤"<<endl;
	cout<<setw(35)<<"���������֤��  :";
	cin.getline (id,20);
	cout<<setw(35)<<"����������  :";
	cin.getline(num,15);
	worker worker1;
    fstream file1;
	file1.open("worker.dat",ios::in|ios::out|ios::binary);
	if(file1.fail())
	{
		cout<<"�Բ���worker���ļ���ʧ��";
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
	cout<<"���������������"<<endl;
	char names[20],add[50];
	cout<<setw(35)<<"����������  :";
    cin.getline(names,20);
	cout<<setw(35)<<"�������ͥסַ  :";
	cin.getline(add,50);
	worker work(names,add);
	work.get_job();
	work.get_info();
	work.get_passward();
	fstream file;
	file.open("worker.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"�Բ���worker���ļ���ʧ��";
		exit(0);
	}
	file.seekg((a)*sizeof(worker),ios::beg);
	file.write((char *)&work,sizeof(work));
	file.close ();
}
/////////////////////////////////////////////////////////��������
char * worker::show_id()
{
	return id_num;
}
///////////////////////////////////////////////////////////��������
char * worker::show_password()
{
	return password;
}
///////////////////////////////////////////////////////ӰԺ��Ϣ����
void worker::set_cinema()
{
	cinema cinema1;
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<setw(35)<<"��������ӰԺ��Ϣ"<<endl<<endl<<endl;
	cin>>cinema1;
	cinema1.set_info();
	fstream file;
	file.open("cinema.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"�ļ���ʧ��";
		exit(0);
	}
	file.write((char*)&cinema1,sizeof(cinema1));
	file.close();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"��ϲ�㣬���óɹ�"<<endl<<endl;
	cout<<setw(42)<<"���س���������һ���˵�"<<endl;
	char e;
	cin.get(e);
}
/////////////////////////////////////////////////////////////////�޸��Լ���Ϣ
void worker::change_my_information()
{
	int a=0,i,b=0;
	long double worknum;
	cin.ignore();
	cout<<setw(35)<<"������Ա����  :";
	cin>>worknum;
	worker worker1;
    fstream file1;
	file1.open("worker.dat",ios::in|ios::out|ios::binary);
	if(file1.fail())
	{
		cout<<"�Բ���worker���ļ���ʧ��";
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
	cout<<setw(40)<<"��ϲ�㣬�޸ĳɹ�"<<endl<<endl;
	cout<<setw(40)<<"�������������"<<endl;
	getch();
	}
	file1.close();
}
//////////////////////////////////////////////////////////////////////////////////////////����
///////////////////////����Ľ���
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
////////////��������
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
/////////////////////////////////////////////�����ɾ��
void worker::del(worker *head,double num)
{
	fstream file("worker.dat",ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"�ļ���ʧ��";
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
