#pragma once
#include<iostream>
#include <time.h>
using namespace std;
class Goods
{
private:
	string pName;//寄件人名字
	string rName;//收件人名字
	int station;//状态 0：派送中 1：在柜中 2：已取出
	long long putTime;//放入时间 ,0:未放入  非0：从1970/1/1开始的秒数
	long long checkTime;//取出时间
	long long goodsId;//快递id

public:
	Goods(string a = "", string b = "", int c = 0, long long d = -1);

	void setpName(string str);
	void setrName(string str);
	void setStation(int s);
	void setPuttime();
	void setChecktime();
	void setGoodsId(long long a);

	string getpName()const;
	string getrName()const;
	int getStation()const;
	long long getPuttime()const;
	long long getChecktime()const;
	long long getGoodsId()const;

	void putGoods()
	{
		setPuttime();
		setStation(1);
	}
	void checkGoods()
	{
		setChecktime();
		setStation(2);
	}
};