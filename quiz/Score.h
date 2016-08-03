#ifndef SCORE_H
#define SCORE_H

#include <iostream>

class Score {
// Overloaded operators
friend Score& operator++(Score& s) {
	s.score_ += 1;
	return s;
}
friend std::ostream& operator<< (std::ostream& sout, const Score& s) {
	sout << s.score_ << "/" << s.max_;
	return sout;
}

public:
	Score(int m) : score_(0), max_(m) {}
	void increment_max () {
		max_ ++;
	}

private:
	int score_;
	int max_;
};

#endif
