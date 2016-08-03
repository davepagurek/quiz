// Facade class
#include "quiz/Quiz.h"

int main (int argc, char** argv) {
	Quiz * q = new Quiz(argv[1], atoi(argv[2]));
	q->getQuestions();
	q->start();
	delete q;
}
