//SUBMITTED BY - NAVJOT KAUR
//SUBMITTED TO - POOYA TAHERI
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

class Students
{
private:
	string name;
	double score;
public:
	Students();
	Students(string name, double score);
	~Students();
	string getName() const;
	double getScore() const;
	void setName(string name);
	void setScore(double score);
};

