#pragma once
#include "LIB.h"

class Admin {
public:
	bool checkTrueSize(const str& login, int left, int right) const;
	bool checkFirstSymbol(const str& login) const;
	bool checkTrueLogin(str& login) const;
	bool getIsAdmin() const;

	void registerAdmin();
	void saveLPToFile(const str& login, const str& password) const;
private:
	string loginAdm, passwordAdm;
	bool isAdmin = false;
};