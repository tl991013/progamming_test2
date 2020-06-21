#include "Person.h"

string Person::getId() const
{
	return id;
}

string Person::getTel() const
{
	return tel;
}

string Person::getName() const
{
	return name;
}
void Person::setId(string str)
{
	id = str;
}

void Person::setTel(string str)
{
	tel = str;
}

void Person::setName(string str)
{
	name = str;
}

Person::Person(string a, string b, string c)
{
	setId(a);
	setTel(b);
	setName(c);
}