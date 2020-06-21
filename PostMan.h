#pragma once
#include"Person.h"
class PostMan :public Person//邮递员类
{
private:
	int postId;//工号
	string position;//职位
	string passWord;//密码
public:

	int getPostId()const;
	string getPosition()const;
	string getPassWord()const;
	void setPassWord(string str);
	void setPosition(string str);
	void setPostId(int pId);
	PostMan(string a = "", string b = "", string c = "", int d = -1, string e = "", string f = "");
};