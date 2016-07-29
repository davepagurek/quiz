#ifndef QUIZ_H
#define QUIZ_H

#include <fstream>
#include <vector>

#include "Score.h"
#include "Question.h"

class Quiz {
public:
	Quiz();
	~Quiz();

	// Void game methods
	void start();
	void getQuestions();
	void askQuestion(Question * &q);

private:
	std::ifstream file;
	Score score_;
	std::vector<Question *> questions_;
	std::vector<Question *> incorrect_;
};

#endif
