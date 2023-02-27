#include <iostream>
using namespace std;
#include "Guest.h"
#include "Admin.h"
int main()
{

	cout << "Choose  1 or 2 " << endl;
	cout << "1 = Guest  2 = Admin " << endl;

	int b;
	cin >> b;
	Guest a;
	Admin n;
	switch (b)
	{
	case 1:

		a.fill_register();
		break;
	case 2:
		n.RegistrAd();
		break;
	}
}
