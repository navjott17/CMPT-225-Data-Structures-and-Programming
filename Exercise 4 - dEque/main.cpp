//SUBMITTED BY - NAVJOT KAUR (301404765)
//SUBMITTED TO - POOYA TAHERI
#include "Deque.h"
int main()
{
	Students s1("Navjot",301404765,3.4);
	Students s2("Baldeep",301202304,3.3);
	Students s3("Ritika",301203495,3.6);
	Students s4("Karam",301520423,3.5);
	Students s5("Nandita",301649252,3.7);
	Deque d;
	try
	{
		d.pushFront(s2);
		d.pushFront(s5);
		d.pushBack(s1);
		d.pushBack(s3);
		d.pushFront(s4);
		cout << "--------------------Displaying the data----------------" << endl;
		d.display();
		Students s6=d.peekFront();
		cout << endl << "The data at the front is : " << endl;
		s6.print(s6);
		cout << endl;
		Students s7=d.peekBack();
		cout << endl << "The data at the back is : " << endl;
		s7.print(s7);
		cout << endl;
		cout << "There are " << d.count() << " elements in the linked list." << endl;
		d.popFront();
		cout << endl << "--------------------After popping from front------------------------------" << endl;
		Students s8=d.peekFront();
		cout << endl << "The data at the front is : " << endl;
		s8.print(s8);
		Students s9=d.peekBack();
		cout << endl << "The data at the back is : " << endl;
		s9.print(s9);
		d.popBack();
		cout << endl << "---------------------After popping from back------------------------------" << endl;
		Students s10=d.peekFront();
		cout << endl << "The data at the front is : " << endl;
		s10.print(s10);
		Students s11=d.peekBack();
		cout << endl << "The data at the back is : " << endl;
		s11.print(s11);
		cout << endl << "---------------------Displaying the data-----------------------------------" << endl;
		d.display();
		cout << endl << "There are " << d.count() << " elements in the linked list." << endl;
		cout << endl;
		if(d.isEmpty())
			cout << "The linked list is empty" << endl;
		else
			cout << "The linked list is not empty" << endl;
		d.clear();
		cout << endl << "After clearing the linked list" << endl;
		cout << endl << "---------------------Displaying the data-----------------------------------" << endl;
		d.display();
		cout << endl << "There are " << d.count() << " elements in the linked list." << endl;
		cout << endl;
		if(d.isEmpty())
			cout << "The linked list is empty" << endl;
		else
			cout << "The linked list is not empty" << endl;
	}
	catch(int e)
	{
		cout <<  "ERROR : The linked list is empty. CAN NOT ACCESS THE DESIRED ELEMENT" << endl;
	}
	catch(...)
	{
		cout << "UNKNOWN ERROR FOUND!!!" << endl;
	}
	return 0;
}