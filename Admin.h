#pragma once
#include "LIB.h"

class Admin {
public:
	void registerAdmin();
	void saveLPToFile();
	bool checkTrueSize(const str& login, int left, int right);
	bool checkFirstSymbol(const str& login);
	bool checkTrueLogin(str& login);
private:
	string loginAdm, passwordAdm;
};