# include<iostream.h>
# include<iomanip.h>
# include<stdlib.h>
# include<fstream.h>
# include<string.h>
# include"cinema.h" 
istream &operator >> (istream &strm,cinema &obj )

{
	strm.ignore ();
	cout<<setw(35)<<"������ӰԺ����  :";
	strm.getline(obj.name,30);
	cout<<setw(35)<<"������ӰԺ�绰  :";
	strm.getline(obj.tel,12);
	cout<<setw(35)<<"������ӰԺ��ַ  :";
    strm.getline(obj.add,50);
	cout<<setw(35)<<"������ӰԺ�Ĵ���ʱ��  :";
	strm.getline(obj.create_time,15);
	return strm;

}    
void cinema::set_name()
{
	cout<<setw(35)<<"������ӰԺ����  : ";
	cin.getline(name,30);
}
void cinema::set_add()
{
	
	cout<<setw(35)<<"������ӰԺ��ַ  : ";
	cin.getline(add,50);
}
void cinema::set_tel()
{
      cout<<setw(35)<<"������绰  : ";
	  cin.getline(tel,12);
}
void cinema::set_time()
{
         cout<<setw(35)<<"�����봴��ʱ��  : ";
		 cin.getline(create_time,15);
}
void cinema::set_info()
{ 
	char a[100];
	cout<<setw(35)<<"������ӰԺ������Ϣ  : ";
	cin.getline(a,1000);
	//info=new char[20];
	strcpy(info,a);
}
void cinema::show_info()
{
	system("cls");
	cout<<endl<<endl<<endl<<endl;
	cout<<"                   ӰԺ����     : "<<name<<endl<<endl;
	cout<<"                   ӰԺ��ַ     : "<<add<<endl<<endl;
	cout<<"                   ӰԺ�绰     : "<<tel<<endl<<endl;
	cout<<"                   ӰԺ����ʱ�� :"<<create_time<<endl<<endl;
	cout<<"                   ӰԺ������Ϣ : "<<info<<endl;
}
void cinema::file_open()
{
	fstream file("cinema.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"�ļ���ʧ��"<<endl;
		exit(0);      
	}
	cinema b;
	file.read((char*)&b,sizeof(class cinema));
	b.show_info();
}
