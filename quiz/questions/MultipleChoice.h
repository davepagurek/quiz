#ifndef MULTIPLE_CHOICE_H
#define MULTIPLE_CHOICE_H

#include <string>
#include "Question.h"

class MultipleChoice : public Question {
public:
	MultipleChoice(std::string q, std::string a, std::string b, std::string c, std::string d, std::string ans)
	: a_(a), b_(b), c_(c), d_(d) , Question(q, ans, "mc") {}

	// Accessors
	std::string a() const {return a_;}
	std::string b() const {return b_;}
	std::string c() const {return c_;}
	std::string d() const {return d_;}

private:
	std::string a_;
	std::string b_;
	std::string c_;
	std::string d_;
};

#endif
