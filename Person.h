#pragma once
#include<iostream>
using namespace std;
class Person//人类，包括人的基本信息
{
private:
	string id;// 身份证号
	string tel;// 电话
	string name;// 姓名
public:
	string getId()const;
	string getTel()const;
	string getName()const;
	void setId(string str);
	void setTel(string str);
	void setName(string str);
	Person(string a = "", string b = "", string c = "");
};