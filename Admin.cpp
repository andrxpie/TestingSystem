#include "Admin.h"
#include "LIB.h"
void Admin::RegistrAd()
{
	
	cout << "\tEnter login (it must contain numbers, caps, etc, but without spaces) : ";
	cin >> loginAd;
	cout << "\tEnter yout password (ypu password must be difficult to hack) : ";
	cin >> passwordAd;
	cin.ignore();
	ofstream abc("ADMIN.txt");
	abc << loginAd << endl;
	abc << passwordAd << endl;

	
}

void Admin::loginAd()
{
	ifstream bcd("ADMIN.txt");
	string loginEB, passwordEB;
	string tmp;
	if (!bcd.is_open())
	{
		RegistrAd();
	}
	else
	{
		cin >> loginEB;
		bcd >> tmp;  
	}
}
