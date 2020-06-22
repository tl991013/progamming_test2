#pragma once
#include<iostream>
#include"Keycell.h"
using namespace std;
class Keys
{
	typedef Keycell* keytype;
	typedef Keycell* Head;
private:
public:
	Head head;
	Keys();

	void insertKey(keytype k);//鍦ㄨ〃涓彃鍏ヤ竴涓猭ey
	Keycell findKey(string kkey);//通过key值查找 ,成功后删除 。。。。。。。1546546

	void printKeys()const;//娴嬭瘯鐢�

	void findGoods(long long goodsId)const;//鏍规嵁id瀵绘壘蹇��
};
