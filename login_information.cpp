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
	string adminid, adminpass; //관리자 아이디와 비밀번호 설정되어 있음.
	string id,pass; //사용자가 입력할 아이디와 비밀번호.
	string userid, userpass; //사용자 아이디와 비밀번호

	int passcnt = 0; //틀린횟수 카운트
	

	ifstream adminfin("supervisor.txt", ios::in); //만들어져있는 관리자 파일을 가져옴.
	if (!adminfin)
	{
		cout << "관리자파일 열기 실패" << endl;
		return 0;
	}
	adminfin >> adminid;
	adminfin >> adminpass;

	
	ifstream userfin("userid.txt"); //사용자 파일을 가져옴 관리자메뉴안에 사용자 만들기 기능이 있음 거기에 ofstream 쓰면 될 듯.
	if (!userfin)
	{
		cout << "사용자파일 열기 실패" << endl;
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
		cout << "ID(계좌)를 입력하세요 : "; cin >> id;
		cout << "비밀번호를 입력하세요 : "; pass = inputpasswords();


		//관리자 로그인
		if (adminid == id)
		{
			if (adminpass == pass)
			{
				cout << "\n관리자 로그인 성공!" << endl;
				break; //추후에 관리자 함수로 가는 부분
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
				//goto try_again;
			}
		}
		//else if (adminid != id && adminpass == pass) //id는 틀리고 비번이 맞을 때
		//{
		//	++passcnt;
		//	cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;
		//	if (passcnt == 5)
		//	{
		//		cout << "프로그램을 종료합니다." << endl;
		//		return 0;
		//	}
		//}
		

		//사용자 로그인
		else if (!(adminid == id))
		{
			for (int cnt = 0; cnt < fileAccountNum; cnt++)
			{
				if (userids[cnt] == id && userpasss[cnt] == pass)
				{
					cout << "\n 사용자 로그인 성공!" << endl;
					cout << "cnt출력: " << cnt;
					break; //사용자 함수로 가는 부분
				}

			}
		if(!(adminpass==pass))
		{
			++passcnt;
			cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;

			if (passcnt == 5)
			{
				cout << "프로그램을 종료합니다." << endl;
				return 0;
			}
			goto re;

				//if (userpass == pass)
				//{
				//	cout << "\n사용자 로그인 성공!" << endl;
				//	break;
				//}

				//else //id는 맞고 비번이 틀릴 때
				//{
				//	++passcnt;
				//	cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;
				//	if (passcnt == 5)
				//	{
				//		cout << "프로그램을 종료합니다." << endl;
				//		return 0;
				//	}
				//}
			}
			
		}
		//else if (userid != id && userpass == pass) //id가 틀리고 비번이 맞을 때
		//{
		//	++passcnt;
		//	cout << "\n아이디 혹은 비밀번호가 " << passcnt << "회 틀렸습니다." << endl;
		//	if (passcnt == 5)
		//	{
		//		cout << "프로그램을 종료합니다." << endl;
		//		return 0;
		//	}
		//}
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
