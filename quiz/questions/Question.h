#ifndef QUESTION_H
#define QUESTION_H

#include<string>

class Question {
public:
	Question(std::string q, std::string ans, std::string t) : question_(q), answer_(ans), type_(t) {}

	// Virtual Accessors
	virtual std::string a() const {return "";}
	virtual std::string b() const {return "";}
	virtual std::string c() const {return "";}
	virtual std::string d() const {return "";}

	// Accessors
	std::string question() 	const {return question_;}
	std::string answer() 	const {return answer_;}
	std::string type() 		const {return type_;}

protected:
	std::string question_;
	std::string answer_;

private:
	std::string type_;
};

#endif
