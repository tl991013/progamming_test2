#include "Goods.h"

void Goods::setpName(string str)
{
	pId = str;
}

void Goods::setrName(string str)
{
	rId = str;
}

void Goods::setStation(int s)
{
	station = s;
}

void Goods::setPuttime()
{
	time_t seconds;
	seconds = time(NULL);
	putTime = seconds;
}

void Goods::setChecktime()
{
	time_t seconds;
	seconds = time(NULL);
	checkTime = seconds;
}

void Goods::setGoodsId(long long a)
{
	goodsId = a;
}

string Goods::getpName() const
{
	return pId;
}

string Goods::getrName() const
{
	return rId;
}

int Goods::getStation() const
{
	return station;
}

long long Goods::getPuttime() const
{
	return putTime;
}

long long Goods::getChecktime() const
{
	return checkTime;
}

long long Goods::getGoodsId() const
{
	return goodsId;
}

Goods::Goods(string a, string b, int c, long long d) :putTime(0), checkTime(0)
{
	setpName(a);
	setrName(b);
	setStation(c);
	setGoodsId(d);
}