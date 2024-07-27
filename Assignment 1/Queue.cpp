#include "Queue.h"

//PRE: none
//POST: assigns the default value of -1 to both front and rear.
Queue::Queue()
{
	front=-1;
	rear=-1;
}

//PRE: queue should not be full.
//POST: pushes the element from the back of the queue.
void Queue::push(char a)
{
	if(full())
		throw overflow_error("Queue is full, can not push");
	else
	{
		if(empty())
			front=rear=0;
		else
			rear++;
		arr[rear]=a;
	}
	cout << a << " is pushed into the queue." << endl;
}

//PRE: queue should not be empty
//POST: pops the element from the front of the queue.
void Queue::pop()
{
	if(empty())
		throw underflow_error("Queue is Empty, can not pop");
	else
	{
		cout << peek() << " is popped from the queue." << endl;
		if(front==rear)
			front=rear=-1;
		else
			front++;
	}
}

//PRE: queue should not be empty.
//POST: returns the element that is at the front of the queue.
char Queue::peek()
{
	if(empty())
		throw underflow_error("Queue is Empty, can not peek");
	else
	{
		char a=arr[front];
		return a;
	}
}

//PRE: none
//POST: returns true if the queue is empty and false otherwise.
bool Queue::empty()
{
	if(front==-1 && rear==-1)
		return true;
	return false;
}

//PRE: none
//POST: returns true if the queue is full and false otherwise.
bool Queue::full()
{
	if(rear==SIZE-1)
		return true;
	return false;
}
