# include<iostream.h>
# include<iomanip.h>
# include"administrator.h"
class customer:public people
{
private:
	char have_book[20];
	char book_film_time1[10];    //���ڴ�Ź���ĳ��ε�ʱ��
	int b;                       //���ڴ�Ź���ĳ���
	customer *next;
public:
	void get_b(int a);       //����b
	void get_time(char *a);
	void get_job(){};                           //�麯��
	void show_self();                     //��ʾ�Լ���Ϣ
	void show_have_book();
	void vip_mem();                      //    vip ����
	void find_film();                     //���ҵ�Ӱ
	void vip_book();                    //��Ա��Ʊ
	void vip_unbook();                   //��Ʊ����
	void set_have_book(char *p);            //�����Ѷ��ĵ�Ӱ
	void change_self();
	void regist();                       //ע���Ա
	void order();                 // ��Ʊ
	void get_add();
	void get_book_1();          //Ĭ�ϵĸ�ֵ
	customer * create();                              //������
	void del(customer *head,char*id);
	void look_all();
	void  show_name()
	{ 
		cout<<setw(35)<<"����  :"<<name<<endl;
	}
	char *showname()
	{return name;}
	char *showpassword()
	{return password;}
	void show_b(){cout<<setw(35)<<"��������  :"<<b<<endl;}
	void show_book_time1(){cout<<setw(35)<<"ʱ��  :"<<book_film_time1<<endl;}
};
