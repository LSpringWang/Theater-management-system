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
	people(char *name1,char *home_add1);                //���캯��    ���� ������סַ
   // ~people();
	void get_info();                                    //����email �绰  ���֤
	void get_name();
	void get_passward();                              //���� ����
	void find_password();
	char * show_id();                             //��ʾ���֤��
	virtual void get_job()=0;                           //�麯��
	virtual void show_self()=0;
};    