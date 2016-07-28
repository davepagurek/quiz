#ifndef TRUE_FALSE_H
#define TRUE_FALSE_H

#include "../Question.h"

class TrueFalse : public Question {
public:
	TrueFalse(std::string q, std::string ans) : Question(q, ans, "tf") {}
};

#endif
