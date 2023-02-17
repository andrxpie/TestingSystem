#include "User.h"

string User::getLogin() const
{
    return login;
}

string User::getPassword() const
{
    return password;
}

bool User::getMode() const
{
    return isAdmin;
}

void User::setLogin(string& login)
{
    if (!login.empty()) {
        if (login.find_first_not_of("0123456789"))
            this->login = login;
        else
            cerr << " num can`t be first int login!";
    }
    else
        cerr << " error login";
}