//SUBMITTED BY - NAVJOT KAUR(301404765)
//SUBMITTED TO - POOYA TAHERI
#include "MyStack.h"
#include "MyStack.cpp"

int main()
{
	MyStack<int> s;
	try
	{
		s.push(10);
		cout << s.peek() << " is pushed to the stack" << endl;
		s.push(20);
		cout << s.peek() << " is pushed to the stack" << endl;
		s.push(30);
		cout << s.peek() << " is pushed to the stack" << endl;
		s.push(40);
		cout << s.peek() << " is pushed to the stack" << endl;
		cout << endl << endl;
		cout << s.pop() << " is popped from the stack" << endl;
		cout << s.pop() << " is popped from the stack" << endl;
		cout << s.pop() << " is popped from the stack" << endl;
		cout << endl << endl;
		s.push(-50);
		cout << s.peek() << " is pushed to the stack" << endl;
		s.push(5);
		cout << s.peek() << " is pushed to the stack" << endl;
		if(s.isEmpty())
			cout << endl << "The stack is empty" << endl << endl;
		if(s.isFull())
			cout << endl << "The stack is full" << endl << endl;
		cout << endl << "There are " << s.count() << " elements in the stack." << endl;
		s.display();
		cout << endl << endl;
	}
	catch(overflow_error &err)
	{
		cout << "ERROR FOUND : ";
		cout << err.what() << endl;
	}
	catch(underflow_error &err)
	{
		cout << "ERROR FOUND : ";
		cout << err.what() << endl;
	}
	catch(...)
	{
		cout << "ERROR FOUND : ";
		cout << "UNKNOWN ERROR CAUGHT!!!" << endl;
	}
	return 0;
}
