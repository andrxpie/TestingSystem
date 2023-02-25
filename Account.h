#pragma once
#include "std.h"

struct Login {
	string _login;
	void setLogin(string& login);
};

class Account {
private:
	string _password;
	string _name;
	string _midname;
	string _surname;
	string _address;

};