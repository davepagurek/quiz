#ifndef TRUE_FALSE_H
#define TRUE_FALSE_H

#include <iostream>
#include "../Question.h"

class TrueFalse : public Question {

public:
	TrueFalse(std::string q, std::string ans) : Question(q, ans, "tf") {}

protected:
	virtual void print(std::ostream& sout) const {
	   sout << "Question: " << question_ << " [T/F]." << std::endl;
	   sout << "Answer: ";
	}
};

#endif
