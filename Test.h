#pragma once
#include "LIB.h"

struct Questions {
	string question;	
	string correct_answer;
	vector<string> answers;
};

class Test {
public:
	void EditQuestion(Questions& a);
	void AddQuestion();
	void DelQuestion();
	void load_data();
	void upload_data();
	void print_question() const;

private:
	vector<Questions> test;
};