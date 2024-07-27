//SUBMITTED BY- Navjot Kaur (301404765)
//SUBMITTED TO- Pooya Taheri

#pragma once
#include <iostream>
using namespace std;

class Sequence
{
public:
	Sequence();
	void insert(const double& num);
	void clear();
	int size() const;
	double stdDeviation() const;
};
