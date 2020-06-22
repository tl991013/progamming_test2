#define _CRT_SECURE_NO_WARNINGS
#include"Sign.h"

int recordMenu = 1;//记录Menu是否继续循环
int recordWork = 1;//记录Work是否循环
//身份的选择：快递员和收件人
int Menu() {
	cout << "***********************************************************************************************" << endl;
	Sleep(100);
	cout << "***********************************************************************************************" << endl;
	Sleep(100);
	cout << "**  ***********  *****              *********  *********  *******                *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****  *********************  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****  *********************  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****  *********************  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****  *********************  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**               *****              *********  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****  *********************  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****  *********************  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****  *********************  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****  *********************  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****  *********************  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "**  ***********  *****             **********  *********  *******  ************  *************" << endl;
	Sleep(100);
	cout << "*********************************************  *********  *******                ************" << endl;
	Sleep(100);
	cout << "*********************************************************************************************" << endl;
	Sleep(300);
	system("cls");
	while (recordMenu) {

		cout << "|------------------------------------------------------------------------|" << endl;
		cout << "|*\t\t\t\t中国邮政快递柜\t\t\t\t*|" << endl;
		cout << "|*\t\t\tWELCOME TO USE THE POSTBOX\t\t\t*|" << endl;
		cout << "|------------------------------------------------------------------------|" << endl;
		cout << "|------------------------------------------------------------------------|" << endl;
		cout << "|*\t\t**\t\t主菜单\t\t\t\t\t*|" << endl;
		cout << "|*\t\t**\t\t\t\t\t\t\t*|" << endl;
		cout << "|*\t\t**\t\t0.退出\t\t\t\t\t*|" << endl;
		cout << "|*\t\t**\t\t\t\t\t\t\t*|" << endl;
		cout << "|*\t\t**\t\t1.快递员\t\t\t\t*|" << endl;
		cout << "|*\t\t**\t\t\t\t\t\t\t*|" << endl;
		cout << "|*\t\t**\t\t2.取快递\t\t\t\t\t*|" << endl;
		cout << "|*\t\t**\t\t\t\t\t\t\t*|" << endl;
		cout << "|------------------------------------------------------------------------|" << endl;
		int a;
		cout << "请选择：";
		cin >> a;
		switch (a)
		{
		case 0:exit(0);
			//此处加入存储文件
			break;
		case 1:system("pause");;
			system("cls");
			PostSign();
			recordMenu = 1;
			break;
		case 2:system("pause");;
			system("cls");
			ReceSign();
			recordMenu = 1;
			break;
		default:cout << "*输入错误，等待重新选择*" << endl;
			system("pause");;
			system("cls");
			recordMenu = 1;
			break;
		}
	}
	return 0;
}

int PostSign() {
	int id = -1, i = -1, record = 0;
	int num = -1;
	string password = "";
	cout << "***输入账号密码界面***" << endl << endl;
	cout << "******请输入账号******" << endl;
	cin >> id;
	cout << endl;
	cout << "******请输入密码******" << endl;
	cin >> password;
	cout << endl;

	//检验密码的正确性
	for (i = 0; i < 100; i++) {
		if (postman[i] != NULL && id == postman[i]->getPostId()) {
			if (password == postman[i]->getPassWord()) {
				cout << "*登录成功*" << endl;
				record = 1;
				system("pause");
				system("cls");
				break;
			}
			else {
				cout << "*密码错误,重新登录*" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		if (postman[i] == NULL || i == 100) {
			cout << "*账号不存在,请等待重新输入选项*" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	if (record == 1)
		Work();
	//返回主菜单
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
		cout << "****0.退出,返回主菜单*****" << endl << endl;
		cout << "****1.存入快递************" << endl << endl;
		cout << "****2.查询快递柜使用情况**" << endl << endl;
		cout << "****3.检查快递************" << endl << endl;
		cout << "****4.快递是否超时********" << endl << endl;
		cout << "****5.创建包裹************" << endl << endl;
		cout << "****6.注册新快递员********" << endl << endl;
		cout << "**************************" << endl << endl;
		cout << "****请输入选项：";
		cin >> choice;
		switch (choice) {
		case 0:
			system("cls");
			recordWork = 0;
			recordMenu = 1;
			break;
		case 1:
			system("cls");
			Put();
			system("pause");
			recordWork = 1;
			system("cls");
			break;
		case 2:
			system("cls");
			checkBox();
			system("pause");
			recordWork = 1;
			system("cls");
			break;
		case 3:
			system("cls");
			checkGoods();
			recordWork = 1;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			checkOvertime();
			recordWork = 1;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			createGoods();
			recordWork = 1;
			system("pause");
			system("cls");
			break;
		case 6:system("cls");
			creatNewPostman();
			recordWork = 1;
			system("pause");
			system("cls");
			break;
		default:cout << "输入错误，等待重新输入" << endl;
			system("pause");;
			system("cls");
			recordWork = 1;
			break;
		}
	}
	return 0;
}