#include "Box.h"

int Box::getpostId()
{
	return postId;
}

void Box::setpostId(int a)
{
	postId = a;
}

Box::Box(int id, int pId)
{
	boxId = id;
	postId = pId;
	for (int i = 0; i < Boxh * Boxw; i++)
		box[i] = 0;
}

int Box::getFreeBox() const
{
	for (int i = 0; i < Boxh * Boxw; i++)
		if (box[i] == 0)
			return i;
	return -1;
}

void Box::printBox(int index) const
{
	cout << "第" << index / Boxw + 1
		<< "行第" << index % Boxw + 1
		<< "列的柜子可放入" << endl;
}

void Box::putBox(int index)
{
	box[index] = 1;
}

void Box::checkBox(int index)
{
	box[index] = 0;
}


void Box::printBoxStation()
{
	//画出3*3的方格
	cout << endl;
	cout << "\t\t\t\t\t----------------------" << endl << endl;
	for (int i = 0; i < Boxh; i++)
	{
		int count = 0;
		cout << "\t\t\t\t\t";
		for (int j = 0; j < Boxw; j++) {
			if (box[i * Boxw + j]) {
				cout << "| Y |";
				count++;
			}
			else {
				cout << "| N |";
				count++;
			}
			if (count % 3 != 0)
				cout << "\t";
			if (count % 3 == 0)
				cout << endl << endl;
		}
	}
	cout << "\t\t\t\t\t----------------------" << endl << endl;
}