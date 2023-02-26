#pragma once
#include "std.h"
class Guest
{
private:
	string name;
	string surname;
	string last_name;
	string adress; 
	int phone;
public:
	Guest(const string& name, const string& surname, const string& last_name,const string& adress ,int phone);

};

Guest::Guest(const string& name, const string& surname, const string& last_name,const string& adress, int phone)
	:name(name), surname(surname),  last_name(last_name), adress(adress), phone(phone)
{}
