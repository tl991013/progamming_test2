#pragma once
#include"Person.h"
class Client :public Person//寄件人和收件人类
{
private:
	string address;//地址
	int clintId;//客户的编号

public:
	void setAddress(string str);
	void setClintId(int cId);
	string getAddress()const;
	int getClintId()const;
	Client(string a, string b, string c, string d, int e);
};