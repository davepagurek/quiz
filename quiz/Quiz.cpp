#include <assert.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <typeinfo>

#include "Score.h"
#include "Quiz.h"

#include "Question.h"
#include "types/MultipleChoice.h"
#include "types/TrueFalse.h"
#include "types/Computation.h"

using namespace std;

// Constructor: init ifstream
Quiz::Quiz (string file, int s) : file("questions/" + file + ".txt"), score_(0), seed_(s) {}

// Destructor: free up memory allocated
Quiz::~Quiz () {
	for (auto q : questions_) {
		delete q;
	}
}

// Random number generator with seed
int myrandom (int i) { return rand() % i; }

// Start the quiz
void Quiz::start () {
	for (auto q : questions_) {
		askQuestion(q);
	}
	end();
}

void Quiz::end () {
	cout << "Your score is: " << score_ << "." << endl;
	cout << endl << "Incorrect questions:" << endl << endl;

	Score inc_score(incorrect_.size());
	string ans;

	// Go through incorrect questions again
	for (auto q : incorrect_) {
		cout << q;
		cin >> ans;
		transform(ans.begin(), ans.end(), ans.begin(), ::toupper);

		if (ans == q->answer()) {
			cout << "Correct Answer!" << endl << endl;
			++inc_score;
		} else {
			cout << "The answer was: " << q->answer() << endl << endl;
		}
	}
	cout << "Your scored " << inc_score << " when asked the questions again." << endl;

	exit(0);
}

// Populate questions_ with questions from questions.txt
void Quiz::getQuestions () {
	srand (seed_);

	if (file.fail()) {
		cout << "Couldn't get questions." << endl;
	} else {
		string keyword, answer, question;

		while (getline(file, keyword)) {
			getline(file, question);
			if (keyword == "Question: Multiple Choice") {
				string a,b,c,d;
				getline(file, a);
				getline(file, b);
				getline(file, c);
				getline(file, d);
				getline(file, answer);

				MultipleChoice * q = new MultipleChoice(question, a, b, c, d, answer);
				questions_.push_back(q);
			} else if (keyword == "Question: True/False") {
				getline(file, answer);
				TrueFalse * q = new TrueFalse(question, answer);
				questions_.push_back(q);
			} else if (keyword == "Question: Computation") {
				getline(file, answer);
				Computation * q = new Computation(question, answer);
				questions_.push_back(q);
			}
		}
	}
	random_shuffle (questions_.begin(), questions_.end(), myrandom);
}

// Ask the next quesiton in sequence
void Quiz::askQuestion (Question * &q) {
	string ans;

	cout << q;
	cin >> ans;
	transform(ans.begin(), ans.end(), ans.begin(), ::toupper);

	if (ans == "EXIT") {
		cout << endl;
		end();
	} else if (ans == q->answer()) {
		cout << "Correct Answer!" << endl;
		++score_;
	} else {
		cout << "Incorrect, the answer was: " << q->answer() << "." << endl;
		incorrect_.push_back(q);
	} cout << endl;
	score_.increment_max();
}
