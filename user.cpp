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

	cout << "����ڰ������� ������"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
	system("cls");
	int sel = 0;
	int don = 0;

	while (sel != 5) {
		cout << "--------------------------------------------------------------" << endl;
		cout << "1.�Ա�\t2.���\t3.�۱�\t4.��ȸ\t5.�α׾ƿ�" << endl;
		cout << "--------------------------------------------------------------" << endl;


		cout << "���Ͻô� �޴��� �Է��ϼ��� >> "; cin >> sel;

		switch (sel) {
		case 1:
			cout << "�Ա��Ͻ� �ݾ��� �Է����ּ��� : "; cin >> don;
			user->data.Deposit(don);
			break;
		case 2:
			cout << "��й�ȣ�� �Է��Ͽ� �ֽʽÿ�."; cin.ignore(); getline(cin, pass);
			cout << "����Ͻ� �ݾ��� �Է����ּ��� : "; cin >> don;
			if (!(user->data.Withdraw(pass, don))) cout << "��� ����...;;����" << endl;
			else cout << "��� �Ϸ�!" << endl;
			break;
		case 3:
			cout << "�۱��� ���¸� �Է��Ͽ� �ֽʽÿ�."; cin.ignore(); getline(cin, arthur);
			cout << "��й�ȣ�� �Է��Ͽ� �ֽʽÿ�."; getline(cin, pass);
			cout << "�۱��Ͻ� �ݾ��� �Է����ּ��� : "; cin >> don;
			//user->data.Remmitance(arthur, pass, don);
			break;
		case 4:
			cout << "��й�ȣ�� �Է��Ͽ� �ֽʽÿ�."; cin.ignore(); getline(cin, pass);
			user->data.Show(pass);
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
