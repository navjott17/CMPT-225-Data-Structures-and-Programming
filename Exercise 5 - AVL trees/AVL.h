#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	int height;
};
class AVL
{ 
public:
	Node* root;
	int max(int, int);
	Node* insert(int, Node*);
	Node* singleRightRotate(Node*&);
	Node* singleLeftRotate(Node*&);
	Node* doubleLeftRightRotate(Node*&);
	Node* doubleRightLeftRotate(Node*&);
	Node* findMin(Node*);
	Node* findMax(Node*);
	Node* remove(int, Node*);
	int height(Node*);
	int getBalance(Node*);
	Node* parent_helper(Node*,Node*,bool&);
	Node* parent(Node*);
	int childCount(Node*);
	bool isRoot(Node*);
	bool isInternal(Node*);
	bool isExternal(Node*);
	bool search(Node*, int);
	int size_helper(Node*);
	int size();
	void inOrder_helper(Node*);
	void inOrder();
	void postOrder_helper(Node*);
	void postOrder();
	void preOrder_helper(Node*);
	void preOrder();

	AVL();
	void destructor_helper(Node*);
	~AVL();
	void copyConstructor_helper(Node*);
	AVL(const AVL&);
	AVL& operator=(const AVL&);
	Node* getRoot();
	bool isFull_helper(Node*); 
	bool isFull();
	bool isComplete_helper(Node*,int);
	bool isComplete();
	bool isAVL();
	void insert(int);
	void remove(int);
	void printTree();
};
 