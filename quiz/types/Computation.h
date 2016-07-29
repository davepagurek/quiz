#ifndef COMPUTATION_H
#define COMPUTATION_H

#include <iostream>
#include "../Question.h"

class Computation : public Question {

public:
	Computation(std::string q, std::string ans) : Question(q, ans, "comp") {}

protected:
	virtual void print(std::ostream& sout) {
		sout << "Question: " << question_ << "." << std::endl;
		sout << "Answer: ";
	}
};

#endif
