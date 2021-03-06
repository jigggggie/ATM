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
	cout << "<관리자 ID / 비밀번호 초기화 화면>" << endl;
	cout << "ID를 입력하십시오 >> "; getline(cin, makeid);
	cout << "비밀번호를 입력하십시오 >> "; getline(cin, makepass);
	adminfout << makeid << "\n" << makepass;
}

int login() {
	string adminid, adminpass; //관리자 아이디와 비밀번호 설정되어 있음.
	string id, pass; //사용자가 입력할 아이디와 비밀번호.
	string userid, userpass; //사용자 아이디와 비밀번호
	int log = 1;

	int passcnt = 0; //틀린횟수 카운트


	ifstream adminfin("supervisor.txt", ios::in); //만들어져있는 관리자 파일을 가져옴.
	if (!adminfin)
	{
		makeadmin();
		login();
	}
	adminfin >> adminid;
	adminfin >> adminpass;


	ifstream userfin("userid.txt", ios::in); //사용자 파일을 가져옴 관리자메뉴안에 사용자 만들기 기능이 있음 거기에 ofstream 쓰면 될 듯.
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
		cout << "ID(계좌)를 입력하세요 : "; cin >> id;
		cout << "비밀번호를 입력하세요 : "; pass = inputpasswords();


		//관리자 로그인
		if (adminid == id)
		{
			if (adminpass == pass)
			{
				cout << "\n관리자 로그인 성공!" << endl;
				admin();
				login();
			}
			else //id는 맞고 비번이 틀릴 때
			{
				++passcnt;
				cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;
				if (passcnt == 5)
				{
					cout << "프로그램을 종료합니다." << endl;
					return 0;
				}
				goto re;
			}
		}



		//사용자 로그인
		else if (!(adminid == id))
		{
			for (int cnt = 0; cnt < fileAccountNum; cnt++)
			{
				if (userids[cnt] == id && userpasss[cnt] == pass)
				{
					cout << "\n 사용자 로그인 성공!" << endl;
					log = user(cnt);
					login();
				}

			}
			if (!(adminpass == pass) && log == 1)
			{
				++passcnt;
				cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;

				if (passcnt == 5)
				{
					cout << "프로그램을 종료합니다." << endl;
					return 0;
				}
				goto re;

			}
		}

		else // 다 틀릴 때
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
}
