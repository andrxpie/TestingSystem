#include "Account.h"

void Login::setLogin(string& login){
	ifstream logins 
	while()

	while (login.find_first_of("0123456789") != -1) {
		if (login.size() < 16) { this->_login = login; break; }
		else if(login.size() >= 16){
			system("cls");
			cerr << " error: login must be less/equal to 16 symbols\n";
			cout << " login: "; cin >> login;
		}
		else if (login.size() < 3) {
			system("cls");
			cerr << " error: login must be more then 3 symbols\n";
			cout << " login: "; cin >> login;
		}
	}
}
