# include<iostream.h>
class cinema
{
private:
	char  name[30];
	char add[50];
	char tel[12];
	char create_time[15];
	char info[100];
public:
	friend istream &operator >>(istream &strm,cinema &obj );
	void set_name();
	void set_add();
	void set_tel();
	void set_time();
	void set_info();
	void show_info();
	void file_open();
                                                                                                                                                                                                                                                                                                                       
};