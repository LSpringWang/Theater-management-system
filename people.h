# include<iostream.h>
class people
{
protected:
	char   name[20];
	char   id_num[20];
	char   tel[13];
	char   email[20];
	char  home_add[40];
	char password[15];
public:
	people()
	{};
	people(char *name1,char *home_add1);                //构造函数    传递 姓名，住址
   // ~people();
	void get_info();                                    //设置email 电话  身份证
	void get_name();
	void get_passward();                              //设置 密码
	void find_password();
	char * show_id();                             //显示身份证号
	virtual void get_job()=0;                           //虚函数
	virtual void show_self()=0;
};    