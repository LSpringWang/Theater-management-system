# include<iostream.h>
# include<iomanip.h>
# include<stdlib.h>
# include<fstream.h>
# include<string.h>
# include"cinema.h" 
istream &operator >> (istream &strm,cinema &obj )

{
	strm.ignore ();
	cout<<setw(35)<<"请输入影院名称  :";
	strm.getline(obj.name,30);
	cout<<setw(35)<<"请输入影院电话  :";
	strm.getline(obj.tel,12);
	cout<<setw(35)<<"请输入影院地址  :";
    strm.getline(obj.add,50);
	cout<<setw(35)<<"请输入影院的创建时间  :";
	strm.getline(obj.create_time,15);
	return strm;

}    
void cinema::set_name()
{
	cout<<setw(35)<<"请输入影院姓名  : ";
	cin.getline(name,30);
}
void cinema::set_add()
{
	
	cout<<setw(35)<<"请输入影院地址  : ";
	cin.getline(add,50);
}
void cinema::set_tel()
{
      cout<<setw(35)<<"请输入电话  : ";
	  cin.getline(tel,12);
}
void cinema::set_time()
{
         cout<<setw(35)<<"请输入创立时间  : ";
		 cin.getline(create_time,15);
}
void cinema::set_info()
{ 
	char a[100];
	cout<<setw(35)<<"请输入影院基本信息  : ";
	cin.getline(a,1000);
	//info=new char[20];
	strcpy(info,a);
}
void cinema::show_info()
{
	system("cls");
	cout<<endl<<endl<<endl<<endl;
	cout<<"                   影院姓名     : "<<name<<endl<<endl;
	cout<<"                   影院地址     : "<<add<<endl<<endl;
	cout<<"                   影院电话     : "<<tel<<endl<<endl;
	cout<<"                   影院创建时间 :"<<create_time<<endl<<endl;
	cout<<"                   影院基本信息 : "<<info<<endl;
}
void cinema::file_open()
{
	fstream file("cinema.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败"<<endl;
		exit(0);      
	}
	cinema b;
	file.read((char*)&b,sizeof(class cinema));
	b.show_info();
}
