# include<iostream.h>
# include<stdlib.h>
# include<fstream.h>
# include<conio.h>
# include<iomanip.h>
# include<string.h>
# include"film.h"
//���캯��  ���� ���� ����
film::film(char * name1,char * actor1)
{
	strcpy(name,name1);
	strcpy(actor,actor1);
}

//��������
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
	cout<<setw(35)<<"������ӰƬ����  :";
	cin.getline(name,20);
}
void film::set_main_info()
{	
	//cin.ignore();
	cout<<setw(35)<<"�����뵼������  :";
	cin.getline(director,15);
    cout<<setw(35)<<"�������Ӱ����  :";
	cin.getline(type,20);
	cout<<setw(35)<<"��Ӱ����  :";
	cin.getline(region,20);
	cout<<setw(35)<<"�������Ӱ��ӳʱ��  :";
	cin.getline(time,12);
	cout<<setw(35)<<"�������Ӱʱ��  :";
	cin>>time_long ;
	cout<<setw(35)<<"Ʊ��  :";
	cin>>price;
	cin.ignore();
}
void film::set_synopsis() 
{
		char a[200];
		cout<<setw(35)<<"�����������   :";
		cin.getline(a,200);
		strcpy(synopsis,a);
}
void film::set_show_time()
{
	cout<<setw(35)<<"�������һ��ӳʱ�䣨���磺12:30pm��  :";
	cin.getline(show_film_time1,10);
	cout<<setw(35)<<"������ڶ���ӳʱ�䣨���磺12:30pm��  :";
	cin.getline(show_film_time2,10);
	cout<<setw(35)<<"�����������ӳʱ�䣨���磺12:30pm��  :";
	cin.getline(show_film_time3,10);
}
void film::setall()
{
	 cout<<setw(35)<<"������ÿ����Ʊ��  :";
     cin>>left_ticket1;
	 left_ticket2=left_ticket1;
     left_ticket3=left_ticket1;
	 totle_ticket=3*left_ticket1;
}
void film::seteach()
{
	cout<<setw(35)<<"�������һ����Ʊ��  :";
	cin>>left_ticket1;
	cout<<setw(35)<<"������ڶ�����Ʊ��  :";
	cin>>left_ticket2;
	cout<<setw(35)<<"�������������Ʊ��  :";
	cin>>left_ticket3;
	totle_ticket=left_ticket1+left_ticket2+left_ticket3;
}
///////////////////////////////////////////////////////////////////////
void film::change_left_ticket()
{
	int a,i;
	for(i=0;a!=4;i++)
	{
		cout<<setw(35)<<"��ѡ�����޸ĵĳ���(1,2,3)����4���� :"<<endl;
		cin>>a;
		if(a==1)
		{
			cout<<setw(35)<<"������ʣ��Ʊ��  :";
			cin>>left_ticket1;
		}
		if(a==2)
		{
			  cout<<setw(35)<<"������ʣ��Ʊ��  :";
			cin>>left_ticket2;
		}
		if(a==3)
		{
			 cout<<setw(35)<<"������ʣ��Ʊ��  :";
			 cin>>left_ticket2;
		}
	}
	
}
void film::set_main_actor()
{
	cout<<setw(35)<<"����������  :";
	cin.getline(actor,30);
}
void film::set_ticket()
{
	int a;
	cout<<setw(35)<<"���ÿ����Ʊ������ͬ��ѡ��1  :"<<endl;
	cout<<setw(35)<<"���ÿ����Ʊ������ͬ��ѡ��2  :";
	cin>>a;
	switch(a)
	{
	case 1 :setall();
	     break;
	case 2 :seteach();
		break;
	}
	   
}
///////////////////////////////////////////////////////////////////////////����ӰƬ��Ϣ
void film::set_film()
{
	film film2;
	system("cls");
	cout<<endl<<endl;
	cout<<setw(40)<<"���ڽ���ӰƬ���  :"<<endl;
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
		cout<<"�Բ���film���ļ���ʧ��";
		exit(0);
	}
	file.write((char*)&film2,sizeof(film2));
	file.close();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(35)<<"��ϲ����ӳɹ�"<<endl<<endl;
	cin.ignore();
	char e;
	cout<<setw(38)<<"���س���������һ���˵�";
	cin.get(e);
}
///////////////////////////////////////////////////////////////////////////�޸�ӰƬ��Ϣ
void film::change_film()
{
	cin.ignore();
	int i,a,j;
	char name[20];
	cout<<setw(28)<<"���������޸ĵ�ӰƬ����  :";
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
		cout<<"                       ************��ѡ��*************       "<<endl;
		cout<<"                       **   1.��Ҫ��Ϣ����          **       "<<endl;
		cout<<"                       **   2.��ӳʱ���޸�          **       "<<endl;
		cout<<"                       **   3.��Ʊ���޸�            **       "<<endl;
		cout<<"                       **   4.ʣ��Ʊ������          **       "<<endl;
		cout<<"                       **   5.������һ���˵�        **       "<<endl;
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
////////////////////////////////////////////////////////////////////����ӰƬ����
void film::find_film()
{  
	int i,b=0;
	fstream file("film.dat",ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"�ļ���ʧ��"<<endl;
		exit(0);
	}
	film film2;
	char name1[20];
	cin.ignore();
	cout<<setw(45)<<"�����������ҵ�ӰƬ����:";
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
		cout<<setw(35)<<"�Բ���û����Ҫ�ҵ�ӰƬ"<<endl;
	}
		cout<<endl<<endl;
	cout<<setw(50)<<"���س���������һ���˵�:";
	char a;
	cin.get(a);
	file.close();
}
/////////////////////////////////////////////////////��ʾӰƬ��Ϣ
void film::show_info()
{
	cout<<endl<<endl;
	cout<<setw(40)<<"           ӰƬ����  :";
	cout<<name<<endl;
	cout<<endl;
	cout<<setw(40)<<"          ����      :";
	cout<<director<<endl;
	cout<<setw(40)<<"          ��Ӱ����  :";
	cout<<type<<endl;
	cout<<setw(40)<<"          ����      :";
	cout<<actor<<endl;
	cout<<setw(40)<<"          ��������  :";
	cout<<region<<endl;
	cout<<setw(40)<<"          ��ӳʱ��  :";
	cout<<time<<endl;
	cout<<setw(40)<<"          ��Ӱʱ��  :";
	cout<<time_long<<endl;
	cout<<setw(40)<<"          Ʊ��      :";
	cout<<price<<endl;
	cout<<setw(40)<<"          ��ӳʱ��  :"<<endl<<endl<<endl;
	cout<<setw(40)<<"          ��һ��    :";
	cout<<show_film_time1<<endl;
	cout<<setw(40)<<"          ʣ��Ʊ��  :";
	cout<<left_ticket1<<endl;
	cout<<setw(40)<<"          �ڶ���    :";
	cout<<show_film_time2<<endl;;
	cout<<setw(40)<<"          ʣ��Ʊ��  :";
	cout<<left_ticket2<<endl;
	cout<<setw(40)<<"          ������    :";
	cout<<show_film_time3<<endl;;
	cout<<setw(40)<<"          ʣ��Ʊ��  :";
	cout<<left_ticket3<<endl;
	cout<<setw(40)<<"          ������  :";
	cout<<synopsis<<endl;
}
/////////////////////////////////////////////////////////ȫ��ӰƬ��ѯ
void film::find_films()
{
	int i;
	film film1;
	fstream file("film.dat",ios::in|ios::binary);
	if(file.fail())
	{
		cout<<"�ļ���ʧ��";
		exit(0);
	}
	file.read((char*)&film1,sizeof(film));
	for(i=0;!file.eof();i++)
	{
		system("cls");
		film1.show_info();
		file.read((char*)&film1,sizeof(film));
		cout<<"�������������ʾ"<<endl;
		getch();
	}
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                ***************************************"<<endl;
	cout<<"                *����Ϊ����ӰԺ�����ȫ��ӰƬ,��ӭ�ۿ�*"<<endl;
	cout<<"                ***************************************"<<endl;
	cout<<endl;
	cout<<"                         ������һ���˵��������          "<<endl;
	getch();
	file.close();

}
/////////////////////////////////////////��Ʊ��һ
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
/////////////////////////////////////////��Ʊ��һ
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

