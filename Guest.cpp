#include "Guest.h"
#include "LIB.h"

void Phone::fill_phone()
{
	string tmp;
	cout << "\t>>>>>Enter phone : ";
	try
	{
		cin >> tmp;
		set_number_phone(tmp);
	}
	catch (phone_exception& a)
	{
		cout << "Error : " << a.get_phone_error() << endl;
		terminate();
	}
}

void Phone::set_number_phone(const string& num)
{
	if (num.find("+380") == -1)
		throw phone_exception("Unknown region");
	if (num.size() != 13)
		throw phone_exception("Wrong number");

	for (int i = 1; i < num.size(); i++)
	{
		if (char(num[i]) < 48 or char(num[i]) > 57)
			throw phone_exception("Your num must contain only of numbers");
	}
	this->phone = num;
}

void Bio::set_name(string name)
{
	if (!isupper(name[0]))
		name[0] = char(name[0] - 32);

	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == ' ')
			throw name_exception("No spaces in name");

	}

	for (int i = 1; i < name.size(); i++)
	{
		if (char(name[i]) < 65 or (char(name[i]) > 90 and (char(name[i]) < 97)))
			throw name_exception("The name must contain only of latyn letters");
	}

	if (name.size() < 2)
		throw name_exception("The name must contain more than 2 symbols");
	if (name.size() > 12)
		throw name_exception("The name must contain less than 12 symbols");

	this->_name = name;
}

void Bio::set_surname(string surname)
{
	if (!isupper(surname[0]))
		surname[0] = char(surname[0] - 32);

	for (int i = 0; i < surname.size(); i++)
	{
		if (surname[i] == ' ')
		{
			surname[i] = '-';
			if (!isupper(surname[i + 1]))
				surname[i + 1] = char(surname[i + 1] - 32);
		}
	}

	for (int i = 1; i < surname.size(); i++)
	{
		if (char(surname[i]) < 97 and char(surname[i]) > 122)
		{
			throw surname_exception("The surname must contain only of latyn letters");
		}
	}

	if (surname.size() < 2)
		throw surname_exception("The surname must contain more than 2 symbols");
	if (surname.size() > 24)
		throw surname_exception("The surname must contain less than 24 symbols");

	this->_surname = surname;
}

void Bio::set_last_name(string last_name)
{
	if (!isupper(last_name[0]))
		last_name[0] = char(last_name[0] + 32);

	for (int i = 0; i < last_name.size(); i++)
	{
		if (last_name[i] == ' ')
			throw last_name_exception("No spaces in name");

	}


	for (int i = 1; i < last_name.size(); i++)
	{
		if (char(last_name[i]) < 65 or (char(last_name[i]) > 90 and (char(last_name[i]) < 97)))
			throw last_name_exception("The name must contain only of latyn letters");
	}

	if (last_name.find("ovych") == -1)
		throw last_name_exception("Incorrect last name input");
	if (last_name.size() < 2)
		throw last_name_exception("The name must contain more than 2 symbols");
	if (last_name.size() > 12)
		throw last_name_exception("The name must contain less than 12 symbols");

	this->_last_name = last_name;
}

void Bio::fill_data()
{
	string tmpname, tmpsurname, tmplastname;

	cout << "Enter name : ";

	try
	{
		getline(cin, tmpname);
		set_name(tmpname);
	}
	catch (name_exception& a)
	{
		cout << "Error : " << a.get_name_error() << endl;
		terminate();
	}
	cout << "\t>>>Succesfully! Now we call you " << _name << endl;

	cout << _name << ", enter your surname" << endl;
	cout << "Surname : ";
	try
	{
		getline(cin, tmpsurname);
		cin.ignore();
		set_surname(tmpsurname);
	}
	catch (surname_exception& a)
	{
		cout << "Error : " << a.get_surname_error() << endl;
		terminate();
	}

	cout << "Enter your last name : ";
	try
	{
		getline(cin, tmplastname);
		set_last_name(tmplastname);
	}
	catch (last_name_exception& a)
	{
		cout << "Error : " << a.get_last_name_error() << endl;
		terminate();
	}
}

void Home_Address::set_street(string street)
{
	if (!isupper(street[0]))
		street[0] = char(street[0] + 32);
}

void Home_Address::fill_address()
{
	cin.ignore();
	cout << "\t>>>>>> Now, enter your home address... <<<<<<" << endl;
	getline(cin, street);
}

str Guest::codestr(str& _word)
{
	for (int i = 0; i < _word.size(); i++)
	{
		if (_word[i] >= char(65) and _word[i] <= char(90))
			_word[i] = char(_word[i] + 2);
		else if (_word[i] >= char(97) and _word[i] <= char(111))
			_word[i] = char(_word[i] - 64);
		else if (_word[i] >= char(112) and _word[i] <= char(122))
			_word[i] = char(_word[i] + 2);
	}

	return _word;
}

str Guest::uncodestr(str& _word) {
	for (int i = 0; i < _word.size(); i++) {
		if (_word[i] >= char(67) and _word[i] <= char(92)) _word[i] = char(_word[i] - 2);
		else if (_word[i] >= char(33) and _word[i] <= char(47)) _word[i] = char(_word[i] + 64);
		else if (_word[i] >= char(114) and _word[i] <= char(124)) _word[i] = char(_word[i] - 2);
	} return _word;
}

void Guest::load_user_data() {
	ofstream load("Users.txt", ios::app);
	if (load.is_open()) {
		load << codestr(login) << endl;
		load << codestr(password) << endl;
		load << _name << endl;
		load << _surname << endl;
		load << _last_name << endl;
		load << phone << endl;
		load << street << endl;
	} load.close();
}

void Guest::upload_user_data() {
	string a = "Users.txt";
	ifstream upload(a);
	upload.close();
}

bool Guest::checkLogin(const str& login) {
	ifstream checkL("Admin.txt"); string tmp; checkL >> tmp; checkL.close();
	if (login == uncodestr(tmp)) return true; return false;
}

bool Admin::checkPassword(const str& password) {
	ifstream checkP("Guests.txt"); string tmp; checkP >> tmp >> tmp; checkP.close();
	if (password == uncodeStr(tmp)) return true; return false;
}

void Guest::registerGuest() {
	cout << "\t>>>>>>>>>> Welcome to Vseosvita 2.0 <<<<<<<<<<" << endl;
	cout << "\tLet`s make an account for you" << endl;

	cout << "\tEnter login (it must contain numbers, caps, etc, but without spaces) : ";
	cin >> login;
	cout << "\tEnter yout password (ypu password must be difficult to hack) : ";
	cin >> password;
	cin.ignore();
	cout << endl;
	fill_data();
	cout << endl;
	fill_phone();
	cout << endl;
	fill_address();
}

void Guest::loginGuest(){
	cout << " login: "; str login; cin >> login;
	while (checkLogin(login) == false) { system("cls"); cerr << " incorrect login: not found, re-enter: "; cin >> login; }

	system("cls");
	cout << " password: "; str password; cin >> password;
	for (size_t i = 0; i < 6; i++) {
		if (checkPassword(password) == false) { system("cls"); cerr << " incorrect password: not match, re-enter (" << 6 - i << " tries left): "; cin >> password; }
		else { guestTools(); break; }
	}
}

void Guest::guestTools() {
	cout << " >>> Guest tools <<<\n";
	cout << " 1. Do test\n 2. See results\n 3. See progress\n 4. Log Out\n";
	cout << " ?: "; int guestChoise; cin >> guestChoise;
	switch (guestChoise) {
	case 1:
		//doTest();
		break;
	case 2:
		//results();
		break;
	case 3:
		//progress();
		break;
	case 4:
		return;
	default:
		system("cls");
		cout << " >>> Guest tools <<<\n";
		cout << " 1. Do test\n 2. See results\n 3. See progress\n";
		cerr << " error: wrong option, re-enter opt: "; cin >> guestChoise;
		break;
	}
}

void Guest::doTest() {
	if (themes.size() == 0) { system("cls"); cout << " >>> No themes found <<<\n"; return; }

	system("cls");
	cout << " >>> Themes <<<\n";
	for (size_t i = 0; i < themes.size(); i++) cout << " " << i + 1 << ": " << themes[i] << "\n";

}

str Guest::getLogin() const { return login; }