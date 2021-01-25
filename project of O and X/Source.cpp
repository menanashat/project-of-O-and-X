#include<iostream>
#include<string>
using namespace std;
string   a[3][3] = { "1","2","3","4","5","6","7","8","9" };
void printplay() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << "    ";
			if (j == 2) {
				continue;
			}
			cout << "|    ";
		}
		cout << endl;
		cout << "-----------------------";
		cout << endl;
	}
}
string palyers = "x";
void player() {
	string  pos;
	cout << "choose your position player(" << palyers << "): ";
	cin >> pos;

	if (pos != "1" && pos != "2" && pos != "3" && pos != "4" && pos != "5" && pos != "6" && pos != "7" && pos != "8" && pos != "9") 
	{
		cout << "no vaalied number" << endl;
		if (cin.get() == '\n') {

		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == pos) {
				a[i][j] = palyers;
			}
			//else {//if(a[i][j]!='1'&&a[i][j]!='2' && a[i][j] != '3' && a[i][j] != '4' && a[i][j] != '5' && a[i][j] != '6' && a[i][j] != '7' && a[i][j] != '8' && a[i][j] != '9'){
			//	cout << "no" << endl;
			//}

		}
	}
	if (palyers == "x") {
		palyers = "o";
	}
	else {
		palyers = "x";
	}
		if (cin.get() == '\n') {
		system("cls");
	}
}
int coount = 0;
string wonplayer() {
	int cx = 0, co = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] != "o" || a[i][j] != "x") {
				coount++;
			}
			if (a[i][j] == "x") {
				cx++;
			}
			else if (a[i][j] == "o") {
				co++;
			}
			if (cx == 3 || co == 3) {
				return cx > co ? "x" : "o";
			}
		}
		cx = 0, co = 0;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[j][i] != "o" || a[i][j] != "x") {
				coount++;
			}
			if (a[j][i] == "x") {
				cx++;
			}
			else if (a[j][i] == "o") {
				co++;
			}
			if (cx == 3 || co == 3) {
				return cx > co ? "x" : "o";
			}
		}
		cx = 0, co = 0;
	}
	if (a[0][0] == "o" && a[1][1] == "o" && a[2][2] == "o") { return "o"; }
	else if (a[0][0] == "x" && a[1][1] == "x" && a[2][2] == "x") { return "x"; }
	else if (a[0][2] == "x" && a[1][1] == "x" && a[2][0] == "x") { return "x"; }
	else if (a[0][2] == "o" && a[1][1] == "o" && a[2][0] == "o") { return "o"; }
	if (coount == 0) {
		return  "z";
	}
	return ".";
}
int main() {
	while (wonplayer() == ".") {
		printplay();
		player();
	}
	printplay();
	if (wonplayer() == "z") {
		cout << "\n  no one is win " << endl;
	}
	else {
		cout << "player  ( " << wonplayer() << " ) congratolationn ..." << endl;
	}
	return 0;
}
