# include<iostream.h>
# include"people.h"
# include"film.h"
class worker : public people 
{
protected:
  double work_num;       //Ա����
	char job[10];             //ְ��
	worker *next;
public:
	worker();
	worker(char * name1,char * home_add1);
	void get(char * name1,char * home_add1);
	void get_job();                   //ְ���빤��
	void set_film();                 //���õ�Ӱ��Ϣ
	void change_film();              //�޸ĵ�Ӱ��Ϣ
	void show_self();               //��ʾ��Ϣ
    void change_self();            //�޸��Լ���Ϣ	
	void change1();                //�޸��Լ���Ϣ���Ӻ���
	void change2();                   //ͬ��
	void change3();                   //ͬ��
	void change4();                   //ͬ��
	void change5();                   //ͬ��
	void change6();           
	void change7();
	void change8();                    //ͬ��
	char * show_id();
	char * show_password();
	void set_my_information();
	void set_cinema();
	void change_my_information();
	worker * create();                              //������
	void  print(worker * head);                           //�������
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
