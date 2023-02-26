#include "std.h"
#pragma once
template<typename T>
class Admin
{
private:
	string login;
	string password;
public:
	Admin(const string& login, const string& password);
	void deleteGuest(const T& guest);
};

template<typename T>
inline Admin<T>::Admin(const string& login, const string& password)
	:login(login), password(password)
{
}
