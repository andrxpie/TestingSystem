#pragma once
#include "LIB.h"
#include "Guest.h"

class Admin {
public:
	bool checkTrueSize(const str& login, int left, int right) const;
	bool checkFirstSymbol(const str& login) const;
	bool checkTrueLogin(str& login) const;
	bool getIsAdmin() const;
	bool checkLogin(const str& login);
	bool checkPassword(const str& password);

	void registerAdmin();
	str codeWord(str& word);
	str uncodeWord(str& word);
	void loginAdmin();
	void saveLPToFile(const str& login, const str& password) const;
	void adminTools();
private:
	str loginAdm, passwordAdm;
	bool isAdmin = false;
	vector<Guest>* guests;
};