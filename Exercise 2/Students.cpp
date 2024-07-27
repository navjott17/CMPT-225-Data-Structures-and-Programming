//SUBMITTED BY - NAVJOT KAUR
//SUBMITTED TO - POOYA TAHERI
#include "Students.h"

Students::Students()
{
	this->name="N/A";
	this->score=0;
}

Students::Students(string name,double score)
{
	this->name=name;
	this->score=score;
}

Students::~Students()
{
}

string Students::getName() const
{
	return name;
}

double Students::getScore() const
{
	return score;
}

void Students::setName(string name)
{
	this->name=name;
}

void Students::setScore(double score)
{
	this->score=score;
}