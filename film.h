# include<iostream.h>
# include<stdio.h>
class  film
{
private:
	char  name[20];                //Ƭ��
	char director[15];            //����
	char actor[30];                 //����
	char type[20];               //��Ӱ���� �������
	char region[20];                //����
	char time[12];                 //��ӳʱ��
	float time_long;               //ʱ��
	float price;                   //Ʊ��
	char synopsis[200];              //������
	char show_film_time1[10];      //��ӳʱ��
	char show_film_time2[10];  
	char show_film_time3[10];  
    int totle_ticket;             //��Ʊ��
	int left_ticket1;             //ʣ��Ʊ��
	int left_ticket2;
	int left_ticket3;
	film * next;
public:
	film(){};
	film(char * name,char * actor);       //���캯��   ���� ӰƬ��  ����  
//	~film();
	void set_main_actor();                    //��������
	void set_main_info();                   //����     ӰƬ��Ϣ ������ Ƭ�� ���� ���� ʱ�� Ʊ�ۣ�
	void set_name();
	void set_synopsis() ;                  //����            ӰƬ����
	void set_show_time();                  //���÷�ӳʱ��
	void setall();                         //����Ʊ�����Ӻ��� Ʊ����ͬʱ
    void seteach();                       //����Ʊ�����Ӻ���   Ʊ����ͬʱ                                                
	void set_ticket();                    //����Ʊ��
	void set_film(); 
	void change_film();
	void find_film();
	void change_left_ticket();
	void show_info();
	void find_films();
	void left_ticket_1();                //��Ʊ��һ
	void left_ticket_2();
	void left_ticket_3();
    void add_left_ticket_1();                //��Ʊ��һ
	void add_left_ticket_2();
	void add_left_ticket_3();
	int show_ticket1();                  //��ʾ��Ʊ
    int show_ticket2();
	int show_ticket3();
	char * show_name();
	char * show_time1(){return show_film_time1;}
	char * show_time2(){return show_film_time2;}
	char * show_time3(){return show_film_time3;}

};
