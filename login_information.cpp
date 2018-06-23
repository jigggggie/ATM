#include "Accountlist.h"
extern int admin();
extern int user(int cnt);
extern int lineoftxt(char* txtfile);

string inputpasswords(void) {
	string pass = "";
	char ch;
	ch = _getch();
	while (ch != 13) {
		if ((ch == 127 || ch == 8) && !pass.empty()) {
			cout << "\b \b";
			pass.pop_back();
		}
		else {
			pass.push_back(ch);
			cout << "*";
		}

		ch = _getch();
	}
	return pass;
}

void makeadmin() {
	ofstream adminfout("supervisor.txt", ios::out);
	string makeid, makepass;
	cout << "<������ ID / ��й�ȣ �ʱ�ȭ ȭ��>" << endl;
	cout << "ID�� �Է��Ͻʽÿ� >> "; getline(cin, makeid);
	cout << "��й�ȣ�� �Է��Ͻʽÿ� >> "; getline(cin, makepass);
	adminfout << makeid << "\n" << makepass;
}

int login() {
	string adminid, adminpass; //������ ���̵�� ��й�ȣ �����Ǿ� ����.
	string id, pass; //����ڰ� �Է��� ���̵�� ��й�ȣ.
	string userid, userpass; //����� ���̵�� ��й�ȣ
	int log = 1;

	int passcnt = 0; //Ʋ��Ƚ�� ī��Ʈ


	ifstream adminfin("supervisor.txt", ios::in); //��������ִ� ������ ������ ������.
	if (!adminfin)
	{
		makeadmin();
		login();
	}
	adminfin >> adminid;
	adminfin >> adminpass;


	ifstream userfin("userid.txt", ios::in); //����� ������ ������ �����ڸ޴��ȿ� ����� ����� ����� ���� �ű⿡ ofstream ���� �� ��.
	if (!userfin)
	{
		ofstream userfout("userid.txt", ios::out);
	}
	int fileAccountNum = lineoftxt("userid.txt") / 2;
	string * userids = new string[fileAccountNum];
	string * userpasss = new string[fileAccountNum];

	for (int i = 0; i < fileAccountNum; i++) {
		getline(userfin, userids[i]);
		getline(userfin, userpasss[i]);
	}

	while (1)
	{
		system("cls");
	re:
		cout << "ID(����)�� �Է��ϼ��� : "; cin >> id;
		cout << "��й�ȣ�� �Է��ϼ��� : "; pass = inputpasswords();


		//������ �α���
		if (adminid == id)
		{
			if (adminpass == pass)
			{
				cout << "\n������ �α��� ����!" << endl;
				admin();
				login();
			}
			else //id�� �°� ����� Ʋ�� ��
			{
				++passcnt;
				cout << "\n���̵� Ȥ�� ��й�ȣ�� " << passcnt << "ȸ Ʋ�Ƚ��ϴ�." << endl;
				if (passcnt == 5)
				{
					cout << "���α׷��� �����մϴ�." << endl;
					return 0;
				}
				goto re;
			}
		}



		//����� �α���
		else if (!(adminid == id))
		{
			for (int cnt = 0; cnt < fileAccountNum; cnt++)
			{
				if (userids[cnt] == id && userpasss[cnt] == pass)
				{
					cout << "\n ����� �α��� ����!" << endl;
					log = user(cnt);
					login();
				}

			}
			if (!(adminpass == pass) && log == 1)
			{
				++passcnt;
				cout << "\n���̵� Ȥ�� ��й�ȣ�� " << passcnt << "ȸ Ʋ�Ƚ��ϴ�." << endl;

				if (passcnt == 5)
				{
					cout << "���α׷��� �����մϴ�." << endl;
					return 0;
				}
				goto re;

			}
		}

		else // �� Ʋ�� ��
		{
			++passcnt;
			cout << "\n���̵� Ȥ�� ��й�ȣ�� " << passcnt << "ȸ Ʋ�Ƚ��ϴ�." << endl;
			if (passcnt == 5)
			{
				cout << "���α׷��� �����մϴ�." << endl;
				return 0;
			}

		}
	}
}
