#include "Test.h"



void Test::AddQuestion()
{
	Questions tmp;
	cout << "Enter your question" << endl;
	getline(cin, tmp.question);

	test.push_back(tmp);
}

void Test::load_data()
{
	ofstream load("Tests.txt");

}

void Test::upload_data()
{
	//ifstream download("")
}

void Test::print_question() const
{
	for (auto& i : test)
	{
		cout << " >>> " << i.question << endl;
		for (auto& k : i.answers)
		{
			cout << k << endl;
		}
	}
}
