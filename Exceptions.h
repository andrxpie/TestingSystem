#pragma once
#include "LIB.h"
#include "Guest.h"

class name_exception
{
	string w_name;
public:
	name_exception(const string& wrongname) :w_name(wrongname) {}

	const string& get_name_error() const { return w_name; }
};

class surname_exception
{
	string w_surname;
public:
	surname_exception(const string& wrongsurname) :w_surname(wrongsurname) {}
	const string& get_surname_error() const { return w_surname; }
};

class last_name_exception
{
	string w_last_name;
public:
	last_name_exception(const string& wronglastname) :w_last_name(wronglastname) {}
	const string& get_last_name_error() const { return w_last_name; }
};

class phone_exception
{
	string w_phone;
public:
	phone_exception(const string& wrongphone) :w_phone(wrongphone) {}
	const string& get_phone_error() const { return w_phone; }
};

class street_exception
{
	string w_street;
public:
	street_exception(const string& wrongstreet) :w_street(wrongstreet) {}
	const string& get_street_error() const { return w_street; }
}; 