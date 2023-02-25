#include "Account.h"

int main() {
	system("color 0B");

	int choose;
	do {
		cout << " >>> Menu <<<\n\n";
		cout << " 1.Sing In\n 2.Log In\n 3.Exit\n";
		cout << " ?: "; cin >> choose;

		switch (choose) {
		case 1:
			
		default:
			cerr << " wrong option: " << choose << "\n";
			break;
		}
	} while (choose != 3);

	return 0;
}