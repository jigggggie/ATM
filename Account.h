#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account {
public:
	int balance;		//잔액
	string pass;		//비밀번호
	string name;		//예금주
	string number;	//계좌번호

	Account(string name, string number, string pass, int balance = 0) {
		this->pass = pass;
		this->number = number;
		this->name = name;
		this->balance = balance;
	}


	//입금, 출금, 송금, 조회하기
	int Deposit(int money) {
		if (money < 0)	//입금실패
		{
			cout << "잘못된 값을 입력하셨습니다." << endl;
			return 0;
		}
		balance += money;	//입금성공
		cout << "입금이 완료되었습니다." << endl;
		return 1;
	}

	int Withdraw(string pass, int money) {
		if (this->pass != pass) {
			cout << "비밀번호가 틀렸습니다." << endl;
			return 0;	//비밀번호 틀림
		}
		if (money > this->balance) {
			cout << "잔액이 부족합니다." << endl;
			return 0;	//잔액부족
		}
		this->balance -= money;
		return money;
	}

	int Remmitance(Account * acc, string pass, int money) {
		int send = Withdraw(pass, money);
		if (send == 0) {
			cout << "잔액이 부족하거나 비밀번호를 확인하여 주십시오." << endl;
			return 0;	//출금 실패로 인한 송금 실패
		}
		acc->Deposit(send);
		return 1;	//송금 성공
	}
	int Show(string pass) {
		if (this->pass == pass) {
			cout << name << "님의 정보" << endl;
			cout << "계좌번호 : " << number << endl;
			cout << "잔액 : " << balance << endl;
			return 1;
		}
		else
		{
			cout << "비밀번호가 틀렸습니다." << endl;
			return 0;
		}
	}
};

//123
