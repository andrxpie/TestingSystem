#include "Admin.h"

bool Admin::checkTrueSize(const str& login, int left, int right) const { if (login.size() >= left and login.size() <= right) return true; else return false; }
bool Admin::checkFirstSymbol(const str& login) const { if (login.find_first_of("0123456789") != -1) return false; else return true; }
bool Admin::checkTrueLogin(str& login) const { if (checkTrueSize(login, 3, 16) == true and checkFirstSymbol(login) == true) return true; else return false; }
bool Admin::getIsAdmin() const { return isAdmin; }

bool Admin::checkLogin(const str& login) const {
	ifstream checkL("Admin.txt");
	string tmp;
	checkL >> tmp;
	cout << " tmp: " << tmp << "\n";
	checkL.close();
	return true;
}

void Admin::registerAdmin() {
	cout << " login: "; str login; cin >> login;
	while (checkTrueLogin(login) == false) {
		while (checkTrueSize(login, 3, 16) == false) { system("cls"); cerr << " incorect login: size, re-enter correct: "; cin >> login; }
		while (checkFirstSymbol(login) == false) { system("cls"); cerr << " incorect login: first must be letter, re-enter correct: "; cin >> login; }
	} this->loginAdm = login;

	cout << " password: "; str password; cin >> password;
	while (checkTrueSize(password, 8, 32) == false) { system("cls"); cerr << " incorrect password: size, re-enter correct: "; cin >> password; } this->passwordAdm = password;
	
	system("cls");
	cout << " login: " << loginAdm << "\n";
	cout << " password: " << passwordAdm << "\n *save it somewhere\n\n";
	isAdmin = true;

	string hashLogin, hashPassword;
	saveLPToFile(hashLogin, hashPassword);
}

void Admin::loginAdmin() {
	cout << " login: "; str login; cin >> login;
	while (checkLogin(login) == false) {
		cerr << " incorrect login: not found, re-enter: "; cin >> login;
	}
}

void Admin::saveLPToFile(const str& login, const str& password) const { ofstream fileIt("Admin.txt"); fileIt << loginAdm << "\n"; fileIt << passwordAdm; fileIt.close(); }