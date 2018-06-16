#include <fstream>
#include "Account.h"

typedef struct Node* pNode;

typedef struct Node {
	Account data;
	pNode link;
}Node;

class Acc_list {
public:
	pNode head;
	int count;
	//ifstream fin;
	//ofstream fout;
	Acc_list();
	~Acc_list();
	void addNode(const Account b);
	void delNode(const Account b);
	void showNode();
	//void set_count(int count);
	//void set_head(pNode ptr);
	//int get_count();
	//pNode get_head();

};

Acc_list::Acc_list() {
	head = NULL;
	count = 0;
	//fin.open("Acc_list.txt", ios::in);
	//fout.open("Acc_list.txt", ios::out | ios::app);
}
Acc_list::~Acc_list(){
	//fin.close();
	//fout.close();
}
void Acc_list::addNode(const Account b) {
	count++;

	pNode p = this->head;
	pNode temp = new Node;
	temp->data = b;
	temp->link = NULL;

	if (head == NULL) {
		head = temp;
		return;
	}

	while (p->link) p = p->link;
	p->link = temp;
}

void Acc_list::delNode(const Account b) {
	pNode p = this->head;
	pNode pp = NULL;

	if (p->data.number == b.number) {
		head = p->link;
		delete p;
		count--;
		return;
	}
	pp = p;
	p = p->link;
}

void Acc_list::showNode() {
	pNode p = head;
	while (p) {
		for (int i = 0; i < count; i++) {
			cout << i+1 << "��° ����" << endl;
			cout << "���¹�ȣ : " << p->data.number << endl;
			cout << "��    �� : " << p->data.name << endl;
			cout << "��    �� : " << p->data.balance << endl;
			cout << "��й�ȣ : " << p->data.pass << endl;
			p = p->link;
		}
	}
}

int main() {
	Acc_list list;
	Account chulsu("��ö��", "1234-1234", "qudtls", 50000);
	Account younghee("�迵��", "4567-4567", "qkqh", 300000000);
	Account younghee2("�迵��", "4567-4567", "qkqh", 300000000);
	Account younghee3("�迵��", "4567-4567", "qkqh", 300000000);
	Account younghee4("�迵��", "4567-4567", "qkqh", 300000000);
	Account younghee5("�迵��", "4567-4567", "qkqh", 300000000);
	Account younghee6("�迵��", "4567-4567", "qkqh", 300000000);
	list.addNode(chulsu);
	list.addNode(younghee);
	list.addNode(younghee2);
	list.addNode(younghee3);
	list.addNode(younghee4);
	list.addNode(younghee5);
	list.addNode(younghee6);
	list.showNode();
	list.delNode(chulsu);
	list.showNode();

}