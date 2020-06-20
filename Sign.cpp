#define _CRT_SECURE_NO_WARNINGS
#include"Sign.h"
//身份的选择：快递员和收件人
int Menu() {
	cout << "*****主菜单******" << endl << endl;
	cout << "****0.退出*******" << endl << endl;
	cout << "****1.快递员*****" << endl << endl;
	cout << "****2.收件*****" << endl << endl;
	cout << "*****************" << endl << endl;
	int a;
	cout << "请选择：";
	cin >> a;
	switch (a)
	{
	case 0:exit(0);
		break;
	case 1:Sleep(1000);
		system("cls");
		PostSign(); break;
	case 2:Sleep(1000);
		system("cls");
		ReceSign(); break;
	default:cout << "*输入错误，等待重新选择*" << endl;
		Sleep(1000);
		system("cls");
		Menu();
		break;
	}
	return 0;
}

int PostSign() {
	int id, i;
	int num;
	string password;
	cout << "*****快递员登录界面*****" << endl << endl;
	cout << "*****0.退出*************" << endl << endl;
	cout << "*****1.输入账号密码*****" << endl << endl;
	cout << "************************" << endl << endl;
	cout << "输入序号:";
	cin >> num;
	switch (num) {
	case 0:Sleep(1000);
		system("cls");
		Menu(); break;
	case 1:Sleep(1000);
		system("cls");
		cout << "***输入账号密码界面***" << endl << endl;
		cout << "******请输入账号******" << endl;
		cin >> id;
		cout << endl;
		cout << "******请输入密码******" << endl;
		cin >> password;
		cout << endl;
		break;
	default:cout << "*输入错误,等待重新输入选项*" << endl;
		Sleep(1000);
		system("cls");
		PostSign();
		break;
	}
	for (i = 0; i < 100; i++) {
		if (id == postman[i]->getPostId()) {
			if (password == postman[i]->getPassWord()) {
				cout << "*登录成功*" << endl;
				Sleep(1000);
				system("cls");
				Work();
			}
			else {
				cout << "*密码错误,重新登录*" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
		}
	}
	if (i == 100) {
		cout << "*账号不存在,请等待重新输入选项*" << endl;
		Sleep(1000);
		system("cls");
	}
	return 0;
}

int ReceSign() {
	Check();
	cout << "*等待返回主菜单*" << endl;
	Sleep(1000);
	system("cls");
	Menu();
	return 0;
}

int Work() {
	int choice;
	cout << "******快递员操作界面******" << endl << endl;
	cout << "****0.退出,返回上层界面***" << endl << endl;
	cout << "****1.存入快递************" << endl << endl;
	cout << "****2.查询快递柜使用情况**" << endl << endl;
	cout << "****3.检查快递************" << endl << endl;
	cout << "****4.快递是否超时********" << endl << endl;
	cout << "**************************" << endl << endl;
	cout << "****请输入选项：";
	cin >> choice;
	switch (choice) {
	case 0:Sleep(1000);
		system("cls");
		PostSign(); break;
	case 1:Sleep(1000);
		system("cls");
		Put(); break;
	case 2:Sleep(1000);
		system("cls");
		checkBox(); break;
	case 3:Sleep(1000);
		system("cls"); checkGoods(); break;
	case 4:Sleep(1000);
		system("cls");
		checkOvertime();
		break;
	default:cout << "输入错误，等待重新输入" << endl;
		Sleep(1000);
		system("cls");
		Work();
		break;
	}
	return 0;
}