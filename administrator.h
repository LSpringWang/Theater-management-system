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
	void find_staff();                    //����Ա����Ϣ
	void del_staff();                     //ɾ��Ա����Ϣ
	void set_information();               //����Ա����Ϣ
	void set_my_information();             //�޸��Լ���Ϣ
	void add_administrator();
	void show_admion();                   //��ʾ�Լ���Ϣ
};