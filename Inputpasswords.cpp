#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

string inputpasswords(void) {
	string pass = "";
	char ch;
	cout << "Enter pass >> ";
	ch = _getch();
	while (ch != 13) {
		pass.push_back(ch);
		cout << "*";
		ch = _getch();
	}
	return pass;
}
