#include "PostMan.h"

int PostMan::getPostId() const
{
	return postId;
}

string PostMan::getPosition() const
{
	return position;
}

void PostMan::setPosition(string str)
{
	position = str;
}

void PostMan::setPostId(int pId)
{
	postId = pId;
}

PostMan::PostMan(string a, string b, string c, int d, string e) :Person(a, b, c)
{
	setPostId(d);
	setPosition(e);
}
