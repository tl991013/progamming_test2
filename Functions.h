#pragma once
#include "PostMan.h"
#include "Client.h"
#include "Goods.h"
#include "Box.h"
#include "Key.h"
#include<fstream>
extern PostMan* postman[100];
extern Client* client[100];
extern Goods* goods[100];
extern Box* box[100];
extern Keys keys;
extern Keycell* keycell[100];

void getPostMan();
void getClient();
void getGoods();
void getKeycell();

void savePostman();
void saveClient();
void saveGood();
void saveKey();

void creatNewPostman();
void createGoods();

void initial();
void Put();
void Check();
void checkBox();
void checkGoods();
void checkOvertime();
void getPostMan();
void getClient();
void getGoods();