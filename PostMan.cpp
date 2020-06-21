#include "PostMan.h"

int PostMan::getPostId() const
{
	return postId;
}

string PostMan::getPosition() const
{
	return position;
}

string PostMan::getPassWord()const
{
	return passWord;
}

void PostMan::setPassWord(string str)
{
	passWord = str;
}

void PostMan::setPosition(string str)
{
	position = str;
}

void PostMan::setPostId(int pId)
{
	postId = pId;
}

PostMan::PostMan(string a, string b, string c, int d, string e, string f) :Person(a, b, c)
{
	setPostId(d);
	setPosition(e);
	setPassWord(f);
}