# include<iostream.h>
# include<fstream.h>
# include<string.h>
# include<iomanip.h>
# include<stdlib.h>
# include"people.h"

//���캯��
people::people(char *name1,char *home_add1)
{
	strcpy(name,name1);
	strcpy(home_add,home_add1);
}
//��������
/*
people::~people ()
{
	delete []name;
	delete []home_add;
}
*/
void people::get_info()
{
	//cin.ignore();
	cout<<setw(35)<<"����������˺�  :";
	cin.getline(id_num,20);
	cout<<setw(35)<<"������绰  :";
	cin.getline(tel,13);
	cout<<setw(35)<<"������email  :";
	cin.getline(email,20);
}

void people::get_passward()
{
	char a[15],b[15];
	int i,c=0;
	cout<<endl;
	cout<<"                     ���� ���ڽ�����������   :"<<endl;
	for(i=0;c!=1;i++)
	{
		cout<<"                     ����������    :";
		cin.getline(a,15);
		cout<<endl;
		cout<<"                     ���ٴ���������:";
		cin.getline (b,15);
		if(strcmp(a,b)==0)
		{
			strcpy(password,a);
			c=1;
		}
		if(c!=1)
		{
			cout<<endl;
			cout<<"             ����������������������";
		}
	}
}
void people::get_name()
{
	cout<<setw(35)<<"����������  :";
	cin>>name;
}
void people::find_password()
{
	fstream file;
	file.open("password.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"�ļ���ʧ��"<<endl;
		exit(0);
	}
	file.close();
}
char * people::show_id()
{
	return id_num;
}









