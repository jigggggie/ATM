#include "Accountlist.h"

int admin() {
	Acc_list list;
	cout << "관리자계정으로 접속중"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	system("cls");
	int sel = 0;
	while (sel != 4) {
		cout << "--------------------------------------------------------------" << endl;
		cout << "1.계좌생성\t2.계좌삭제\t3.계좌조회\t4.로그아웃" << endl;
		cout << "--------------------------------------------------------------" << endl;


		cout << "원하시는 메뉴를 입력하세요 >> "; cin >> sel;

		switch (sel) {
		case 1:
			list.addAccount();
			break;
		case 2:
			list.delAccount();
			break;
		case 3:
			list.showNode();
			break;
		case 4:
			break;
		default:
			cout << endl << "잘못된 선택입니다." << endl;
			break;
		}
	}
	cout << endl << "성공적으로 로그아웃 되었습니다"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	//list.fileAccountNum = list.AccountNum;
	return 0;
}
