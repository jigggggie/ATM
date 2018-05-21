#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account {
public:
	int balance;		//�ܾ�
	string pass;		//��й�ȣ
	string name;		//������
	string number;	//���¹�ȣ

	Account(string name, string number, string pass, int balance = 0) {
		this->pass = pass;
		this->number = number;
		this->name = name;
		this->balance = balance;
	}


	//�Ա�, ���, �۱�, ��ȸ�ϱ�
	int Deposit(int money) {
		if (money < 0)	//�Աݽ���
		{
			cout << "�߸��� ���� �Է��ϼ̽��ϴ�." << endl;
			return 0;
		}
		balance += money;	//�Աݼ���
		cout << "�Ա��� �Ϸ�Ǿ����ϴ�." << endl;
		return 1;
	}

	int Withdraw(string pass, int money) {
		if (this->pass != pass) {
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			return 0;	//��й�ȣ Ʋ��
		}
		if (money > this->balance) {
			cout << "�ܾ��� �����մϴ�." << endl;
			return 0;	//�ܾ׺���
		}
		this->balance -= money;
		return money;
	}

	int Remmitance(Account * acc, string pass, int money) {
		int send = Withdraw(pass, money);
		if (send == 0) {
			cout << "�ܾ��� �����ϰų� ��й�ȣ�� Ȯ���Ͽ� �ֽʽÿ�." << endl;
			return 0;	//��� ���з� ���� �۱� ����
		}
		acc->Deposit(send);
		return 1;	//�۱� ����
	}
	int Show(string pass) {
		if (this->pass == pass) {
			cout << name << "���� ����" << endl;
			cout << "���¹�ȣ : " << number << endl;
			cout << "�ܾ� : " << balance << endl;
			return 1;
		}
		else
		{
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			return 0;
		}
	}
};

//123
