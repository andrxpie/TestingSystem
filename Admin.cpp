#include "Admin.h"

void Admin::set_login()
{
	string login;
	cout << "Enter a login: ";
	cin >> login;
	check_login(login);
}

void Admin::set_password()
{
	string password;
	cout << "enter a password: ";
	cin >> password;
	check_pass(password);
}

void Admin::changeGuest(const Guest& guest)
{
	cout << "enter a new name: ";
	//cin>>guest.
}

void Admin::check_pass(const string& pass)
{
	if (pass != " ")
	{
		this->password = pass;
	}
}

void Admin::check_login(const string& log)
{
	if (log != " ")
	{
		this->login = log;
	}
}
