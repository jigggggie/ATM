#include "Accountlist.h"

int lineoftxt(char* txtfile) {
	ifstream wow;
	wow.open(txtfile, ios::in);
	string temp;
	int linenum = 0;
	while (getline(wow, temp))
		++linenum;
	wow.close();
	return linenum;
}

Acc_list::Acc_list() {
	head = NULL;
	AccountNum = 0;
	fileAccountNum = lineoftxt("Acc_list.txt") / 4;
	fin.open("Acc_list.txt", ios::in);
	loadlist();
	fout.open("Acc_list.txt", ios::out);
	user.open("userid.txt", ios::out);
}
Acc_list::~Acc_list() {
	savelist();
	fin.close();
	fout.close();
	user.close();
}
void Acc_list::addNode(const Account b) {
	AccountNum++;

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

	while (p) {
		if (p->data.number == b.number) {
			if (pp)
				pp->link = p->link;
			else
				head = p->link;
			delete p;
			AccountNum--;
			return;
		}
		pp = p;
		p = p->link;
	}
}

void Acc_list::showNode() {
	pNode p = head;
	while (p) {
		for (int i = 0; i < AccountNum; i++) {
			cout << i + 1 << "��° ����" << endl;
			cout << "���¹�ȣ : " << p->data.number << endl;
			cout << "��    �� : " << p->data.name << endl;
			cout << "��    �� : " << p->data.balance << endl;
			cout << "��й�ȣ : " << p->data.pass << endl;
			p = p->link;
		}
	}
}

void Acc_list::set_AccountNum(int AccountNum)
{
	this->AccountNum = AccountNum;
}

void Acc_list::set_head(pNode ptr)
{
	this->head = ptr;
}

int Acc_list::get_AccountNum()
{
	return this->AccountNum;
}

pNode Acc_list::get_head()
{
	return this->head;
}

void Acc_list::savelist()
{
	pNode temp = this->head;
	while (temp) {
		this->fout << temp->data.number << "\n" << temp->data.name << "\n" << temp->data.pass << "\n" << temp->data.balance << "\n";
		this->user << temp->data.number << "\n" << temp->data.pass << "\n";
		temp = temp->link;
	}
	return;
}

void Acc_list::loadlist()
{
	for (int i = 0; i <fileAccountNum; i++) {
		Account a;
		string temp;
		getline(fin, a.number);
		getline(fin, a.name);
		getline(fin, a.pass);
		getline(fin, temp);
		a.balance = stoi(temp);
		addNode(a);
	}
}

void Acc_list::addAccount()
{
	Account add;
	cout << "����� ���¿� ���� ������ �Է��ϼ���. (0000-0000)" << endl;
	cout << "���¹�ȣ : "; cin.ignore(); getline(cin, add.number);
	while (isOver(add.number))
	{
		cout << endl << "�ߺ��� �����Դϴ�. �ٸ� ��ȣ�� �Է����ֽʽÿ�." << endl;
		cout << "���¹�ȣ : "; getline(cin, add.number);
	}
	cout << "��    �� : "; getline(cin, add.name);
	cout << "��й�ȣ : "; getline(cin, add.pass);
	cout << "��    �� : "; cin >> add.balance;

	addNode(add);
}

void Acc_list::delAccount()
{
	Account del;
	cout << "������ ���¹�ȣ�� �Է����ּ��� : "; cin.ignore(); getline(cin, del.number);

	delNode(del);
}

bool Acc_list::isOver(string input)
{
	pNode p = head;
	while (p) {
		if (p->data.number == input) return true;
		p = p->link;
	}
	return false;
}