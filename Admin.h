#include "std.h"
#pragma once
#include "Guest.h"

class Admin
{
private:
	string login;
	string password;
	void check_pass(const string& pass);
	void check_login(const string& log);
public:
	Admin() = default;
	void set_login();
	void set_password();
	void changeGuest(const Guest& guest);
}