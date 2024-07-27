#include "AVL.h"
#include<string>
#include<vector>

//PRE: none
//POST: returns true if all the elements of string s are numeric
bool digit_checker(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<'0' || s[i]>'9')
			return false;
	}
	return true;
}

//PRE: none
//POST: if all the elements of string s are not numeric then it will ask user to enter the number again.
void exception_handler(string& s)
{
	while(digit_checker(s)==false)
	{
		cout << "\t\tEnter a positive integer number to insert : ";
		cin >> s;
	}
}

//PRE: none
//POST: if the answer is not Y/y or N/n then it will ask user to enter the string again.
void right_input(string& answer)
{
	while(true)
	{
		if(answer.size()==1)
		{
			if(answer=="y" || answer=="Y" || answer=="n" || answer=="N")
				break;
			else
			{
				cout << "\tPLEASE CHOOSE Y/y OR N/n ONLY : ";
				cin >> answer;
			}
		}
		else
		{
			cout << "\tPLEASE CHOOSE Y/y OR N/n ONLY : ";
			cin >> answer;
		}
	}
}
int main()
{
	AVL t;
	vector<int> v;
	cout << "--------------------CONSTRUCTING AN AVL TREE--------------------" << endl;
	string elements;
	cout << "How many elements do you want to insert in an AVL tree? " << endl;
	cout << "For simplicity, choose a number between 1-10." << endl;
	cin >> elements;
	int i=0;
	while(true)
	{
		if(elements.size()==1)
		{
			if(elements>="1" && elements<="9")
				break;
			else	
			{
				cout << "\tEnter your choice from(1-10) please: ";
				cin >> elements;
			}
		}
		else if(elements.size()==2)
		{
			if(elements=="10")
				break;
			else	
			{
				cout << "\tEnter your choice from(1-10) please: ";
				cin >> elements;
			}
		}
		else
		{
			cout << "\tEnter your choice from(1-10) please: ";
			cin >> elements;
		}
	}
	cout << "--------------------INSERTING ELEMENTS--------------------" << endl;
	int x=stoi(elements);
	string number;
	for(int i=0;i<x;i++)
	{
		cout << "Enter the element number " << i+1 << " : ";
		cin >> number;
		exception_handler(number);
		int b=stoi(number);
		v.push_back(b);
	}
	for(int i=0;i<v.size();i++)
		t.insert(v[i]);
	cout << "The elements are inserted in the tree and the three traversals are as follows :" << endl;
	t.printTree();
	cout << "-------------TESTING findMin, findMax, height, size, and root--------------" << endl;
	Node* temp=t.getRoot();
	cout << "The root of the AVL tree is : " << temp->data << endl << endl;
	Node* min=t.findMin(temp);
	cout << "The minimum element of the tree is : " << min->data << endl << endl;
	Node* max=t.findMax(temp);
	cout << "The maximum element of the tree is : " << max->data << endl << endl;
	cout << "The height of the tree is : " << t.height(temp) << endl << endl;
	cout << "The size of the tree is : " << t.size() << endl << endl;
	cout << "---------TESTING isAVL, isComplete and isFull---------------" << endl << endl;
	if(t.isAVL())
		cout << "The tree is AVL." << endl << endl;
	else
		cout << "The tree is not AVL." << endl << endl;
	if(t.isComplete())
		cout << "The tree is Complete." << endl << endl;
	else
		cout << "The tree is not Complete." << endl << endl;
	if(t.isFull())
		cout << "The tree is Full." << endl << endl;
	else
		cout << "The tree is not Full." << endl << endl;
	cout << "-----------TESTING SEARCH FUNCTION-------------------" << endl << endl;
	bool loop=true;
	while(loop)
	{
		string num;
		cout << "Enter the number you would like to search : ";
		cin >> num;
		exception_handler(num);
		int c=stoi(num);
		bool flag=t.search(t.getRoot(),c);
		if(flag==true)
			cout << c << " is in the AVL tree." << endl;
		else
			cout << c << " is not in the AVL tree." << endl;
		string loop_char;
		cout << "DO you want to search any other integer? Enter Y/y or N/n" << endl;
		cin >> loop_char;
		right_input(loop_char);
		if(loop_char=="N" || loop_char=="n")
			loop=false;
	}
	cout << "--------------TESTING Parent, Childcount-------------" << endl << endl;
	if(t.size()>2)
	{
		if(temp->left!=nullptr)
		{
			Node* pt=t.parent(temp->left);
			cout << "The parent of " << temp->left->data << " is " << pt->data << endl << endl;
		}
		if(temp->right!=nullptr)
		{
			Node* pt1=t.parent(temp->right);
			cout << "The parent of " << temp->right->data << " is " << pt1->data << endl << endl;
		}
		if(temp->right->right!=nullptr)
		{
			Node* pt2=t.parent(temp->right->right);
			cout << "The parent of " << temp->right->right->data << " is " << pt2->data << endl << endl;
		}
		cout << "The child count of " << temp->data << " is " << t.childCount(temp) << endl << endl;
		if(temp->left!=nullptr)
			cout << "The child count of " << temp->left->data << " is " << t.childCount(temp->left) << endl << endl;
		if(temp->right->right!=nullptr)
			cout << "The child count of " << temp->right->right->data << " is " << t.childCount(temp->right->right) << endl << endl;
	}
	cout << "--------------TESTING isRoot, isInternal and isExternal nodes------------" << endl << endl;
	if(t.isRoot(temp))
		cout << temp->data << " is the root of AVL tree." << endl << endl;
	if(t.isInternal(temp))
		cout << temp->data << " is the internal node of AVL tree." << endl << endl;
	if(t.isExternal(temp))
		cout << temp->data << " is the external node of AVL tree." << endl << endl;
	if(temp->left!=nullptr)
	{
		if(t.isRoot(temp->left))
			cout << temp->left->data << " is the root of AVL tree." << endl << endl;
		if(t.isInternal(temp->left))
			cout << temp->left->data << " is the internal node of AVL tree." << endl << endl;
		if(t.isExternal(temp->left))
			cout << temp->left->data << " is the external node of AVL tree." << endl << endl;
		else
			cout << temp->left->data << " is not the external node of AVL tree." << endl << endl;
	}
	cout << "---------------TESTING remove----------------------" << endl << endl;
	cout << "Enter a number you would like to remove from AVL tree : ";
	string num2;
	cin >> num2;
	exception_handler(num2);
	int e=stoi(num2);
	if(!(t.search(temp,e)))
		cout << "Sorry, the number you entered is not in AVL tree." << endl;
	else
	{
		t.remove(e);
		cout << "The tree after removing " << e << " is " << endl;
		t.printTree();
	}
	cout << "--------TESTING copy constructor and assignment operator-------------" << endl << endl;
	cout << "Tree t1 is being copy constructed from tree t..." << endl << endl;
	AVL t1=t;
	cout << "==================COPY CONSTRUCTED TREE t1====================" << endl << endl;
	t1.printTree();
	AVL t2;
	t2=t;
	cout << endl << "Tree t2 is made equal to the tree t by assignment operator" << endl << endl;
	cout << "==================USING ASSIGNMENT OPERATOR TREE t2====================" << endl << endl;
	t2.printTree();
	cout << "----------END OF PROGRAM. GOODBYE-----------------" << endl << endl << endl;
	return 0;
}