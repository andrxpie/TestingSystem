#pragma once
#include "std.h"


class Bio
{
	string name;
	string surname;
	string last_name;
public:
	void setName(const string& name);
	void setSurname(const string& surname);
	void setLastName(const string& last_name);
};

class Phone
{
	string phone;
	void check_num(const string num);
public:
	void setPhone(const string& num);
};

class Adress
{
	string adress;
public:
	void setAdress(const string adr);
};

class Guest
{
protected:
	vector<tuple<Bio, Phone, Adress>> guests;
public:
	Guest(Bio bio, Phone phone,Adress adress);
	void print()const;
	string getName()const;
	string getSurname()const;
	string getLastName()const;
	void setName(const string& name);
	void setSurname(const string& surname);
	void setLastName(const string& last_name);
	void setAdress(const string adr);
	void setPhone(const string& num);
};