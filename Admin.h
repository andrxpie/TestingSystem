#pragma once
#include "LIB.h"
#include "Guest.h"
#include "Test.h"

class Admin {
public:
	bool checkTrueSize(const str& login, int left, int right) const;
	bool checkFirstSymbol(const str& login) const;
	bool checkTrueLogin(str& login) const;
	bool getIsAdmin() const;
	bool checkLogin(const str& login);
	bool checkPassword(const str& password);

	void registerAdmin();
	str codeSTRING(str& word);
	str uncodeSTRING(str& word);
	void loginAdmin();
	void saveLPToFile(const str& login, const str& password) const;

	void adminTools();
	void editUsers();
	void addGuest();
	void addGuest(Guest a);
	void delGuest();

private:
	str loginAdm, passwordAdm;
	bool isAdmin = false;
	vector <class Guest> guests;
	vector <Test> tests;
};