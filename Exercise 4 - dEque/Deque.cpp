//SUBMITTED BY - NAVJOT KAUR (301404765)
//SUBMITTED TO - POOYA TAHERI
#include "Deque.h"
//PRE: NONE
//POST: sets the default value of front and back pointers to nullptr.
Deque::Deque()
{
	front=nullptr;
	back=nullptr;
}
//PRE: NONE
//POST: inserts the new data of student to the front of linked list.
//PARAM: s is the object of Students class that is being inserted.
void Deque::pushFront(Students s)
{
	Node* t=new Node;
	t->data=s;
	t->prev=nullptr;
	t->next=nullptr;
	if(front==nullptr && back==nullptr)
	{
		front=t;
		back=t;
	}
	else
	{
		t->next=front;
		front->prev=t;
		front=t;
	}
}
//PRE: NONE
//POST: inserts the new data of student to the back of linked list.
//PARAM: s is the object of Students class that is being inserted.
void Deque::pushBack(Students s)
{
	Node* t=new Node;
	t->data=s;
	t->prev=nullptr;
	t->next=nullptr;
	if(front==nullptr && back==nullptr)
	{
		front=t;
		back=t;
	}
	else
	{
		back->next=t;
		t->prev=back;
		back=t;
	}
}
//PRE: The linked list should not be empty and this function is not returning anything.
//POST: removes the data of student from the front of the linked list.
void Deque::popFront()
{
	Node* t=front;
	if(front==nullptr && back==nullptr)
		throw -1;
	if(front==back)
	{
		front=nullptr;
		back=nullptr;
	}
	else
	{
		front=front->next;
		front->prev=nullptr;
	}
	delete t;
}
//PRE:The linked list should not be empty and this function is not returning anything.
//POST: removes the data of student from the back of the linked list.
void Deque::popBack()
{
	Node* t=back;
	if(front==nullptr && back==nullptr)
		throw -1;
	if(front==back)
	{
		front=nullptr;
		back=nullptr;
	}
	else
	{
		back=back->prev;
		back->next=nullptr;
	}
	delete t;
}
//PRE: The linked list should not be empty.
//POST: returns the front element of the linked list.
Students Deque::peekFront()
{
	if(front==nullptr)
		throw -1;
	return front->data;
}
//PRE: The linked list should not be empty.
//POST: returns the last element of the linked list.
Students Deque::peekBack()
{
	if(back==nullptr)
		throw -1;
	return back->data;
}
//PRE: The linked list should not be empty.
//POST: It deletes the every element of the linked list.
void Deque::clear()
{
	if(front==nullptr && back==nullptr)
		return;
	while(!isEmpty())
		popFront();
}
//PRE: NONE
//POST: returns true if the linked list is empty and false otherwise.
bool Deque::isEmpty()
{
	if(front==nullptr && back==nullptr)
		return true;
	return false;
}
//PRE: NONE
//POST: returns the total number of elements the linked list contains.
int Deque::count()
{
	int count=0;
	Node* t=front;
	if(front==nullptr && back==nullptr)
		return count;
	else
	{
		for(int i=0;t->next!=nullptr;i++)
		{
			t=t->next;
			count++;
		}
		if(t->next==nullptr)
			count++;
	}
	return count;
}
//PRE: NONE
//POST: displays all the elements of the linked list.
void Deque::display()
{
	Node* t=front;
	if(front==nullptr && back==nullptr)
	{
		cout << "The linked list is empty. NOTHING TO DISPLAY." << endl;
		return;
	}
	cout << "Students Info : " << endl;
	for(int i=0;t!=nullptr;i++)
	{
		cout << endl;
		cout << "Student Name : " << t->data.name << endl;
		cout << "Student ID : " << t->data.student_id << endl;
		cout << "Student GPA : " << t->data.gpa << endl;
		t=t->next;
	}
}