# include<iostream.h>
# include<iomanip.h>
# include"administrator.h"
class customer:public people
{
private:
	char have_book[20];
	char book_film_time1[10];    //用于存放购买的场次的时间
	int b;                       //用于存放购买的场次
	customer *next;
public:
	void get_b(int a);       //设置b
	void get_time(char *a);
	void get_job(){};                           //虚函数
	void show_self();                     //显示自己信息
	void show_have_book();
	void vip_mem();                      //    vip 窗口
	void find_film();                     //查找电影
	void vip_book();                    //会员订票
	void vip_unbook();                   //退票函数
	void set_have_book(char *p);            //设置已定的电影
	void change_self();
	void regist();                       //注册会员
	void order();                 // 购票
	void get_add();
	void get_book_1();          //默认的赋值
	customer * create();                              //链表建立
	void del(customer *head,char*id);
	void look_all();
	void  show_name()
	{ 
		cout<<setw(35)<<"姓名  :"<<name<<endl;
	}
	char *showname()
	{return name;}
	char *showpassword()
	{return password;}
	void show_b(){cout<<setw(35)<<"订购场次  :"<<b<<endl;}
	void show_book_time1(){cout<<setw(35)<<"时间  :"<<book_film_time1<<endl;}
};
