#include "Client.h"

void Client::setAddress(string str)
{
	address = str;
}

void Client::setClintId(int cId)
{
	clintId = cId;
}

string Client::getAddress() const
{
	return address;
}

int Client::getClintId() const
{
	return clintId;
}

Client::Client(string a, string b, string c, string d, int e) :Person(a, b, c)
{
	setAddress(d);
	setClintId(e);
}