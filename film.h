# include<iostream.h>
# include<stdio.h>
class  film
{
private:
	char  name[20];                //片名
	char director[15];            //导演
	char actor[30];                 //主演
	char type[20];               //电影类型 例：惊悚
	char region[20];                //地区
	char time[12];                 //上映时间
	float time_long;               //时长
	float price;                   //票价
	char synopsis[200];              //剧情简介
	char show_film_time1[10];      //放映时间
	char show_film_time2[10];  
	char show_film_time3[10];  
    int totle_ticket;             //总票数
	int left_ticket1;             //剩余票数
	int left_ticket2;
	int left_ticket3;
	film * next;
public:
	film(){};
	film(char * name,char * actor);       //构造函数   传递 影片名  主演  
//	~film();
	void set_main_actor();                    //设置主演
	void set_main_info();                   //设置     影片信息 （包括 片名 导演 地区 时长 票价）
	void set_name();
	void set_synopsis() ;                  //设置            影片剧情
	void set_show_time();                  //设置放映时间
	void setall();                         //设置票数的子函数 票数相同时
    void seteach();                       //设置票数的子函数   票数不同时                                                
	void set_ticket();                    //设置票数
	void set_film(); 
	void change_film();
	void find_film();
	void change_left_ticket();
	void show_info();
	void find_films();
	void left_ticket_1();                //余票减一
	void left_ticket_2();
	void left_ticket_3();
    void add_left_ticket_1();                //余票加一
	void add_left_ticket_2();
	void add_left_ticket_3();
	int show_ticket1();                  //显示余票
    int show_ticket2();
	int show_ticket3();
	char * show_name();
	char * show_time1(){return show_film_time1;}
	char * show_time2(){return show_film_time2;}
	char * show_time3(){return show_film_time3;}

};
