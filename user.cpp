#include "Accountlist.h"

extern int lineoftxt(char* txtfile);

int user(int cnt) {
	Acc_list list;
	cout << "사용자계정으로 접속중"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	system("cls");
	int sel = 0;
	while (sel != 5) {
		cout << "--------------------------------------------------------------" << endl;
		cout << "1.입금\t2.출금\t3.송금\t4.조회\t5.로그아웃" << endl;
		cout << "--------------------------------------------------------------" << endl;


		cout << "원하시는 메뉴를 입력하세요 >> "; cin >> sel;

		switch (sel) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
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