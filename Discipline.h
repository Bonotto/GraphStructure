//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_DISCIPLINE_H
#define PROJECT_DISCIPLINE_H

#include <string>

using namespace std;

class Discipline
{
public:
	Discipline(string name, size_t credit);
	~Discipline();
	
	string mName;
	size_t mCredit;
};

Discipline::Discipline(string name, size_t credit) :
	mName(name),
	mCredit(credit)
{

}

Discipline::~Discipline()
{

}

#endif