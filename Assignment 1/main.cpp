#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stack>
#include <deque>
#include <queue>
using namespace std;
//PRE: none
//POST: swap the two elements with one another
//PARAM: T data type a and b pointers, where T is a template class.
template <class T>
void swap(T* a,T* b)
{
	T temp=*a;
	*a=*b;
	*b=temp;
}

//PRE:none
//POST: finds the random pivot element and swap it with the first element of the array.
//PARAM: T data type array, first is the start index from where the array is to be sorted,
//       last is the last index upto where the array is to be sorted. 
template <class T>
void pivot(T arr[], int first, int last)
{
	int pivot_index=rand()%((last-first+1)-first);
	T pivot=arr[pivot_index];
	swap(&arr[pivot_index], &arr[first]);
}

//PRE:none
//POST: sorts the given array by using random pivot found in above function.
//PARAM: T data type array, first is the start index from where the array is to be sorted,
//       last is the last index upto where the array is to be sorted.
template <class T>
int partition(T arr[], int first, int last)
{
	int pivot_index=first;
	T pivot=arr[first];
	for(int i=first+1;i<last;i++)
	{
		if(arr[i]<=pivot)
		{
			pivot_index++;
			swap(&arr[i], &arr[pivot_index]);
		}
	}
	swap(&arr[pivot_index],&arr[first]);
	return pivot_index;
}

//PRE:none
//POST: sorts the given array using partition and calling the same function recursively.
//PARAM: T data type array, first is the start index from where the array is to be sorted,
//       last is the last index upto where the array is to be sorted.
template <class T>
void quicksort(T arr[], int first, int last)
{
	if(first<last)
	{
		int pi=partition(arr,first,last);
		quicksort(arr,first,pi-1);
		quicksort(arr,pi+1,last);
	}
}
//PRE: none
//POST: merges and sorts the two already sorted linked lists.
//PARAM: h1 and h2 are head pointers of type Node of two linked lists that are to be sorted.
Node* sort_linkedList(Node* h1, Node* h2)
{
	Node* newHead=nullptr;
	if(h1==nullptr)
	{
		newHead=h2;
		return newHead;
	}
	else if(h2==nullptr)
	{
		newHead=h1;
		return newHead;
	}
	Node* temp1=h1;
	Node* temp2=h2;
	if(temp1->data<=temp2->data)
	{
		newHead=temp1;
		temp1=temp1->next;
	}
	else
	{
		newHead=temp2;
		temp2=temp2->next;
	}
	Node* p=newHead;
	while(temp1!=nullptr && temp2!=nullptr)
	{		
		if(temp1->data<=temp2->data)
		{
			p->next=temp1;
			p=temp1;
			temp1=temp1->next;
		}
		else
		{
			p->next=temp2;
			p=temp2;
			temp2=temp2->next;
		}
	}	
	while(temp1!=nullptr)
	{
		p->next=temp1;
		p=temp1;
		temp1=temp1->next;
	}
	while(temp2!=nullptr)
	{
		p->next=temp2;
		p=temp2;
		temp2=temp2->next;
	}
	p=nullptr;
	delete temp1;
	delete temp2;
	delete p;
	return newHead;
}
//PRE: none
//POST: displays the linked list.
//PARAM: Node type pointer head of the linked list.
void display_linkedList(Node* &head)
{
	Node* temp=head;
	for(int i=0;temp!=nullptr;i++)
	{
		cout << "---" << temp->data << "---";
		temp=temp->next;
	}
	cout << endl;
}
//PRE: none
//POST: returns true if the string is a palindrome and false otherwise using deques.
//PARAM: string data type
bool isPalindrome(string s)
{
	if(s=="")
		return true;
	deque<char> temp1;
	deque<char> temp2;
	for(int i=0;i<s.length();i++)
		temp1.push_front(s[i]);
	for(int i=0;i<s.length();i++)
		temp2.push_back(s[i]);
	while(temp1.empty()==false)
	{
		char c1=temp1.front();
		char c2=temp2.front();	
		if(c1!=c2)
			return false;
		temp1.pop_front();
		temp2.pop_front();
	}
	return true;
}
//PRE: none
//POST: deletes the middle element of the stack using recursion.
//PARAM: st is a stack of char data type, size is the size of the array
//       curr is given the defaul value of 0, which increments as the function proceeds.
//       when curr and middle index's are same, the element is popped.
void deleteMid(stack<char>& st, int size,int curr=0)
{
	if(st.empty())
		return;
	int middle=size/2;
	if(curr==middle)
	{
		st.pop();
		return;
	}
	char c=st.top();
	st.pop();
	deleteMid(st,size,curr+1);
	st.push(c);
}
//PRE: none
//POST: prints the elements of the stack.
//PARAM: s is a stack of char data type.
void display_stack(stack<char> s)
{
	cout << "---------------" << endl;
	while(!s.empty())
	{
		cout << s.top() << " , ";
		s.pop();
	}
	cout << endl;
	cout << "---------------" << endl;
}
//PRE: none
//POST: prints the binary numbers required using queue of string data type.
//PARAM: n is given the value of how many binary numbers are required.
void print_binary(int n)
{
	queue<string> q;
	q.push("1");
	for(int i=0;i<n;i++)
	{
		string s=q.front();
		q.pop();
		cout << s << ", ";
		string s1=s+"0";
		string s2=s+"1";
		q.push(s1);
		q.push(s2);
	}
	cout << endl;
}
//PRE: none
//POST: returns the size of the char array.
//PARAM: c is the array of characters.
int strlen(char c[])
{
	int i=0;
	while(c[i]!='\0')
		i++;
	return i;
}
//PRE: none
//POST: takes the char array of integers and returns it in int data type.
//PARAM: c is the array of char data type, size is the size of the array.
int atoiRecursive(char c[],int size)
{
	if(size==1)
		return c[0]-48;
	int x=atoiRecursive(c,size-1);
	int y=c[size-1]-48;
	int sum=10*x+y;
	return sum;
}
int main()
{
	srand(time(0));
	cout << endl << endl;
	cout << "            ###########------------Q1--------------###########" << endl;
	cout << "            ###########----------Stacks------------###########" << endl;
	cout << endl << endl;
	Stack s;
	try
	{
		s.push(11);
		s.push(22);
		s.push(33);
		s.push(44);
		int count=s.size();
		cout << "There are " << count << " elements in the stack. " << endl;
		cout << "The top element is " << s.peek() << endl;
		s.pop();
		s.pop();
		int count1=s.size();
		cout << "After popping, there are " << count1 << " elements in the stack." << endl;
		cout << "The top element is " << s.peek() << endl;
		if(s.empty())
			cout << "The stack is empty" << endl;
		else
			cout << "The stack is not empty" << endl;
	}
	catch (underflow_error &err)
	{
		cout << "Exception CAUGHT!!" << endl;
		cout << err.what() << endl;
	}
	cout << endl << endl;
	cout << "            ###########------------Q2--------------###########" << endl;
	cout << "            ###########----------Queues------------###########" << endl;
	cout << endl << endl;
	Queue q;
	try
	{
		q.push('a');
		q.push('b');
		q.push('c');
		q.push('d');
		cout << "The element at the front of the queue is " << q.peek() << endl;
		q.pop();
		q.pop();
		cout << "After popping, the element at the front is " << q.peek() << endl;
		if(q.empty())
			cout << "The queue is empty" << endl;
		else
			cout << "The queue is not empty" << endl;
	}
	catch (underflow_error &err)
	{
		cout << "Exception CAUGHT!!" << endl;
		cout << err.what() << endl;
	}
	catch(overflow_error & err)
	{
		cout << "Exception CAUGHT!!" << endl;
		cout << err.what() << endl;
	}
	cout << endl << endl;
	cout << "            ###########------------Q3----------------###########" << endl;
	cout << "            ###########----------Deque---------------###########" << endl;
	cout << endl << endl;
	Deque d;
	try
	{
		d.push_front("hi");
		d.push_front("hello");
		d.push_back("bonjour");
		d.push_back("hey");
		d.push_front("lol");

		cout << "The element at the front is " << d.peek_front() << endl;
		cout << "The element at the back is " << d.peek_back() << endl;
		d.pop_front();
		d.pop_back();
		d.pop_front();
		cout << "The element at the front is " << d.peek_front() << endl;
		cout << "The element at the back is " << d.peek_back() << endl;
		if(d.empty())
			cout << "The array is empty" << endl;
		else
			cout << "The array is not empty" << endl;
		if(d.full())
			cout << "The array is full" << endl;
		else
			cout << "The array is not full" << endl;
	}
	catch(underflow_error &err)
	{
		cout << "EXCEPTION CAUGHT!!" << endl;
		cout << err.what() << endl;
	}
	catch(overflow_error &err)
	{
		cout << "EXCEPTION CAUGHT!!" << endl;
		cout << err.what() << endl;
	}
	cout << endl << endl;
	cout << "            ###########--------------Q4-------------###########" << endl;
	cout << "            ###########---------QUICK SORT----------###########" << endl;
	cout << endl << endl;
	int arr[]={10,5,2,7,3,1,19};
	cout << "The original array is " << endl;
	for(int i=0;i<7;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	quicksort(arr,0,7);
	cout << "The sorted array is " << endl;
	for(int i=0;i<7;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << endl << endl;
	/*            ###########--------------Q5-----------------------###########
	            ###########--------TOWERS OF HANOI----------------###########
	There are a number of errors in the code given on slide 27 of recursion.
	1. In class Stack, there is a member variable called int* array, which is a dynamic array
		and it's memory is not deallocated, i.e, deleted. A possible solution for that could be
		making a deallocator for the Stack class as given below:
		void deallocate_array()
		{
			delete[] array
		}

	2. The function void tohIterative(int num_of_disks, Stack src, Stack aux, Stack dest) has to be changed to
		void tohIterative(int num_of_disks, Stack* src, Stack* aux, Stack* dest) because originally they are pointers 
		created in the main function.
		Also, with these the following function calls should also be changed:
		src.push(i) to src->push(i);

	3. The fuction void moveDisksBetweenTwoPoles(Stack src, Stack dest, char s, char d) has to be changed to
		void moveDisksBetweenTwoPoles(Stack* src, Stack* dest, char s, char d) because they are pointers created
		in the main because the output was not proper.
		The following function calls should be changed:
		src.pop() to src->pop();
		dest.pop() to dest->pop();
		src.push(pole2TopDisk) to src->push(pole2TopDisk);
		dest.push(pole1TopDisk) to dest->push(pole1TopDisk);
		all other src. should be changed to src->
		and all the dest. should be changed to dest->

	4. In the main function the Stack pointers *src,*dest,*aux are allocated on the heap 
		but not deleted.
		The main function is:
		int main()
		{
			int num_of_disks = 3;
			Stack *src, *dest, *aux;
			src = createStack(num_of_disks);
			aux = createStack(num_of_disks);
			dest = createStack(num_of_disks);
			tohIterative(num_of_disks, *src, *aux, *dest);
			return 0;
		}
		The updated main is now:
		int main()
		{
			int num_of_disks = 3;
			Stack *src, *dest, *aux;
			src = createStack(num_of_disks);
			aux = createStack(num_of_disks);
			dest = createStack(num_of_disks);
			tohIterative(num_of_disks, src, aux, dest);
			src->deallocate_array();
			dest->deallocate_array();
			aux->deallocate_array();
			delete src;
			delete dest;
			delete aux;
			return 0;
		}
	*/
	cout << "            ###########--------------Q6-----------------------###########" << endl;
	cout << "            ###########----MERGING AND SORTING LINKED LIST----###########" << endl;
	cout << endl << endl;
	Node* l1=new Node;
	l1=new Node(5);
	l1->next=new Node(7);
	l1->next->next=new Node(9);
	cout << "Linked list l1 is" << endl;
	display_linkedList(l1);
	Node* l2=new Node;
	l2=new Node(1);
	l2->next=new Node(3);
	l2->next->next=new Node(8);
	l2->next->next->next=new Node(10);
	cout << "Linked list l2 is" << endl;
	display_linkedList(l2);
	Node* head=sort_linkedList(l1,l2);
	cout << "The merged and sorted linked list is " << endl;
	display_linkedList(head);
	cout << endl << endl;
	cout << "            ###########------------Q7--------------###########" << endl;
	cout << "            ###########-------PALINDROME-----------###########" << endl;
	cout << endl << endl;
	string s1="RACECAR";
	if(isPalindrome(s1))
		cout << s1 << " is a Palindrome" << endl;
	else
		cout << s1 << " is not a Palindrome." << endl;
	string s2="navjot";
	if(isPalindrome(s2))
		cout << s2 << " is a Palindrome" << endl;
	else
		cout << s2 << " is not a Palindrome." << endl;
	string s3;
	cout << "Enter a string to check if it is palindrome." << endl;
	cin >> s3;
	if(isPalindrome(s3))
		cout << s3 << " is a Palindrome" << endl;
	else
		cout << s3 << " is not a Palindrome." << endl;
	cout << endl << endl;
	cout << "            ###########----------------Q8----------------###########" << endl;
	cout << "            ###########-----------DELETE MIDDLE----------###########" << endl;
	cout << endl << endl;
	stack<char> stac;
	stac.push('a');
	stac.push('b');
	stac.push('c');
	stac.push('d');
	stac.push('e');
	cout << "Original elements of the stack are " << endl;
	display_stack(stac);
	deleteMid(stac,5);
	cout << "After deleting the middle element, the elements of the stack are " << endl;
	display_stack(stac);
	cout << endl << endl;
	cout << "            ##########---------------Q9-----------------###########" << endl;
	cout << "            ##########----------PRINTING BINARY---------###########" << endl;
	cout << endl << endl;
	int n;
	cout << "How many binary numbers do you want to generate? " << endl;
	cin >> n;
	cout << "The " << n << " binary numbers are : " << endl;
	print_binary(n);
	cout << endl << endl;
	cout << "            ##########----------------Q10---------------###########" << endl;
	cout << "            ##########----------CHAR ARRAY TO INT-------###########" << endl;
	cout << endl << endl;
	char str[]="112";
	int size=strlen(str);
	cout << atoiRecursive(str,size) << endl;
	cout << endl << endl;
	return 0;
}
