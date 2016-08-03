#ifndef QUIZ_H
#define QUIZ_H

#include <fstream>
#include <vector>

#include "Score.h"
#include "Question.h"

class Quiz {
public:
	Quiz(std::string, int seed);
	~Quiz();

	// Void game methods
	void start();
	void end();
	void getQuestions();
	void askQuestion(Question * &q);

private:
	int seed_;
	std::ifstream file;
	Score score_;
	std::vector<Question *> questions_;
	std::vector<Question *> incorrect_;
};

#endif
