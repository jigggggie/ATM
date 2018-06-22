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
//		cout << "파일 열기 실패" << endl;
//		return 0;
//	}
//
//	cout << "ID입력 : "; cin >> Id;
//	cout << "비밀번호 : "; password = inputpasswords();
//	fout << Id << endl;
//	fout << password << endl;
//	
//	fout.close();
//	return 0;
//}




int main() {
	string adminid, adminpass; //관리자 아이디와 비밀번호 설정되어 있음.
	string id,pass; //사용자가 입력할 아이디와 비밀번호.
	string userid, userpass; //사용자 아이디와 비밀번호

	int passcnt = 0; //틀린횟수 카운트
	int login_menu;

	ifstream adminfin("supervisor.txt", ios::in); //만들어져있는 관리자 파일을 가져옴.
	if (!adminfin)
	{
		cout << "관리자파일 열기 실패" << endl;
		return 0;
	}
	adminfin >> adminid;
	adminfin >> adminpass;

	
ifstream userfin("user.txt"); //사용자 파일을 가져옴 관리자메뉴안에 사용자 만들기 기능이 있음 거기에 ofstream 쓰면 될 듯.
	if (!userfin)
	{
		cout << "사용자파일 열기 실패" << endl;
		return 0;
	}
	userfin >> userid;
	userfin >> userpass;
	
	cout << "1.관리자 로그인\t 2.사용자 로그인" << endl; cin >> login_menu;
	switch (login_menu)
	{
	case 1:
		while (6)
		{
			cout << "ID입력 : "; cin >> id;
			cout << "비밀번호 : "; pass = inputpasswords();

			if (adminid == id) //관리자 로그인
			{
				if (adminpass == pass)
				{
					cout << "\n관리자 로그인 성공!" << endl;
					break;
				}
				else
				{
					++passcnt;
					cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;
					if (passcnt == 5)
					{
						cout << "프로그램을 종료합니다." << endl;
						return 0;
					}
				}
			}
			else
			{
				++passcnt;
				cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;
				if (passcnt == 5)
				{
					cout << "프로그램을 종료합니다." << endl;
					return 0;
				}
			}
		
		}
		break;


	case 2:
		while (6)
		{
			cout << "유저아이디: " << userid << "유저비번:" << userpass;
			cout << "사용계좌번호를 입력하시오: "; cin >> id;
			cout << "사용비밀번호를 입력하시오: "; pass = inputpasswords();

			if (userid == id) //사용자 로그인
			{
				if (userpass == pass)
				{
					cout << "\n사용자 로그인 성공!" << endl;
					break;
				}

				else
				{
					++passcnt;
					cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;
					if (passcnt == 5)
					{
						cout << "프로그램을 종료합니다." << endl;
						return 0;
					}
				}
			}
			else
			{
				++passcnt;
				cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;
				if (passcnt == 5)
				{
					cout << "프로그램을 종료합니다." << endl;
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
//		cout << "파일 열기 실패" << endl;
//		return 0;
//	}
//
//	fin >> name;
//	fin >> password;
//	fin >> money;
//
//	cout << "이름 : " << name << endl;
//	cout << "비밀번호 : " << password << endl;
//	cout << "예금금액 : " << money << endl;
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
//		cout << "파일 열기 실패" << endl;
//		return 0;
//	}
//
//	int cnt = 0;
//	for (int c; (c = fin.get()) != EOF; cnt++)
//		cout << (char)c;
//
//	cout << "읽은 바이트 수 : " << cnt << endl;
//	fin.close();
//}


//int main()
//{
//	ifstream fin;
//	fin.open("Account.txt", ios::in);
//	if (!fin)
//	{
//		cout << "파일 열기 실패" << endl;
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
