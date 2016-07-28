// Quiz facade class which interacts with all other classes in application

#include <assert.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <typeinfo>

#include "Score.h"
#include "Student.h"
#include "Quiz.h"

#include "questions/Question.h"
#include "questions/MultipleChoice.h"
#include "questions/TrueFalse.h"
#include "questions/Computation.h"

using namespace std;

// Constructor: init ifstream
Quiz::Quiz() : file("quiz/questions/questions.txt"), score_(0), student_(0,"","") {}

// Destructor: free up memory allocated
Quiz::~Quiz () {
	for (auto q : questions_) {
		delete q;
	}
}

// Start the quiz
void Quiz::start () {
	for (auto q : questions_) {
		askQuestion(q);
	}
	cout << "Student: " << student_.getID() << endl;
	cout << "Your score is: " << score_ << "." << endl;
}

// Populate questions_ with questions from questions.txt
void Quiz::getQuestions() {
	if (file.fail()) {
		cout << "Couldn't get questions." << endl;
	} else {
		string keyword, answer, question;

		while (getline(file, keyword)) {
			getline(file, question);
			if (keyword == "Question: Multiple Choice") {
				// get four multiple choice and answer
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
	score_ = Score(questions_.size());
}

// Make new student object
void Quiz::getStudentInfo () {
	int id;
	string first_name, last_name;

	cout << "*************" << endl;
	cout << "CS 247 - Quiz" << endl;
	cout << "*************" << endl;
	cout << "Please enter your student information below:" << endl;
	cout << "First Name: ";
	cin >> first_name;
	cout << "Last Name: ";
	cin >> last_name;
	cout << "ID Number: ";
	cin >> id;
	cout << endl;

	student_ = Student(id, first_name, last_name);
}

// Ask the next quesiton in sequence
void Quiz::askQuestion (Question * &q) {
	string ans;

	if (q->type() == "mc") {
		cout << "Question: " << q->question() << endl;
		cout << q->a() << endl;
		cout << q->b() << endl;
		cout << q->c() << endl;
		cout << q->d() << endl;
		cout << "Answer: ";
		cin >> ans;
	} else if (q->type() == "tf") {
		cout << "Question: " << q->question() << " [T/F]." << endl;
		cout << "Answer: ";
		cin >> ans;
		transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
	} else if (q->type() == "comp") {
		cout << "Question: " << q->question() << "." << endl;
		cout << "Answer: ";
		cin >> ans;
	}

	if (ans == q->answer()) {
		cout << "Correct Answer!" << endl;
		++score_;
	} else {
		cout << "Incorrect, the answer was: " << q->answer() << "." << endl;
	} cout << endl;
}
