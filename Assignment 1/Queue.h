#pragma once
#include <iostream>
#include <exception>
using namespace std;
#define SIZE 100
class Queue
{
	char arr[SIZE];
	int front;
	int rear;
public:
	Queue();
	void push(char a);
	void pop();
	char peek();
	bool empty();
	bool full();
};