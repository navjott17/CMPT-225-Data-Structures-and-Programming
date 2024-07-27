//SUBMITTED BY - NAVJOT KAUR
//SUBMITTED TO - POOYA TAHERI
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

class MyException:public exception
{
private:
	char* error;
public:
	MyException();
	MyException(char* error);
	~MyException();
	virtual char const* what() const; 
};

