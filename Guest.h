#pragma once
#include "LIB.h"
#include "Exceptions.h"
#include "Admin.h"
class Bio
{
protected:
	string _name;
	string _surname;
	string _last_name;
	void set_name(string name);
	void set_surname(string surname);
	void set_last_name(string last_name);
	void fill_data();

};

class Phone
{
protected:
	string phone;
	void fill_phone();
	void set_number_phone(const string& num);

};

class Home_Address
{
protected:
	string street;
	void set_street(string street);
	void fill_address();

};

class Guest : public Home_Address, Phone, Bio {
	string login, password;
	vector<int> marks;
protected:
	str codestr(str& _word);
	str uncodestr(str& _word);
	void upload_user_data();
public:
	bool checkLogin(const str& login);
	bool checkPassword(const str& password);

	void load_user_data();
	void registerGuest();
	void loginGuest();
	void guestTools();
	str getLogin() const;
};
