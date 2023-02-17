#pragma once
#include "std.h"

class User
{
public:
	User(const string& login = "", const string& password = "", bool isAdmin = 0);

	string getLogin() const;
	string getPassword() const;
	bool getMode() const;

	void setLogin(string& login);
	void setPassword(const string& password);
private:
	string login;
	string password;
	bool isAdmin;
};