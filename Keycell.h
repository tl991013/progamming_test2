#pragma once
#include<iostream>
#include<map>
#include<ctime>
using namespace std;
extern map<string, bool>keyMap;
class Keycell
{
public:
	Keycell(string k = "", long long g = -1, int b = -1, int in = -1);
	void setRandomKey();
	string getKey();//new
	int getBoxId();//new
	int getGoodsId();
	void sendMessage();
	Keycell* next;
	int index;
protected:
	string key;//√‹¬Î
	long long goodsId;
	int boxId;
};
