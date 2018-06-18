#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
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
	ifstream fin;
	ofstream fout;
	Acc_list();
	~Acc_list();
	void addNode(const Account b);
	void delNode(const Account b);
	void showNode();
	void set_count(int count);
	void set_head(pNode ptr);
	int get_count();
	pNode get_head();
	void savelist();
	void loadlist();

};

Acc_list::Acc_list() {
	head = NULL;
	count = 0;
	fin.open("Acc_list.txt", ios::in);
	fout.open("Acc_list.txt", ios::out | ios::app);
}
Acc_list::~Acc_list(){
	fin.close();
	fout.close();
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
			cout << i+1 << "¹øÂ° °í°´´Ô" << endl;
			cout << "°èÁÂ¹øÈ£ : " << p->data.number << endl;
			cout << "ÀÌ    ¸§ : " << p->data.name << endl;
			cout << "ÀÜ    ¾× : " << p->data.balance << endl;
			cout << "ºñ¹Ð¹øÈ£ : " << p->data.pass << endl;
			p = p->link;
		}
	}
}

void Acc_list::set_count(int count)
{
	this->count = count;
}

void Acc_list::set_head(pNode ptr)
{
	this->head = ptr;
}

int Acc_list::get_count()
{
	return this->count;
}

pNode Acc_list::get_head()
{
	return this->head;
}

void Acc_list::savelist()
{
	pNode temp = this->head;
	while (temp) {
		this->fout << temp->data.name << "\n" << temp->data.number << "\n" << temp->data.pass << "\n" << temp->data.balance << "\n";
		temp = temp->link;
	}
	fout.close();
	return;
}

void Acc_list::loadlist()
{
	string test;
	int test2;
	/*while (fin.eof()) {
		Account a;
		getline(fin, a.name);
		getline(fin, a.number);
		getline(fin, a.pass);
		fin >> a.balance;
		addNode(a);
	}*/

	for( int i = 0; i <7; i++){

		Account a;
		string temp;
		getline(fin, a.name);
		//cout << a.name << endl;

		getline(fin, a.number);
		//cout << a.number << endl;

		getline(fin, a.pass);
		//cout << a.pass << endl;

		getline(fin, temp);
		a.balance = stoi(temp);
		//fin >> a.balance;
		//cout << a.balance << endl;

		//cout << "\n"<<a.name << a.number << a.pass << a1 << "\n"<< endl;
		addNode(a);
	}
	fin.close();
}

int main() {
	Acc_list list;
	
	//Account chulsu("±èÃ¶¼ö", "1234-1234", "qudtls", 500);
	//Account younghee("±è6¿µÈñ", "4567-4567", "qkqh", 30000);
	//Account younghee2("±è5¿µÈñ", "4213567-4567", "qkqh", 411000);
	//Account younghee3("±è4¿µÈñ", "4562137-4567", "qkqh", 30040);
	//Account younghee4("±è3¿µÈñ", "4521367-4567", "qkqh", 3100);
	//Account younghee5("±è2¿µÈñ", "4521367-4567", "qkqh", 3012000);
	//Account younghee6("±è1¿µÈñ", "4562137-4567", "qkqh", 30000);

	//list.addNode(chulsu);
	//list.addNode(younghee);
	//list.addNode(younghee2);
	//list.addNode(younghee3);
	//list.addNode(younghee4);
	//list.addNode(younghee5);
	//list.addNode(younghee6);
	list.loadlist();

	list.showNode();
	
	/*list.savelist();

	list.showNode();
*/

}



//class Account_Admin {
//public:
//
//	
//	int balance;		//ÀÜ¾×
//	string name;		//¿¹±ÝÁÖ
//	string number;		//°èÁÂ¹øÈ£
//	string pass;		//ºñ¹Ð¹øÈ£
//
//	iostream FIEL;
//
//	Account_Admin(string name = "", string number = "", string pass = "", int balance = 0) {
//		this->pass = pass;
//		this->number = number;
//		this->name = name;
//		this->balance = balance;
//	}
//
//	void Create_Account(string name, string number) {
//		this->name = name;
//
//	}
//
//};