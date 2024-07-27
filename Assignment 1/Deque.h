#pragma once
#include <iostream>
using namespace std;
#define MAX 5
class Deque
{
	string arr[MAX];
	int front;
	int rear;
public:
	Deque();
	void push_back(string a);
	void pop_back();
	void push_front(string a);
	void pop_front();
	string peek_front();
	string peek_back();
	bool empty();
	bool full();
};