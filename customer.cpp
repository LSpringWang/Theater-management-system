# include"customer.h"
//# include"film.h"
# include<fstream.h>
# include<string.h>
# include<iomanip.h>
# include<conio.h>
# include<stdlib.h>
///////////////////���ù�Ʊ�ĳ���
void customer::get_b(int a)
{
       b=a;
}
//////////////////////////////////////////////��ʾ�Լ���Ϣ
void customer::show_self()
{
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<setw(45)<<"������Ϣ��ʾ���� :"<<endl<<endl;
	cout<<setw(40)<<"����  :";
	cout<<name<<endl;
	cout<<setw(40)<<"���֤��  :";
	cout<<id_num<<endl;
	cout<<setw(40)<<"�绰  :";
	cout<<tel<<endl;
	cout<<setw(40)<<"�����ʼ�  :";
	cout<<email<<endl;
	cout<<setw(40)<<"��ͥסַ  :";
	cout<<home_add<<endl;
}
void customer::show_have_book()
{
	cout<<setw(35)<<"�Ѷ����ĵ�Ӱ  :";
	cout<<have_book<<endl;
}
void customer::vip_mem()
{
	int a;
	for(;a!=5;)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                       ************��ѡ��*************       "<<endl;
		cout<<"                       **   1.�鿴�Լ���Ϣ          **       "<<endl;
		cout<<"                       **   2.�޸��Լ���Ϣ          **       "<<endl;
		cout<<"                       **   3.�鿴ӰƬ��Ϣ          **       "<<endl;
		cout<<"                       **   4.��Ʊ                  **       "<<endl;
		cout<<"                       **   5.������һ���˵�        **       "<<endl;
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
					cout<<"�ļ���ʧ��";
					exit(0);
				}
				char num[20];
				cin.ignore();
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(28)<<"���������֤��:";
				cin.getline(num,20);
				file.read((char*)&customer1,sizeof(customer));
				for(i=0;!file.eof();i++)
				{
					if(strcmp(customer1.show_id(),num)==0)
					{
						customer1.show_self();
						customer1.show_have_book();
						cout<<endl<<endl;
						cout<<"                          �����س���������һ���˵���";
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
		cout<<"                       ************��ѡ��*************       "<<endl;
		cout<<"                       **       1.��Ƭ����ѯ                 "<<endl;
		cout<<"                       **       2.ӰԺȫ����ӳӰƬ��ѯ       "<<endl;
		cout<<"                       **       3.������һ���˵�             "<<endl;
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
/////////////////////////////////////     ����һ��Ʊ��ʱ��
void customer::get_time(char *a)
{
	strcpy(book_film_time1,a);

}
////////////////////////////////////////////////     vip��Ʊ
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
    cout<<"                ����������Ʊ�ĵ�Ӱ���� :";
	cin.getline(name,20);
	cout<<"                ������������ĳ���     :";
	cin>>b;
	fstream file("film.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"film�ļ���ʧ��"<<endl;
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
				cout<<setw(30)<<"�Բ���˵�ӰƱ������";
			}
			else
			   film1.left_ticket_1();                       //��Ʊ��һ
		}
		if(b==2)
		{
			if(film1.show_ticket2()==0)
			{
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(30)<<"�Բ���˵�ӰƱ������";
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
				cout<<setw(30)<<"�Բ���˵�ӰƱ������";
			}
			else
			   film1.left_ticket_3();
		}
		file.seekg(-sizeof(film),ios::cur);
		file.write((char*)&film1,sizeof(film));
		file.close();
		///////////////////////////////////////////////////////vip��Ա��Ϣ���Ķ�Ʊ�����ļ��и���
		char num[20];
		cout<<endl<<endl;
		cin.ignore();
		cout<<setw(35)<<"������������֤��  :";
		cin.getline(num,20);
		fstream file1("vip_customer.dat",ios::in|ios::out|ios::binary);
		fstream file2("order_people.dat",ios::in|ios::out|ios::binary);
		if(file1.fail())
		{
			cout<<"vip_customer�ļ���ʧ��";
			exit(0);
		}
		if(file2.fail())
		{
			cout<<"order_people�ļ���ʧ��";
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
		customer1.set_have_book(name);                       ////���ö����ߵ�ӰƬʱ��
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
		cout<<"                          ��ϲ�㶩Ʊ�ɹ�"<<endl;
		char e;
		cout<<"                     ������س���������һ���˵�";
		cin.get(e);
	}
	else
	{
		cout<<"               �Բ���û�д�ӰƬ    "<<endl;
	    cout<<"                �س���������         "<<endl;
	    char e;
	    cin.get(e);
	}
}

void customer::get_book_1()
{
	strcpy(have_book,"����ʱû�ж���ӰƱ");
}
/////////////////////////////////////////////////////////////�޸��Լ�����Ϣ
void customer::change_self()
{
	char a[20];
	int b, i;
	customer customer1; 
	fstream file("vip_customer.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"�ļ���ʧ��";
		exit(0);
	}
	cout<<setw(35)<<"���������֤��  :";
	cin.getline(a,20);
	file.read((char *)&customer1,sizeof(customer));
	for(i=0;!file.eof();i++)
	{
		if(strcmp(customer1.show_id(),a)==0)
		{
			customer customer2=customer1;
			system("cls");
		    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		    cout<<"                       ************��ѡ��*******************   "<<endl;
			cout<<"                       **      1.�޸�����                 **   "<<endl;
			cout<<"                       **      2.�޸ļ�ͥסַ             **   "<<endl;
			cout<<"                       **      3.�޸ĵ绰�����֤��,����  **   "<<endl;
			cout<<"                       **      4.�޸�����                 **   "<<endl;
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
			cout<<setw(35)<<"��ϲ�����޸ĳɹ�"<<endl;
			break;
		}
		file.read((char *)&customer1,sizeof(customer));
	}
	if(file.eof())
	{
		cout<<endl<<endl;
		cout<<setw(30)<<"�Բ���û�д���"<<endl;
	}
	cout<<endl<<endl;
	cout<<setw(30)<<"�����������"<<endl;
	getch();
}

//////////////////////////////////////////////ע���Ա
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
		cout<<"�ļ���ʧ��";
		exit(0);
	} 
	file.write((char*)&customer2,sizeof(customer));
	file.close();
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                             ��ϲ�㣬��Աע��ɹ�"<<endl<<endl;
	cout<<"                      ����������Ʊ���뷵�ػ�Ա��Ʊ����"<<endl;
	cout<<"                              �����������"<<endl;
	getch();
}
////////////////////////////////////////////////////////////////////
void customer::get_add()
{
	//cin.ignore();
	cout<<setw(35)<<"�������ַ  :";
	cin.getline(home_add,40);
}
////////////////////////////////////////////////��Ʊ
void customer::order()
{
	int i,b;
	char name[20];
	film film1;
	cin.ignore();
	system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<setw(30)<<"����������Ʊ�ĵ�Ӱ����  :";
	cin.getline(name,20);
	cout<<setw(30)<<"������������ĳ���  :";
	cin>>b;
	fstream file("film.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"film�ļ���ʧ��"<<endl;
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
		cout<<setw(35)<<"�Բ���û����Ҫ�ҵ�ӰƬ"<<endl;
	}
	else
	{
		if(b==1)
		{
			if(film1.show_ticket1()==0)
			{
				system("cls");
		        cout<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(30)<<"�Բ���˵�ӰƱ������";
			}
			else
			   film1.left_ticket_1();                       //��Ʊ��һ
		}
		if(b==2)
		{
			if(film1.show_ticket2()==0)
				{
				system("cls");
		        cout<<endl<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(30)<<"�Բ���˵�ӰƱ������";
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
				cout<<setw(30)<<"�Բ���˵�ӰƱ������";
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
			cout<<"order_people�ļ���ʧ��";
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
		cout<<setw(30)<<"��ϲ�㣬��Ʊ�ɹ�"<<endl;
	}
	cout<<endl;
	cout<<setw(34)<<"�������������һ���˵�"<<endl;
	getch();
}
//////////////////////////////////////////////////////////��Ʊ
void customer::vip_unbook()
{
	char id[20];
	int b=0;
    customer customer1;
	customer customer2;
	fstream file("order_people.dat",ios::in|ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"order_people�ļ���ʧ��";
		exit(0);
	}
	cin.ignore();
	cout<<endl;
	cout<<setw(35)<<"���������֤��  :";
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
		cout<<setw(30)<<"�Բ���û�����Ķ�Ʊ��Ϣ";
	}
	fstream file1("vip_customer.dat",ios::in|ios::out|ios::binary);
	if(file1.fail())
	{
		cout<<"�ļ���ʧ��";
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
		cout<<"film�ļ���ʧ��"<<endl;
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
		cout<<"customer�ļ���ʧ��";
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
		cout<<setw(38)<<"���س�������"<<endl;
		cin.get(e);
		//cout<<endl;
	}
	cout<<endl<<endl;
	cout<<setw(38)<<"����Ϊȫ���Ķ�Ʊ��Ա"<<endl;
	cout<<setw(35)<<"�����������";
	cin.get(e);
	file.close();
}

//////////////////////////////////////////////////////////////////////////////////////////����
///////////////////////����Ľ���
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
/////////////////////////////////////////////�����ɾ��
void customer::del(customer *head,char*id)
{
	fstream file("order_people.dat",ios::out|ios::binary);
	if(file.fail())
	{
		cout<<"�ļ���ʧ��";
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
