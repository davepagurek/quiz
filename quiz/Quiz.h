#ifndef QUIZ_H
#define QUIZ_H

#include <fstream>
#include <vector>

#include "Score.h"
#include "Student.h"
#include "questions/Question.h"

class Quiz {
public:
	Quiz();
	~Quiz();

	// Void game methods
	void start();
	void getQuestions();
	void askQuestion(Question * &q);
	void getStudentInfo();

private:
	std::ifstream file;
	Student student_;
	Score score_;
	std::vector<Question *> questions_;
};

#endif
