#include "Accountlist.h"

int admin() {
	Acc_list list;
	cout << "�����ڰ������� ������"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	system("cls");
	int sel = 0;
	while (sel != 4) {
		cout << "--------------------------------------------------------------" << endl;
		cout << "1.���»���\t2.���»���\t3.������ȸ\t4.�α׾ƿ�" << endl;
		cout << "--------------------------------------------------------------" << endl;


		cout << "���Ͻô� �޴��� �Է��ϼ��� >> "; cin >> sel;

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
			cout << endl << "�߸��� �����Դϴ�." << endl;
			break;
		}
	}
	cout << endl << "���������� �α׾ƿ� �Ǿ����ϴ�"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	//list.fileAccountNum = list.AccountNum;
	return 0;
}
