#include "Accountlist.h"

extern int lineoftxt(char* txtfile);

int user(int cnt) {
	Acc_list list;
	cout << "����ڰ������� ������"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	system("cls");
	int sel = 0;
	while (sel != 5) {
		cout << "--------------------------------------------------------------" << endl;
		cout << "1.�Ա�\t2.���\t3.�۱�\t4.��ȸ\t5.�α׾ƿ�" << endl;
		cout << "--------------------------------------------------------------" << endl;


		cout << "���Ͻô� �޴��� �Է��ϼ��� >> "; cin >> sel;

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
			cout << endl << "�߸��� �����Դϴ�." << endl;
			break;
		}
	}
	cout << endl << "���������� �α׾ƿ� �Ǿ����ϴ�."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	return 0;
}