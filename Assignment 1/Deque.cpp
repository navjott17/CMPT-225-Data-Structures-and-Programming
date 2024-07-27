#include "Deque.h"
//PRE: none
//POST: assigns the default value of -1 to both front and rear.
Deque::Deque()
{
	front=-1;
	rear=-1;
}

//PRE: deque should not be full.
//POST: pushes the element from the back of the deque.
void Deque::push_back(string a)
{
	if(front==(rear+1)%MAX)
		throw overflow_error("Deque is Full, can not push_back");
	if(front==-1 && rear==-1)
		front=rear=0;
	else
		rear=(rear+1)%MAX;
	arr[rear]=a;
	cout << a << " is enqueued from back in deque." << endl;
}

//PRE: deque should not be empty.
//POST: pops the element from the back of the deque.
void Deque::pop_back()
{
	if(front==-1)
		throw underflow_error("Deque is empty, can not pop_back");
	cout << peek_back() << " is dequeued from back from deque." << endl;
	if(front==rear)
		front=rear=-1;
	else
		rear=(MAX+rear-1)%MAX;
}

//PRE: deque should not be full.
//POST: pushes the element from the front of the deque.
void Deque::push_front(string a)
{
	if(front==(rear+1)%MAX)
		throw overflow_error("Deque is full, can not push_front");	
	if(front==-1 && rear==-1)
		front=rear=0;
	else if(front==0)
		front=MAX-1;
	else
		front--;
	arr[front]=a;
	cout << a << " is enqueued from front in deque." << endl;
}

//PRE: deque should not be empty
//POST: pops the element from the front of the deque.
void Deque::pop_front()
{
	if(front==-1 && rear==1)
		throw underflow_error("Deque is empty, can not pop_front");
	cout << peek_front() << " is dequeued from front from deque." << endl;
	if(front==rear)
		front=rear=-1;
	else
		front=(front+1)%MAX;
}

//PRE: deque should not be empty.
//POST: returns the element that is at the front of the deque.
string Deque::peek_front()
{
	if(empty())
		throw underflow_error("Deque is empty, can not return front element");
	else
		return arr[front];
}

//PRE: deque should not be empty.
//POST: returns the element that is at the back of the deque.
string Deque::peek_back()
{
	if(empty())
		throw underflow_error("Deque is empty, can not return back element");
	else
		return arr[rear];
}

//PRE: none
//POST: returns true if the deque is empty and false otherwise.
bool Deque::empty()
{
	if(front==-1 && rear==-1)
		return true;
	return false;
}

//PRE: none
//POST: returns true if the deque is full and false otherwise.
bool Deque::full()
{
	if(rear==front-1 && rear==front+1)
		return true;
	return false;
}