#define _CRT_SECURE_NO_WARNINGS
#include"Sign.h"

int recordMenu = 1;
int recordPostsign = 1;
int recordWork = 1;
//身份的选择：快递员和收件人
int Menu() {
	while (recordMenu) {
		cout << "*****主菜单******" << endl << endl;
		cout << "****0.退出*******" << endl << endl;
		cout << "****1.快递员*****" << endl << endl;
		cout << "****2.收件*******" << endl << endl;
		cout << "*****************" << endl << endl;
		int a;
		cout << "请选择：";
		cin >> a;
		switch (a)
		{
		case 0:exit(0);
			break;
		case 1:Sleep(1000);
			PostSign();
			recordMenu = 1;
			break;
		case 2:Sleep(1000);
			ReceSign();
			recordMenu = 1;
			break;
		default:cout << "*输入错误，等待重新选择*" << endl;
			Sleep(1000);
			system("cls");
			recordMenu = 1;
			break;
		}
	}
	
	return 0;
}

int PostSign() {
	recordPostsign = 1;
	int id = -1, i = -1, record = 0;
	int num = -1;
	string password = "";
	while (recordPostsign)
	{
		cout << "*****快递员登录界面*****" << endl << endl;
		cout << "*****0.退出*************" << endl << endl;
		cout << "*****1.输入账号密码*****" << endl << endl;
		cout << "************************" << endl << endl;
		cout << "输入序号:";
		cin >> num;
		switch (num) {
		case 0:
			system("cls");
			recordPostsign = 0;
			recordMenu = 1;
			break;
		case 1:
			system("cls");
			cout << "***输入账号密码界面***" << endl << endl;
			cout << "******请输入账号******" << endl;
			cin >> id;
			cout << endl;
			cout << "******请输入密码******" << endl;
			cin >> password;
			cout << endl;
			recordPostsign = 1;
			break;
		default:cout << "*输入错误,等待重新输入选项*" << endl;
			Sleep(1000);
			system("cls");
			recordPostsign = 1;
			break;
		}
		if (num == 1) {
			for (i = 0; i < 100; i++) {
				if (postman[i] != NULL || id == postman[i]->getPostId()) {
					if (password == postman[i]->getPassWord()) {
						cout << "*登录成功*" << endl;
						record = 1;
						recordPostsign = 0;
						Sleep(1000);
						system("cls");
						break;
					}
					else {
						cout << "*密码错误,重新登录*" << endl;
						Sleep(1000);
						system("cls");
						break;
					}
				}
				if (postman[i] == NULL||i==100) {
					cout << "*账号不存在,请等待重新输入选项*" << endl;
					recordPostsign = 1;
					Sleep(1000);
					system("cls");
					break;
				}
			}
		}
		if (num == 1 && record)
			Work();
	}
	return 0;
}

int ReceSign() {
	Check();
	cout << "*等待返回主菜单*" << endl;
	Sleep(3000);
	system("cls");
	recordMenu = 1;
	return 0;
}

int Work() {
	int choice = -1;
	recordWork = 1;
	while (recordWork) {
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
		case 0:
			system("cls");
			recordWork = 0;
			recordPostsign = 1;
			break;
		case 1:
			system("cls");
			Put();
			recordWork = 1;
			system("cls");
			break;
		case 2:
			system("cls");
			checkBox();
			recordWork = 1;
			system("cls");
			break;
		case 3:
			system("cls");
			checkGoods();
			recordWork = 1;
			system("cls");
			break;
		case 4:
			system("cls");
			checkOvertime();
			recordWork = 1;
			system("cls");
			break;
		default:cout << "输入错误，等待重新输入" << endl;
			Sleep(1000);
			system("cls");
			recordWork = 1;
			break;
		}
	}
	return 0;
}