#pragma once
#include <iostream>
#include <exception>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(){}
	Node(int x)
	{
		this->data=x;
		this->next=nullptr;
	}
};

class Stack
{
	Node* top;
public:
	Stack();
	bool empty();
	void push(int data);
	void pop();
	int peek();
	int size();
};