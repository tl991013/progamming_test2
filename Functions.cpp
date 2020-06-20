#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Functions.h"
using namespace std;
PostMan* postman[100];
Client* client[100];
Goods* goods[100];
Box* box[100];
Keys keys;
Keycell* keycell[100];

void getPostMan()
{

	string a, b, c, e;
	int d;
	fstream fio("D:\\postman.txt", ios::in | ios::out);
	if (fio.is_open())
	{
		for (int i = 0; i < 100; i++)
		{
			fio >> a >> b >> c >> d >> e;
			postman[i] = new PostMan(a, b, c, d, e);
			if (fio.eof())
				break;
		}
		fio.close();
	}
	else
		cout << "文件打开失败" << endl;
}

void getClient()
{
	string a, b, c, d;
	int e;
	fstream fio("D:\\client.txt", ios::in | ios::out);
	if (fio.is_open())
	{
		for (int i = 0; i < 100; i++)
		{
			fio >> a >> b >> c >> d >> e;
			client[i] = new Client(a, b, c, d, e);
			if (fio.eof())
				break;
		}
		fio.close();
	}
	else
		cout << "文件打开失败" << endl;
}

void getGoods()
{
	string a, b;
	int c,d;
	fstream fio("D:\\client.txt", ios::in | ios::out);
	if (fio.is_open())
	{
		for (int i = 0; i < 100; i++)
		{
			fio >> a >> b >> c >> d;
			goods[i] = new Goods(a, b, c, d);
			if (fio.eof())
				break;
		}
		fio.close();
	}
	else
		cout << "文件打开失败" << endl;
}
void savePostman() {
	ofstream fw;
	fw.open("D:\\postman.txt", ios::out);
	if (fw.is_open()) {
		for (int i = 0; postman[i] != NULL; i++) {
			fw << postman[i]->getId() << "\t" << postman[i]->getTel() << "\t" << postman[i]->getName() << "\t"
				<< postman[i]->getPostId() << "\t" << postman[i]->getPosition() << "\n";
		}
	}
	fw.close();
}

void saveClient() {
	ofstream fw;
	fw.open("D:\\client.txt", ios::out);
	if (fw.is_open()) {
		for (int i = 0; client[i] != NULL; i++) {
			fw << client[i]->getId() << "\t" << client[i]->getTel() << "\t" << client[i]->getName() << "\t"
				<< client[i]->getAddress() << "\t" << client[i]->getClintId() << "\n";
		}
	}
}

void saveGood() {
	ofstream fw;
	fw.open("D:\\goods.txt", ios::out);
	if (fw.is_open()) {
		for (int i = 0; goods[i] != NULL; i++) {
			fw << goods[i]->getpId() << "\t" << goods[i]->getrId() << "\t" << goods[i]->getStation() << "\n";
		}
	}
}

void saveKey() {
	ofstream fw;
	fw.open("D:\\key.txt", ios::out);
	if (fw.is_open()) {
		for (int i = 0; keycell[i] == NULL; i++) {
			fw << keycell[i]->getKey() << "\t" << keycell[i]->getGoodsId() << "\t" << keycell[i]->getBoxId() << "\n";
		}
	}
	fw.close();
}

void getKeycell() {
	string a;
	long long b;
	int c;
	ifstream fr;
	fr.open("key.txt", ios::in);
	if (fr.is_open()) {
		for (int i = 0; i < 100; i++) {
			fr >> a >> b >> c;
			keycell[i] = new Keycell(a, b, c, -1);
			if (fr.eof())
				break;
		}
		fr.close();
	}
	else
		cout << "文件打开失败" << endl;
	for (int i = 0; keycell[i] != NULL; i++) {
		keys.insertKey(keycell[i]);
	}
}


void initial()
{
	getPostMan();
	getClient();
	getGoods();
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
