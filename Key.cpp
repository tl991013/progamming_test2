#include "Key.h"
#include "Box.h"

Keys::Keys()
{
	head = new Keycell();
}

void Keys::insertKey(keytype k)
{
	k->next = head->next;
	head->next = k;
}

Keycell Keys::findKey(string kkey)
{
	keytype p = head->next;
	keytype q = head;
	while (p != NULL)
	{
		if (p->getKey() == kkey)
		{
			q->next = p->next;
			cout << "编号为" << p->getGoodsId()
				<< "的快递，在" << p->getBoxId()
				<< "号快递柜，第" << p->index / Box::Boxw + 1
				<< "行第" << p->index % Box::Boxh + 1
				<< "列" << endl;
			Keycell ret = *p;
			delete p;
			keyMap[kkey] = 0;
			return ret;
		}
		q = p;
		p = p->next;
	}
	return Keycell();//输入错误，查找失败
}

void Keys::printKeys() const
{
	keytype p = head->next;
	while (p != NULL)
	{
		cout << p->getKey() << " ";
		p = p->next;
	}
}

void Keys::findGoods(long long goodsId) const
{
	keytype p = head->next;
	while (p != NULL)
	{
		if (p->getGoodsId() == goodsId)
		{
			cout << "编号为" << p->getGoodsId()
				<< "的快递，在" << p->getBoxId()
				<< "号快递柜，第" << p->index / Box::Boxw + 1
				<< "行第" << p->index % Box::Boxh + 1
				<< "列" << endl;
			return;
		}
		p = p->next;
	}
}