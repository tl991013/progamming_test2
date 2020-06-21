#pragma once
#include<iostream>
#include<map>
#include<ctime>
using namespace std;
extern map<string, bool>keyMap;
class Keycell
{
public:
	Keycell(string k = "", long long gId = -1, int bId = -1, int inDex = -1);
	void setRandomKey();
	string getKey();//new
	int getBoxId();//new
	int getGoodsId();
	void sendMessage();
	Keycell* next;
	int index;//快递位置
protected:
	string key;//密码
	long long goodsId;
	int boxId;
};
