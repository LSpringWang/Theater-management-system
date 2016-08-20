# include<iostream.h>
# include"people.h"
# include"film.h"
class worker : public people 
{
protected:
  double work_num;       //员工号
	char job[10];             //职务
	worker *next;
public:
	worker();
	worker(char * name1,char * home_add1);
	void get(char * name1,char * home_add1);
	void get_job();                   //职务与工号
	void set_film();                 //设置电影信息
	void change_film();              //修改电影信息
	void show_self();               //显示信息
    void change_self();            //修改自己信息	
	void change1();                //修改自己信息的子函数
	void change2();                   //同上
	void change3();                   //同上
	void change4();                   //同上
	void change5();                   //同上
	void change6();           
	void change7();
	void change8();                    //同上
	char * show_id();
	char * show_password();
	void set_my_information();
	void set_cinema();
	void change_my_information();
	worker * create();                              //链表建立
	void  print(worker * head);                           //链表输出
	void del(worker *head,double num);
	char * show_name()
	{
		return name;
	}
	double show_work_num()
	{
		return work_num;
	}
   
	
};
