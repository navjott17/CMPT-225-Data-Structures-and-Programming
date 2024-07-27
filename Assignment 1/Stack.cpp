#include "Stack.h"

//PRE: none
//POST: top is made nullptr by default.
Stack::Stack()
{
	top=nullptr;
}

//PRE: none
//POST: returns true if the stack is empty and false otherwise.
bool Stack::empty()
{
	if(top==nullptr)
		return true;
	return false;
}

//PRE: none.
//POST: pushes the element to the stack.
void Stack::push(int data)
{
	Node* temp=new Node();
	temp->data=data;
	temp->next=top;
	top=temp;
	cout << data << " is pushed into the stack." << endl;
}

//PRE: stack should not be empty
//POST: pops the top element from the stack.
void Stack::pop()
{
	if(empty())
		throw underflow_error("Stack is Empty, can not pop");
	cout << peek() << " is popped from the stack." << endl;
	Node* temp=new Node();
	temp=top;
	top=top->next;
	temp->next=nullptr;
	delete temp;
}

//PRE: stack should not be empty.
//POST: returns the element that is at the top of the stack.
int Stack::peek()
{
	if(empty())
		throw underflow_error("Stack is Empty, can not peek");
	else
		return top->data;
}

//PRE: none
//POST: returns the number of elements in the stack.
int Stack::size()
{
	if(empty())
		return 0;
	int count=0;
	Node* temp=new Node();
	temp=top;
	for(int i=0;temp!=nullptr;i++)
	{
		count++;
		temp=temp->next;
	}
	return count;
}