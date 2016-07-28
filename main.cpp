// Facade class
#include "quiz/Quiz.h"

using namespace std;

int main () {
	Quiz * q = new Quiz();
	q->getQuestions();
	q->getStudentInfo();
	q->start();
	delete q;
}
