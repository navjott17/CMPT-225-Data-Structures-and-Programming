//SUBMITTED BY - NAVJOT KAUR(301404765)
//SUBMITTED TO - POOYA TAHERI
#pragma once
#include <iostream>
#include <exception>
using namespace std;

#define MAX 1000
template<class T>
class MyStack
{
	int top;
	T a[MAX];
public:
	MyStack(){ top=-1;}
	void push(T x);
	T pop();
	T peek();
	bool isEmpty();
	bool isFull();
	int count();
	void display();
};