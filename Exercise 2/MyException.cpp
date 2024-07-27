//SUBMITTED BY - NAVJOT KAUR
//SUBMITTED TO - POOYA TAHERI
#include "MyException.h"

MyException::MyException()
{
}

MyException::MyException(char* error)
{
	this->error=error;
}

MyException::~MyException()
{
}

char const* MyException::what() const
{
	return error;
}
