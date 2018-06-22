#include "Accountlist.h"


int user(int cnt) {
	Acc_list list;
	pNode user = list.get_head();
	for (int i = 0; i < cnt; i++) {
		if(user)
			user = user->link;
	}
	string pass;
	string arthur;

	cout << "사용자계정으로 접속중"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	system("cls");
	int sel = 0;
	int don = 0;

	while (sel != 5) {
		cout << "--------------------------------------------------------------" << endl;
		cout << "1.입금\t2.출금\t3.송금\t4.조회\t5.로그아웃" << endl;
		cout << "--------------------------------------------------------------" << endl;


		cout << "원하시는 메뉴를 입력하세요 >> "; cin >> sel;

		switch (sel) {
		case 1:
			cout << "입금하실 금액을 입력해주세요 : "; cin >> don;
			user->data.Deposit(don);
			break;
		case 2:
			cout << "비밀번호를 입력하여 주십시오."; cin.ignore(); getline(cin, pass);
			cout << "출금하실 금액을 입력해주세요 : "; cin >> don;
			if (!(user->data.Withdraw(pass, don))) cout << "출금 실패...;;ㄲㅂ" << endl;
			else cout << "출금 완료!" << endl;
			break;
		case 3:
			cout << "송금할 계좌를 입력하여 주십시오."; cin.ignore(); getline(cin, arthur);
			cout << "비밀번호를 입력하여 주십시오."; getline(cin, pass);
			cout << "송금하실 금액을 입력해주세요 : "; cin >> don;
			//user->data.Remmitance(arthur, pass, don);
			break;
		case 4:
			cout << "비밀번호를 입력하여 주십시오."; cin.ignore(); getline(cin, pass);
			user->data.Show(pass);
			break;
		case 5:
			break;
		default:
			cout << endl << "잘못된 선택입니다." << endl;
			break;
		}
	}
	cout << endl << "성공적으로 로그아웃 되었습니다."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	return 0;
}
