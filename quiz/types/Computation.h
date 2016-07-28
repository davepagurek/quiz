#ifndef COMPUTATION_H
#define COMPUTATION_H

#include "../Question.h"

class Computation : public Question {
public:
	Computation(std::string q, std::string ans) : Question(q, ans, "comp") {}
};

#endif
