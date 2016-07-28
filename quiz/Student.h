#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
	Student(int id, std::string f, std::string l) : id_(id), first_name(f), last_name(l) {};

	// Accessors
	std::string getFirstName()	const {return first_name;}
	std::string getLastName()	const {return last_name;}
	int getID()					const {return id_;}

private:
	int id_;
	std::string first_name;
	std::string last_name;
};

#endif
