# include<iostream.h>
# include"worker.h"
class administrator:public worker
{
public:
	administrator(char * name1,char * home_add1);
	administrator();
	void find_password();
	void ad_staff();
	void add_staff();                      
	void find_staff();                    //查找员工信息
	void del_staff();                     //删除员工信息
	void set_information();               //增加员工信息
	void set_my_information();             //修改自己信息
	void add_administrator();
	void show_admion();                   //显示自己信息
};