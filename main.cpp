#include "Guest.h"
#include "Admin.h"

int main() {
	int user, singUp; Admin admin; Guest guest;
	do {
		cout << " >>> Menu <<<\n";
		cout << " 1. Sing Up\t2.Log In\n 3. Exit";
		cout << " ?: "; cin >> user;
		switch (user) {
		case 1:
			system("cls");
			cout << " >>> Chose person <<<\n";
			cout << " 1. Admin\t2. Guest\n";
			cout << " ?: "; cin >> singUp;
			switch (singUp){
			case 2:
				guest.fill_register();
				break;
			case 1:
				system("cls");
				admin.registerAdmin();
				break;
			}
		case 3:
			cout << "\n >>> Bye <<<\n";
			return 0;
		default:
			cerr << " error: wrong option, re-enter opt: "; cin >> user;
			break;
		}
	} while (user != 3);
}