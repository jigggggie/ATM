#pragma once
#include "Account.h"
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

typedef struct Node* pNode;

typedef struct Node {
	Account data;
	pNode link;
}Node;

class Acc_list {
public:
	pNode head;
	pNode curr;
	int AccountNum;
	int fileAccountNum;
	ifstream fin;
	ofstream fout;
	ofstream user;
	Acc_list();
	~Acc_list();
	void addNode(const Account b);
	void delNode(const Account b);
	void showNode();
	pNode findNode(string f);
	void set_AccountNum(int AccountNum);
	void set_head(pNode ptr);
	int get_AccountNum();
	pNode get_head();
	void savelist();
	void loadlist();
	void addAccount();
	void delAccount();
	bool isOver(string input);
};