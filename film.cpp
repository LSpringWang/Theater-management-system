# include<iostream.h>
# include<stdlib.h>
# include<fstream.h>
# include<conio.h>
# include<iomanip.h>
# include<string.h>
# include"film.h"
//构造函数  传递 姓名 主演
film::film(char * name1,char * actor1)
{
	strcpy(name,name1);
	strcpy(actor,actor1);
}

//析构函数
/*film::~film()
{
	delete []name;
	delete []actor;
}*/

//
void film::set_name()
{
	//system("cls");
	cin.ignore ();
	cout<<endl<<endl<<endl;
	cout<<setw(35)<<"请输入影片姓名  :";
	cin.getline(name,20);
}
void film::set_main_info()
{	
	//cin.ignore();
	cout<<setw(35)<<"请输入导演姓名  :";
	cin.getline(director,15);
    cout<<setw(35)<<"请输入电影类型  :";
	cin.getline(type,20);
	cout<<setw(35)<<"电影地区  :";
	cin.getline(region,20);
	cout<<setw(35)<<"请输入电影上映时间  :";
	cin.getline(time,12);
	cout<<setw(35)<<"请输入电影时长  :";
	cin>>time_long ;
	cout<<setw(35)<<"票价  :";
	cin>>price;
	cin.ignore();
}
void film::set_synopsis() 
{
		char a[200];
		cout<<setw(35)<<"请输入剧情简介   :";
		cin.getline(a,200);
		strcpy(synopsis,a);
}
void film::set_show_time()
{
	cout<<setw(35)<<"请输入第一放映时间（例如：12:30pm）  :";
	cin.getline(show_film_time1,10);
	cout<<setw(35)<<"请输入第二放映时间（例如：12:30pm）  :";
	cin.getline(show_film_time2,10);
	cout<<setw(35)<<"请输入第三放映时间（例如：12:30pm）  :";
	cin.getline(show_film_time3,10);
}
void film::setall()
{
	 cout<<setw(35)<<"请输入每场的票数  :";
     cin>>left_ticket1;
	 left_ticket2=left_ticket1;
     left_ticket3=left_ticket1;
	 totle_ticket=3*left_ticket1;
}
void film::seteach()
{
	cout<<setw(35)<<"请输入第一场的票数  :";
	cin>>left_ticket1;
	cout<<setw(35)<<"请输入第二场的票数  :";
	cin>>left_ticket2;
	cout<<setw(35)<<"请输入第三场的票数  :";
	cin>>left_ticket3;
	totle_ticket=left_ticket1+left_ticket2+left_ticket3;
}
///////////////////////////////////////////////////////////////////////
void film::change_left_ticket()
{
	int a,i;
	for(i=0;a!=4;i++)
	{
		cout<<setw(35)<<"请选择欲修改的场次(1,2,3)，按4返回 :"<<endl;
		cin>>a;
		if(a==1)
		{
			cout<<setw(35)<<"请输入剩余票数  :";
			cin>>left_ticket1;
		}
		if(a==2)
		{
			  cout<<setw(35)<<"请输入剩余票数  :";
			cin>>left_ticket2;
		}
		if(a==3)
		{
			 cout<<setw(35)<<"请输入剩余票数  :";
			 cin>>left_ticket2;
		}
	}
	
}
void film::set_main_actor()
{
	cout<<setw(35)<<"请输入主演  :";
	cin.getline(actor,30);
}
void film::set_ticket()
{
	int a;
	cout<<setw(35)<<"如果每场的票总数相同请选择1  :"<<endl;
	cout<<setw(35)<<"如果每场的票总数不同请选择2  :";
	cin>>a;
	switch(a)
	{
	case 1 :setall();
	     break;
	case 2 :seteach();
		break;
	}
	   
}
///////////////////////////////////////////////////////////////////////////设置影片信息
void film::set_film()
{
	film film2;
	system("cls");
	cout<<endl<<endl;
	cout<<setw(40)<<"正在进行影片添加  :"<<endl;
	film2.set_name();
	film2.set_main_actor();
	film2.set_main_info ();
	film2.set_show_time ();
	film2.set_synopsis ();
	film2.set_ticket ();
	fstream file;
	file.open("film.dat",ios::app|ios::binary);
	if(file.fail())
	{
		cout<<"对不起“film”文件打开失败";
		exit(0);
	}
	file.write((char*)&film2,sizeof(film2));
	file.close();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(35)<<"恭喜你添加成功"<<endl<<endl;
	cin.ignore();
	char e;
	cout<<setw(38)<<"按回车键返回上一级菜单";
	cin.get(e);
}
///////////////////////////////////////////////////////////////////////////修改影片信息
void film::change_film()
{
	cin.ignore();
	int i,a,j;
	char name[20];
	cout<<setw(28)<<"请输入欲修改的影片姓名  :";
	cin.getline(name,20);
	film film1;
	fstream file("film.dat",ios::in|ios::out|ios::binary);
	for(i=0;;i++)
	{
		file.read((char *)&film1,sizeof(film));
		if(strcmp(film1.name,name)==0)
		{
			break;
		}
	}
	for(j=0;a!=5;j++)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************请选择*************       "<<endl;
		cout<<"                       **   1.主要信息更改          **       "<<endl;
		cout<<"                       **   2.放映时间修改          **       "<<endl;
		cout<<"                       **   3.主票量修改            **       "<<endl;
		cout<<"                       **   4.剩余票量设置          **       "<<endl;
		cout<<"                       **   5.返回上一级菜单        **       "<<endl;
		cout<<"                       *******************************       "<<endl;
		cin>>a;
		switch(a)
		{
			case 1:
				{
				film1.set_main_info();
				break;
				}
			case 2:
				{
				film1.set_show_time();
				break;
				}
			case 3:
				{
				film1.set_ticket();
				break;
				}
			case 4:
				{
				film1.change_left_ticket();
				break;
				}
			case 5:
				break;
		}
	}
	file.seekg(-(sizeof(film1)),ios::cur);
	file.write((char*)&film1,sizeof(film1));
	file.close();
}
////////////////////////////////////////////////////////////////////单个影片查找
void film::find_film()
{  
	int i,b=0;
	fstream file("film.dat",ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败"<<endl;
		exit(0);
	}
	film film2;
	char name1[20];
	cin.ignore();
	cout<<setw(45)<<"请输入欲查找的影片姓名:";
	cin.getline(name1,20);
	file.read((char*)&film2,sizeof(film));
	for(i=0;!file.eof();i++)
	{
		if(strcmp(film2.name,name1)==0)
		{
			system("cls");
			cout<<"  "<<endl;
			film2.show_info();
			b=1;
            
		}
		file.read((char*)&film2,sizeof(film));
	}
	if(b==0)
	{
		system("cls");
        cout<<endl<<endl<<endl<<endl<<endl;
		cout<<setw(35)<<"对不起，没有您要找的影片"<<endl;
	}
		cout<<endl<<endl;
	cout<<setw(50)<<"按回车键返回上一级菜单:";
	char a;
	cin.get(a);
	file.close();
}
/////////////////////////////////////////////////////显示影片信息
void film::show_info()
{
	cout<<endl<<endl;
	cout<<setw(40)<<"           影片姓名  :";
	cout<<name<<endl;
	cout<<endl;
	cout<<setw(40)<<"          导演      :";
	cout<<director<<endl;
	cout<<setw(40)<<"          电影类型  :";
	cout<<type<<endl;
	cout<<setw(40)<<"          主演      :";
	cout<<actor<<endl;
	cout<<setw(40)<<"          所属地区  :";
	cout<<region<<endl;
	cout<<setw(40)<<"          上映时间  :";
	cout<<time<<endl;
	cout<<setw(40)<<"          电影时长  :";
	cout<<time_long<<endl;
	cout<<setw(40)<<"          票价      :";
	cout<<price<<endl;
	cout<<setw(40)<<"          放映时间  :"<<endl<<endl<<endl;
	cout<<setw(40)<<"          第一场    :";
	cout<<show_film_time1<<endl;
	cout<<setw(40)<<"          剩余票数  :";
	cout<<left_ticket1<<endl;
	cout<<setw(40)<<"          第二场    :";
	cout<<show_film_time2<<endl;;
	cout<<setw(40)<<"          剩余票数  :";
	cout<<left_ticket2<<endl;
	cout<<setw(40)<<"          第三场    :";
	cout<<show_film_time3<<endl;;
	cout<<setw(40)<<"          剩余票数  :";
	cout<<left_ticket3<<endl;
	cout<<setw(40)<<"          剧情简介  :";
	cout<<synopsis<<endl;
}
/////////////////////////////////////////////////////////全部影片查询
void film::find_films()
{
	int i;
	film film1;
	fstream file("film.dat",ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"文件打开失败";
		exit(0);
	}
	file.read((char*)&film1,sizeof(film));
	for(i=0;!file.eof();i++)
	{
		system("cls");
		film1.show_info();
		file.read((char*)&film1,sizeof(film));
		cout<<"按任意键继续显示"<<endl;
		getch();
	}
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                ***************************************"<<endl;
	cout<<"                *以上为我们影院最近的全部影片,欢迎观看*"<<endl;
	cout<<"                ***************************************"<<endl;
	cout<<endl;
	cout<<"                         返回上一级菜单按任意键          "<<endl;
	getch();
	file.close();

}
/////////////////////////////////////////余票减一
void film::left_ticket_1()
{
	left_ticket1--;
}
void film::left_ticket_2()
{
	left_ticket2--;
}
void film::left_ticket_3()
{
	left_ticket3--;
}
/////////////////////////////////////////余票加一
void film::add_left_ticket_1()
{
	left_ticket1++;

}               
void film::add_left_ticket_2()
{
     left_ticket2++;
}
void film::add_left_ticket_3()
{
     left_ticket3++;
}
int film::show_ticket1()
{
   return left_ticket1;   
}
int film::show_ticket2()
{
   return left_ticket2;
}
int film::show_ticket3()
{
   return left_ticket3;
}
char * film::show_name()
{
	return name;
}

