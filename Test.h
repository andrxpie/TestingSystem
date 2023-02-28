#pragma once
#include "LIB.h"

struct Questions
{
	string question;
	vector<string> answers;
};

class Test
{
	vector <Questions> test;
public:
	void AddQuestion();
	void load_data();
	void upload_data();
	void print_question() const;
};