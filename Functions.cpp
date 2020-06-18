#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Functions.h"
using namespace std;
PostMan* postman[100];
Client* client[100];
Goods* goods[100];
Box* box[100];
Keys keys;
void initial()
{
	FILE* fp;
	if (fp = fopen("D:\\test.txt", "w"))
	{
		cout << "打开文件成功" << endl;
		fputs("hello", fp);
		fclose(fp);
	}
	else
		cout << "打开文件失败" << endl;
	postman[0] = new PostMan("123451", "110", "PostmanA", 0, "worker");
	postman[1] = new PostMan("123452", "111", "PostmanB", 1, "manager");


	client[0] = new Client("123453", "119", "ClientC", "翻斗花园", 0);
	client[1] = new Client("123454", "120", "ClientD", "龙华美食街", 1);
	client[2] = new Client("123454", "121", "ClientE", "南京工业大学", 2);

	goods[0] = new Goods("3", "4", 0, 0);
	goods[1] = new Goods("4", "5", 0, 1);
	goods[2] = new Goods("5", "3", 1, 2);
	goods[3] = new Goods("4", "3", 2, 3);

	box[0] = new Box(1, 2);
	box[1] = new Box(2, 2);

	keys.insertKey(new Keycell("111111", 3, 0, 0));
	keys.insertKey(new Keycell("123456", 2, 1, 0));
	goods[3]->setPuttime();
	goods[3]->putGoods();
	box[0]->putBox(0);
}

void Put()
{
	//输入用户名和密码，略
	int boxId;
	int freeIndex;
	long long goodsId;
	cout << "输入当前快递柜编号" << endl;
	cin >> boxId;
	if (boxId > 1 || boxId < 0)
	{
		cout << "输入错误" << endl;
		return;
	}
	freeIndex = box[boxId]->getFreeBox();
	if (freeIndex == -1)
	{
		cout << "此柜已满，请换一个" << endl;
		return;
	}
	box[boxId]->printBox(freeIndex);
	cout << "请输入要放入的快递编号" << endl;
	cin >> goodsId;
	if (goodsId < 0 || goodsId>3)
	{
		cout << "不存在此快递，请重新输入" << endl;
		return;
	}
	if (goods[goodsId]->getStation() != 0)
	{
		cout << "此快递已放入或已取出，请重新输入" << endl;
		return;
	}
	goods[goodsId]->putGoods();
	box[boxId]->putBox(freeIndex);
	Keycell* temp = new Keycell("", goodsId, boxId, freeIndex);
	temp->setRandomKey();
	keys.insertKey(temp);
	cout << "已成功存入" << endl;
	temp->sendMessage();

	return;

}

void Check()
{

	string key;
	Keycell temp;
	cout << "请输入密码" << endl;
	cin >> key;
	temp = keys.findKey(key);
	if (temp.getKey() == "")
	{
		cout << "输入错误，不存在此密码，请检查是否输入错误" << endl;
		return;
	}
	box[temp.getBoxId()]->checkBox(temp.index);
	goods[temp.getGoodsId()]->checkGoods();
	cout << "取件成功" << endl;

}

void checkBox()
{
	int boxId;
	cout << "输入当前快递柜编号" << endl;
	cin >> boxId;
	if (boxId > 1 || boxId < 0)
	{
		cout << "输入错误" << endl;
		return;
	}
	cout << "快递柜使用情况如下" << endl;
	box[boxId]->printBoxStation();
	return;
}

void checkGoods()
{
	int goodsId;
	cout << "请输入快递编号" << endl;
	cin >> goodsId;
	if (goodsId < 0 || goodsId>3)
	{
		cout << "不存在此快递，请重新输入" << endl;
		return;
	}
	if (goods[goodsId]->getStation() == 2)
	{
		time_t seconds;

		seconds = time(NULL);
		long long a = seconds;
		cout << "编号为" << goodsId
			<< "的快递已经在" << a - goods[goodsId]->getChecktime()
			<< "秒前被取走" << endl;
		return;
	}

	else if (goods[goodsId]->getStation() == 1)
	{
		keys.findGoods(goodsId);
		return;
	}

	else
	{
		cout << "此快递并未到达快递柜" << endl;
		return;
	}
}

bool checkOvertime()
{
	time_t seconds;
	seconds = time(NULL);
	long long a = seconds;
	for (long long i = 0; i < 4; i++)
		if (goods[i]->getStation() == 1 && a - goods[i]->getPuttime() >= 10)//20s即过期 
		{
			keys.findGoods(i);
			return true;
		}
	return false;
}
