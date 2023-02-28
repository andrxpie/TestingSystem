#pragma once
#include "LIB.h"

struct Questions
{
	string question;	
	string correct_answer;
	vector<string> answers;
};

class Test
{
	vector <Questions> test;
public:

	void EditQuestion(Questions& a);
	void AddQuestion();
	void DelQuestion();
	void load_data();
	void upload_data();
	void print_question() const;
};