#include <iostream>
#include <fstream>
#include <string>
using namespace std;
extern string inputpasswords(void);

//void createAccount() // Takes and stores users login information, username and password
//{
//	string username;
//	string password;
//	cout << "Please create a username" << endl;
//	cin >> username;
//	cout << "Please create a password" << endl;
//	cin >> password;
//	ofstream createaccount;
//	createaccount.open("accounts.txt", ios::app); // Will store the users information.
//	createaccount << username << " " << password << endl;
//	createaccount.close();
//	cout << "Account created!" << endl;
//
//}


//extern string Id, password;

//int main() {
//	string Id;
//	string password;
//
//	ofstream fout("supervisor.txt");
//	if (!fout)
//	{
//		cout << "���� ���� ����" << endl;
//		return 0;
//	}
//
//	cout << "ID�Է� : "; cin >> Id;
//	cout << "��й�ȣ : "; password = inputpasswords();
//	fout << Id << endl;
//	fout << password << endl;
//	
//	fout.close();
//	return 0;
//}




int main() {
	string adminid, adminpass; //������ ���̵�� ��й�ȣ �����Ǿ� ����.
	string id,pass; //����ڰ� �Է��� ���̵�� ��й�ȣ.
	string userid, userpass; //����� ���̵�� ��й�ȣ

	int passcnt = 0; //Ʋ��Ƚ�� ī��Ʈ
	int login_menu;

	ifstream adminfin("supervisor.txt", ios::in); //��������ִ� ������ ������ ������.
	if (!adminfin)
	{
		cout << "���������� ���� ����" << endl;
		return 0;
	}
	adminfin >> adminid;
	adminfin >> adminpass;

	
ifstream userfin("user.txt"); //����� ������ ������ �����ڸ޴��ȿ� ����� ����� ����� ���� �ű⿡ ofstream ���� �� ��.
	if (!userfin)
	{
		cout << "��������� ���� ����" << endl;
		return 0;
	}
	userfin >> userid;
	userfin >> userpass;
	
	cout << "1.������ �α���\t 2.����� �α���" << endl; cin >> login_menu;
	switch (login_menu)
	{
	case 1:
		while (6)
		{
			cout << "ID�Է� : "; cin >> id;
			cout << "��й�ȣ : "; pass = inputpasswords();

			if (adminid == id) //������ �α���
			{
				if (adminpass == pass)
				{
					cout << "\n������ �α��� ����!" << endl;
					break;
				}
				else
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
			else
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
		break;


	case 2:
		while (6)
		{
			cout << "�������̵�: " << userid << "�������:" << userpass;
			cout << "�����¹�ȣ�� �Է��Ͻÿ�: "; cin >> id;
			cout << "����й�ȣ�� �Է��Ͻÿ�: "; pass = inputpasswords();

			if (userid == id) //����� �α���
			{
				if (userpass == pass)
				{
					cout << "\n����� �α��� ����!" << endl;
					break;
				}

				else
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
			else
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
		break;
	}

}




//int main()
//{
//	char name[20];
//	int password, money;
//
//	ifstream fin;
//	fin.open("Account.txt", ios::in);
//	if (!fin)
//	{
//		cout << "���� ���� ����" << endl;
//		return 0;
//	}
//
//	fin >> name;
//	fin >> password;
//	fin >> money;
//
//	cout << "�̸� : " << name << endl;
//	cout << "��й�ȣ : " << password << endl;
//	cout << "���ݱݾ� : " << money << endl;
//
//	fin.close();
//	return 0;
//}


//int main()
//{
//	char name[20];
//	int password, money;
//
//	ifstream fin;
//	fin.open("Account.txt", ios::in);
//	if (!fin)
//	{
//		cout << "���� ���� ����" << endl;
//		return 0;
//	}
//
//	int cnt = 0;
//	for (int c; (c = fin.get()) != EOF; cnt++)
//		cout << (char)c;
//
//	cout << "���� ����Ʈ �� : " << cnt << endl;
//	fin.close();
//}


//int main()
//{
//	ifstream fin;
//	fin.open("Account.txt", ios::in);
//	if (!fin)
//	{
//		cout << "���� ���� ����" << endl;
//		return 0;
//	}
//
//	string buff;
//	while (!fin.eof())
//	{
//		getline(fin, buff);
//		cout << buff << endl;
//	}
//
//	fin.close();
//	return 0;
//
//}
//
