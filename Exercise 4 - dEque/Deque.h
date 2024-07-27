//SUBMITTED BY - NAVJOT KAUR (301404765)
//SUBMITTED TO - POOYA TAHERI
#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Students
{
	string name;
	int student_id;
	double gpa;
	//PRE: NONE
	//POST: sets the default value of the member variables.
	Students()
	{
		this->name="N/A";
		this->student_id=0;
		this->gpa=0;
	}
	//PRE: NONE
	//POST: sets the values of parameters to the members variables of Students class.
	Students(const string name,const int student_id,const double gpa)
	{
		this->name=name;
		this->student_id=student_id;
		this->gpa=gpa;
	} 
	//PRE: NONE
	//POST: prints the elements of the Students parameter s.
	//PARAM: s is an object of Students class
	void print(Students s)
	{
		cout << "Student Name : " << s.name << endl;
		cout << "Student ID : " << s.student_id << endl;
		cout << "Student GPA : " << s.gpa << endl;
	}
};

struct Node
{
	Students data;
	Node* prev;
	Node* next;
};

class Deque
{
private:
	Node* front;
	Node* back;
public:
	Deque();
	void pushFront(Students s);
	void pushBack(Students s);
	void popFront();
	void popBack();
	Students peekFront();
	Students peekBack();
	void clear();
	bool isEmpty();
	int count();
	void display();
};