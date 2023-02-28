#include "Admin.h"

bool Admin::checkTrueSize(const str& login, int left, int right) const { if (login.size() >= left and login.size() <= right) return true; else return false; }
bool Admin::checkFirstSymbol(const str& login) const { if (login.find_first_of("0123456789") != -1) return false; else return true; }
bool Admin::checkTrueLogin(str& login) const { if (checkTrueSize(login, 3, 16) == true and checkFirstSymbol(login) == true) return true; else return false; }
bool Admin::getIsAdmin() const { return isAdmin; }

bool Admin::checkLogin(const str& login) {
	ifstream checkL("Admin.txt"); string tmp; checkL >> tmp; checkL.close();
	if (login == uncodeSTRING(tmp)) return true; return false;
}

bool Admin::checkPassword(const str& password) {
	ifstream checkP("Admin.txt"); string tmp; checkP >> tmp >> tmp; checkP.close();
	if (password == uncodeSTRING(tmp)) return true; return false;
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

	saveLPToFile(codeSTRING(loginAdm), codeSTRING(passwordAdm));
}

str Admin::codeSTRING(str& word) {
	for (int i = 0; i < word.size(); i++) {
		if (word[i] >= char(65) and word[i] <= char(90)) word[i] = char(word[i] + 2);
		else if (word[i] >= char(97) and word[i] <= char(111)) word[i] = char(word[i] - 64);
		else if (word[i] >= char(112) and word[i] <= char(122)) word[i] = char(word[i] + 2);
	} return word;
}

str Admin::uncodeSTRING(str& word) {
	for (int i = 0; i < word.size(); i++) {
		if (word[i] >= char(67) and word[i] <= char(92)) word[i] = char(word[i] - 2);
		else if (word[i] >= char(33) and word[i] <= char(47)) word[i] = char(word[i] + 64);
		else if (word[i] >= char(114) and word[i] <= char(124)) word[i] = char(word[i] - 2);
	} return word;
}

void Admin::loginAdmin() {
	cout << " login: "; str login; cin >> login;
	while (checkLogin(login) == false) { system("cls"); cerr << " incorrect login: not found, re-enter: "; cin >> login; }

	system("cls");
	cout << " password: "; str password; cin >> password;
	for (size_t i = 0; i < 3; i++) {
		if (checkPassword(password) == false) { system("cls"); cerr << " incorrect password: not match, re-enter (" << 3 - i << " tries left): "; cin >> password; }
		else { adminTools(); break; }
	}
}

void Admin::saveLPToFile(const str& login, const str& password) const { ofstream fileIt("Admin.txt"); fileIt << loginAdm << "\n"; fileIt << passwordAdm; fileIt.close(); }

void Admin::addGuest() {
	Guest newGuest; newGuest.registerGuest();
	guests.push_back(newGuest);
	newGuest.load_user_data();
}

void Admin::addGuest(class Guest a) {
	guests.push_back(a);
	a.load_user_data();
}

void Admin::delGuest() {
	if (guests.size() == 0) { system("cls"); cout << " >>> No guests founded <<<\n"; return; }

	system("cls");
	cout << " >>> Guests <<<\n";
	for (int i = 0; i < guests.size(); i++) { cout << " " << i + 1 << "# guest: " << guests[i].getLogin() << "\n"; }
	cout << " ?: "; int guestPos; cin >> guestPos;
	guests.erase(guests.begin() + guestPos - 1);
}

void Admin::editUsers() {
	system("cls");
	cout << " >>> Edit users <<<\n";
	cout << " 1. Add guest\n 2. Del guest\n 3. Modify guest\n 4. Return\n";
	cout << " ?: "; int editChoise; cin >> editChoise;
	switch (editChoise) {
	case 1:
		addGuest();
		break;
	case 2:
		delGuest();
		break;
	default:
		system("cls");
		cout << " >>> Edit users <<<\n";
		cout << " 1. Add guest\n 2. Del guest\n 3. Modify guest\n 4. Return\n";
		cerr << " error: wrong option, re-enter opt: "; cin >> editChoise;
		break;
	}
}

void Admin::adminTools() {
	system("cls");
	cout << " >>> Welcome to Admin tools <<<\n";
	cout << " 1. Edit users\n 2. Show statistic\n 3. Edit tests\n 4. Log Out\n";
	cout << " ?: "; int adminChoise; cin >> adminChoise;
	switch (adminChoise) {
	case 1:
		editUsers();
		break;
	case 2:
		//showStat();
		break;
	case 3:
		//editTest();
		break;
	case 4:
		system("cls");
		cout << " >>> Succesfully logged out <<<\n\n";
		return;
	default:
		system("cls");
		cout << " >>> Welcome to Admin tools <<<\n";
		cout << " 1. Edit users\n 2. Show statistic\n 3. Edit tests\n 4. Log Out\n";
		cerr << " error: wrong option, re-enter opt: "; cin >> adminChoise;
		break;
	}
}