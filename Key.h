#pragma once
#include<iostream>
#include"Keycell.h"
using namespace std;
class Keys
{
	typedef Keycell* keytype;
	typedef Keycell* Head;
private:
	Head head;

public:
	Keys();

	void insertKey(keytype k);//在表中插入一个key

	Keycell findKey(string kkey);//通过key值查找 ,成功后删除

	void printKeys()const;//测试用

	void findGoods(long long goodsId)const;//根据id寻找快递
};