#include "Test.h"



void Test::EditQuestion(Questions& a)
{
	str tmp;

	cout << "Enter new question" << endl;
	getline(cin, tmp);
	
	a.question = tmp;
}

void Test::AddQuestion()
{
	Questions tmp;
	int tmpnum;
	cout << "Enter your question" << endl;
	getline(cin, tmp.question);
	cout << "Enter number of answers " << endl;
	cin >> tmpnum;
	tmp.answers.resize(tmpnum);
	
	for (auto& i : tmp.answers)
	{
		cout << "Enter answer (put '!' at the beginning of correct answer)" << endl;
		getline(cin, i);
		if (i[0] == '!')
			tmp.correct_answer = i;
		i.erase(0);
	}

	test.push_back(tmp);
}

void Test::DelQuestion()
{
	string cinstr;
	
	
	cout << "Here is your questions. With the help of them, you can enter a few key words to find neariest question you wanna delete" << endl;

	for (auto& i : test)
		cout << i.question << endl;
	
	cout << "So, now it`s your turn to enter " << endl;
	getline(cin, cinstr);

	int max = 0;


	for (int i = 0; i < test.size() - 1; i++)
	{
		if (test.begin()[i].question.find(cinstr) > test.begin()[i + 1].question.find(cinstr))
			max = i;
		else
			max = i + 1;
	}

	test.erase(test.begin() + max);
	

}

void Test::load_data()
{
	ofstream load("Tests.txt");
	
	for (auto& i : test)
	{
		load << i.question << endl;
		load << i.correct_answer << endl;
		for (auto& k : i.answers)
		{
			load << k;
		}
	}

}

void Test::upload_data()
{
	ifstream download("Tests.txt");

	for (auto& i : test)
	{
		getline(download, i.question);
		getline(download, i.correct_answer);
		for (auto& k : i.answers)
		{
			getline(download, k);
			i.answers.push_back(k);
		}
	}
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
