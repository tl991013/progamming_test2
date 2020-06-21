#include "Keycell.h"
map<string, bool>keyMap;
Keycell::Keycell(string k, long long gId, int bId, int inDex) :key(k), goodsId(gId), boxId(bId), index(inDex), next(NULL)
{
}

void Keycell::setRandomKey()
{
	srand((int)time(0));
	char str[10];
	while (1)
	{
		for (int i = 0; i < 6; ++i)
		{
			switch ((rand() % 3))
			{
			case 1:
				str[i] = 'A' + rand() % 26;
				break;
			case 2:
				str[i] = 'a' + rand() % 26;
				break;
			default:
				str[i] = '0' + rand() % 10;
				break;
			}
		}
		str[6] = '\0';
		if (keyMap[str] == 0)
			break;
	}
	keyMap[str] = 1;
	key = str;
}

string Keycell::getKey()
{
	return key;
}

int Keycell::getBoxId()
{
	return boxId;
}

int Keycell::getGoodsId()
{
	return goodsId;
}

void Keycell::sendMessage()
{
	cout << "短信" << endl;
	cout << "您好，您编号为" << goodsId
		<< "的快递已经到达" << boxId
		<< "号快递柜,请一小时内凭借" << key.c_str()
		<< "领取您的快递" << endl;
}