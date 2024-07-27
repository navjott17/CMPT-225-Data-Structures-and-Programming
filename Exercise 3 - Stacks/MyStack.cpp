//SUBMITTED BY - NAVJOT KAUR(301404765)
//SUBMITTED TO - POOYA TAHERI
#include "MyStack.h"

//PRE: stack should not be full.
//POST: insertes data at the top of the stack.
//PARAM: x = T data type parameter which is pushed into stack.
template<class T>
void MyStack<T>::push(T x)
{
	if(top>=MAX-1)
		throw overflow_error("Stack Overflow");
	else
	{
		a[++top]=x;
	}
}

//PRE: stack should not be empty.
//POST: deletes and returns data from the top of the stack
template<class T>
T MyStack<T>::pop()
{
	if(top<0)
		throw underflow_error("Stack Underflow");
	else
	{
		T x=a[top--];
		return x;
	}
}

//PRE: stack should not be empty.
//POST: returns the element of the stack which is at the top of the stack.
template<class T>
T MyStack<T>::peek()
{
	if(top<0)
		throw underflow_error("Stack is Empty");
	else
	{
		T x=a[top];
		return x;
	}
}

//PRE: none
//POST: returns true if the stack is empty and false otherwise.
template<class T>
bool MyStack<T>::isEmpty()
{
	return (top<0);
}

//PRE: none
//POST: returns true if the stack is full and false otherwise.
template<class T>
bool MyStack<T>::isFull()
{
	return (top>=MAX-1);
}

//PRE: none
//POST: returns the number of elements of the stack.
template<class T>
int MyStack<T>::count()
{
	if(isEmpty())
		return 0;
	return (top+1);
}

//PRE: none
//POST: prints the elements of the stack.
template<class T>
void MyStack<T>::display()
{
	if(isEmpty())
		cout << "The Stack is Empty" << endl;
	cout << endl << endl;
	cout << "The stack has the following elements:" << endl;
	for(int i=0;i<=top;i++)
	{
		if(i==top)
		{
			cout << a[i] << endl;
			return;
		}
		cout << a[i] << ", " ;
	}
	cout << endl << endl;
}