#include <iostream>
#include <fstream>
#include <string>
using namespace std;
extern string inputpasswords(void);

int lineoftxt() {
	ifstream wow;
	wow.open("userid.txt", ios::in);
	string temp;
	int linenum = 0;
	while (getline(wow, temp))
		++linenum;
	wow.close();
	return linenum;
}

int main() {
	string adminid, adminpass; //������ ���̵�� ��й�ȣ �����Ǿ� ����.
	string id,pass; //����ڰ� �Է��� ���̵�� ��й�ȣ.
	string userid, userpass; //����� ���̵�� ��й�ȣ

	int passcnt = 0; //Ʋ��Ƚ�� ī��Ʈ
	

	ifstream adminfin("supervisor.txt", ios::in); //��������ִ� ������ ������ ������.
	if (!adminfin)
	{
		cout << "���������� ���� ����" << endl;
		return 0;
	}
	adminfin >> adminid;
	adminfin >> adminpass;

	
	ifstream userfin("userid.txt"); //����� ������ ������ �����ڸ޴��ȿ� ����� ����� ����� ���� �ű⿡ ofstream ���� �� ��.
	if (!userfin)
	{
		cout << "��������� ���� ����" << endl;
		return 0;
	}
	int fileAccountNum = lineoftxt() / 2;
	string * userids = new string[fileAccountNum];
	string * userpasss = new string[fileAccountNum];
	/*userfin >> userid;
	userfin >> userpass;*/
	
	for (int i = 0; i < fileAccountNum; i++) {
		getline(userfin, userids[i]);
		getline(userfin, userpasss[i]);
	}
	
	while (1)
	{
		re:
		cout << "ID(����)�� �Է��ϼ��� : "; cin >> id;
		cout << "��й�ȣ�� �Է��ϼ��� : "; pass = inputpasswords();


		//������ �α���
		if (adminid == id)
		{
			if (adminpass == pass)
			{
				cout << "\n������ �α��� ����!" << endl;
				break; //���Ŀ� ������ �Լ��� ���� �κ�
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
				//goto try_again;
			}
		}
		//else if (adminid != id && adminpass == pass) //id�� Ʋ���� ����� ���� ��
		//{
		//	++passcnt;
		//	cout << "\n���̵� Ȥ�� ��й�ȣ�� " << passcnt << "ȸ Ʋ�Ƚ��ϴ�." << endl;
		//	if (passcnt == 5)
		//	{
		//		cout << "���α׷��� �����մϴ�." << endl;
		//		return 0;
		//	}
		//}
		

		//����� �α���
		else if (!(adminid == id))
		{
			for (int cnt = 0; cnt < fileAccountNum; cnt++)
			{
				if (userids[cnt] == id && userpasss[cnt] == pass)
				{
					cout << "\n ����� �α��� ����!" << endl;
					cout << "cnt���: " << cnt;
					break; //����� �Լ��� ���� �κ�
				}

			}
		if(!(adminpass==pass))
		{
			++passcnt;
			cout << "\n���̵� Ȥ�� ��й�ȣ�� " << passcnt << "ȸ Ʋ�Ƚ��ϴ�." << endl;

			if (passcnt == 5)
			{
				cout << "���α׷��� �����մϴ�." << endl;
				return 0;
			}
			goto re;

				//if (userpass == pass)
				//{
				//	cout << "\n����� �α��� ����!" << endl;
				//	break;
				//}

				//else //id�� �°� ����� Ʋ�� ��
				//{
				//	++passcnt;
				//	cout << "\n���̵� Ȥ�� ��й�ȣ�� " << passcnt << "ȸ Ʋ�Ƚ��ϴ�." << endl;
				//	if (passcnt == 5)
				//	{
				//		cout << "���α׷��� �����մϴ�." << endl;
				//		return 0;
				//	}
				//}
			}
			
		}
		//else if (userid != id && userpass == pass) //id�� Ʋ���� ����� ���� ��
		//{
		//	++passcnt;
		//	cout << "\n���̵� Ȥ�� ��й�ȣ�� " << passcnt << "ȸ Ʋ�Ƚ��ϴ�." << endl;
		//	if (passcnt == 5)
		//	{
		//		cout << "���α׷��� �����մϴ�." << endl;
		//		return 0;
		//	}
		//}
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
