#pragma once
#include<iostream>
using namespace std;
class Box
{
public:
	const static int Boxw = 3;//柜宽
	const static int Boxh = 3;//柜高

private:
	bool box[Boxh * Boxw];
	//long long idbox[Boxh*Boxw];
	int boxId;//快递柜的id
	int postId;//管理人员编号

public:
	Box(int id, int pId);
	int getpostId();
	void setpostId(int a);
	int getFreeBox()const;//寻找空柜子

	void printBox(int index)const;//输出柜子的行和列(xx行xx列可放入)

	void putBox(int index);//box[i]=1

	void checkBox(int index);//box[i]=0

	void printBoxStation();//查询柜使用情况
};