#include "AVL.h"
//PRE: none
//POST: returns the maximum of the two integers.
int AVL::max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

//PRE: the argument should be an integer.
//POST: inserts the integer to the AVL tree and returns the inserted node.
Node* AVL::insert(int x, Node* node)
{
	//creates a new node everytime an integer is inserted.
	if(node==nullptr) 
	{
		Node* temp=new Node;
		temp->data=x;
		temp->left=nullptr;
		temp->right=nullptr;
		temp->height=0;
		return temp;
	}
	//checks if the integer being inserted is smaller or greater than the argument node
	if(x<=node->data)
		node->left=insert(x,node->left); //if the integer is smaller then the new node is inserted on the left side of the argument node.
	else
		node->right=insert(x,node->right); //if the integer is greater then the new node is inserted on the right side of the argument node.
	//checks the left subtree and right subtree's height in order to assign the height of the argument node.
	int left_height=height(node->left);
	int right_height=height(node->right);
	node->height=1+max(left_height,right_height); // 1+ the maximun of the two heights being compared is the desired height.
	//compute the balance factor of the node.
	int balance=getBalance(node);
	//if the tree becomes unbalanced i.e the balance factor exceeds 1 or decreases from -1,
	//four cases(LL, RR, LR, RL) arise and the following codes checks the balance factor 
	//and rotates the tree accordingly.
	//LL case
	if(balance>1 && x<node->left->data)
		return singleRightRotate(node);
	//RR case
	if(balance<-1 && x>node->right->data)
		return singleLeftRotate(node);
	//RL case
	if(balance<-1 && x<node->right->data)
		return doubleLeftRightRotate(node);
	//LR case
	if(balance>1 && x>node->left->data)
		return doubleRightLeftRotate(node);
	return node;
}

//PRE: AVL tree is not empty and one of the nodes has lost its AVL property.
//POST: rotates the node of the tree to right so that the tree doesn't lose its AVL properties 
//       and returns the node being rotated.
Node* AVL::singleRightRotate(Node*& node)
{
	Node* temp1=node->left;
	Node* temp2=temp1->right;
	temp1->right=node;
	node->left=temp2;
	node->height=1+max(height(node->left),height(node->right));
	temp1->height=1+max(height(temp1->left),height(temp1->right));
	return temp1;
}

//PRE: AVL tree is not empty and one of the nodes has lost its AVL property.
//POST: rotates the node of the tree to left so that the tree doesn't lose its AVL properties 
//       and returns the node being rotated.
Node* AVL::singleLeftRotate(Node*& node)
{
	Node* temp1=node->right;
	Node* temp2=temp1->left;
	temp1->left=node;
	node->right=temp2;
	node->height=1+max(height(node->left),height(node->right));
	temp1->height=1+max(height(temp1->left),height(temp1->right));
	return temp1;
}

//PRE: AVL tree is not empty and one of the nodes has lost its AVL property.
//POST: rotates the node of the tree to right and then left so that the tree doesn't 
//      lose its AVL properties and returns the node being rotated.
Node* AVL::doubleLeftRightRotate(Node*& node)
{
	node->right=singleRightRotate(node->right);
	node->right=singleLeftRotate(node->right);
	return node->right;
}

//PRE: AVL tree is not empty and one of the nodes has lost its AVL property.
//POST: rotates the node of the tree to left and then right so that the tree doesn't 
//      lose its AVL properties and returns the node being rotated.
Node* AVL::doubleRightLeftRotate(Node*& node)
{
	node->left=singleLeftRotate(node->left);
	node->left=singleRightRotate(node->left);
	return node->left;
}

//PRE: AVL tree is not empty
//POST: returns the node with minimum integer value(left-most node) 
Node* AVL::findMin(Node* node)
{
	Node* temp=node;
	while(temp->left!=nullptr)
		temp=temp->left;
	return temp;
}

//PRE: AVL tree is not empty
//POST: returns the node with maximum integer value(right-most node)
Node* AVL::findMax(Node* node)
{
	Node* temp=node;
	while(temp->right!=nullptr)
		temp=temp->right;
	return temp;
}

//PRE: AVL tree is not empty
//POST: removes the integer argument provided from the AVL tree while retaining the
//      AVL properties of the tree. 
Node* AVL::remove(int x, Node* node)
{
	//checks if the node being removed is a nullptr.
	if(node==nullptr)
		return nullptr;
	//checks whether the integer data being removed is present on the left side of the node
	//i.e is smaller than the node data or the data is present on the right side of the node
	//i.e is bigger than the node data.
	if(x<node->data)
		node->left=remove(x,node->left);
	else if(x>node->data)
		node->right=remove(x,node->right);
	else
	{
		//removing the node with only one child or no child
		if(node->left==nullptr || node->right==nullptr)
		{
			Node* temp=node;
			if(node->left==nullptr)
				temp=node->right;
			else
				temp=node->left;
			if(temp==nullptr)
			{
				temp=node;
				node=nullptr;
			}
			else
				*node=*temp;
			delete temp;
		}
		else
		{
			//removing the node with two children
			Node* temp=findMin(node->right);
			node->data=temp->data;
			node->right=remove(temp->data, node->right);
		}		
	}
	if(node==nullptr)
		return nullptr;
	//assigns the new height to the argument node.
	node->height=1+max(height(node->left),height(node->right));
	//checks the balance factor
	int balance=getBalance(node);
	//if the tree becomes unbalanced i.e the balance factor exceeds 1 or decreases from -1,
	//four cases(LL, RR, LR, RL) arise and the following codes checks the balance factor 
	//and rotates the tree accordingly.
	//LL case
	if(balance>1 && getBalance(node->left)>=0)
		return singleRightRotate(node);
	//RR case
	if(balance<-1 && getBalance(node->right)<=0)
		return singleLeftRotate(node);
	//RL case
	if(balance<-1 && getBalance(node->right)>0)
		return doubleLeftRightRotate(node);
	//LR case
	if(balance>1 && getBalance(node->left)<0)
		return doubleRightLeftRotate(node);
	return node;
}

//PRE: none
//POST: returns the height of the tree.
int AVL::height(Node* node)
{
	if(node==nullptr)
		return -1;
	else
		return node->height;
}

//PRE: none
//POST: returns the balance factor of the tree.
int AVL::getBalance(Node* node)
{
	if(node==nullptr)
		return 0;
	else
	{
		int h=height(node->left)-height(node->right);
		return h;
	}
}

//PRE: AVL tree is not empty
//POST: returns the parent node of the desired node.
Node* AVL::parent_helper(Node* node1,Node* node2,bool& f)
{
	if(f)
	{
		return node1;
	}
	if(node1==nullptr)
	{
		return nullptr;
	}
	if(node1->left==node2||node1->right==node2)
	{
		f=true;
		return node1;
	}
	if(node2->data<this->root->data)
		node1=parent_helper(node1->left,node2,f);
	else if(node2->data>this->root->data)
		node1=parent_helper(node1->right,node2,f);
	return node1;
}

//PRE: AVL tree is not empty
//POST: returns the parent node of the desired node by calling the helper function.
Node* AVL::parent (Node* node)
{
	bool temp=false;
	Node* parent=parent_helper(root,node,temp);
	return parent;
}

//PRE: AVL tree is not empty
//POST: returns how many children a provided node has.
int AVL::childCount (Node* node)
{
	if(node->left==nullptr && node->right==nullptr)
		return 0;
	else if(node->left==nullptr && node->right!=nullptr || node->left!=nullptr && node->right==nullptr)
		return 1;
	else
		return 2;
}

//POST: AVL tree is not empty
//POST: returns true if the provided node is the root node and false otherwise.
bool AVL::isRoot(Node* node)
{
	if(node->data==root->data)
		return true;
	return false;
}

//PRE: AVL tree is not empty
//POST: returns true if the provided node is the internal node and false otherwise.
bool AVL::isInternal(Node* node)
{
	if(node->left!=nullptr || node->right!=nullptr)
		return true;
	return false;
}

//PRE: AVL tree is not empty
//POST: returns true if the provided node is external node and false otherwise.
bool AVL::isExternal(Node* node)
{
	if(node->left==nullptr && node->right==nullptr)
		return true;
	return false;
}

//PRE: AVL tree is not empty
//POST: returns true if the given integer data is in the tree and false otherwise.
bool AVL::search(Node* node, int x)
{
	if(node==nullptr)
		return false;
	if(node->data==x)
		return true;
	else
	{
		bool temp;
		if(x<node->data)
			temp=search(node->left,x);
		else
			temp=search(node->right,x);
		return temp;
	}
}

//PRE: AVL tree is not empty
//POST: returns the size i.e, number of nodes of the tree.
int AVL::size_helper(Node* node)
{
	if(this->root==nullptr || node==nullptr)
		return 0;
	else
	{
		int count=1+size_helper(node->left)+size_helper(node->right);
		return count;
	}
}

//PRE: AVL tree is not empty
//POST: returns the size of the tree by using a helper function.
int AVL::size()
{
	return size_helper(this->root);
}	

//PRE: AVL tree is not empty
//POST: displays the inorder traversal of the tree.
void AVL::inOrder_helper(Node* node)
{
	if(node)
	{
		inOrder_helper(node->left);
		cout << node->data << "   ";
		inOrder_helper(node->right);
	}
}

//PRE: AVL tree is not empty
//POST: displays the inorder traversal of the tree by using a helper function.
void AVL::inOrder() 
{
	cout << "                     ";
	inOrder_helper(root);
	cout << endl;
}

//PRE: AVL tree is not empty
//POST: displays the postorder traversal of the tree.
void AVL::postOrder_helper(Node* node)
{
	if(node)
	{
		postOrder_helper(node->left);
		postOrder_helper(node->right);
		cout << node->data << "   ";
	}
}

//PRE: AVL tree is not empty
//POST: displays the postorder traversal of the tree by using a helper function.
void AVL::postOrder() 
{
	cout << "                     ";
	postOrder_helper(root);
	cout << endl;
}

//PRE: AVL tree is not empty
//POST: displays the preorder traversal of the tree.
void AVL::preOrder_helper(Node* node)
{
	if(node)
	{
		cout << node->data << "   ";
		preOrder_helper(node->left);
		preOrder_helper(node->right);
	}
}

//PRE: AVL tree is not empty
//POST: displays the preorder traversal of the tree by using a helper function.
void AVL::preOrder()
{
	cout << "                     ";
	preOrder_helper(root);
	cout << endl;
}
//default constructor
AVL::AVL()
{
	this->root=nullptr;
}

//PRE: none
//POST: deletes the AVL tree.
void AVL::destructor_helper(Node* node)
{
	if(node!=nullptr)
	{
		destructor_helper(node->right);
		destructor_helper(node->left);
		delete node;
	}
}

//destructor
AVL::~AVL()
{
	destructor_helper(this->root);
}

//PRE: none
//POST: makes a copy of the provided node to the calling object.
void AVL::copyConstructor_helper(Node* node)
{
	if(node==nullptr)
		return;
	else
	{
		this->insert(node->data);
		copyConstructor_helper(node->left);
		copyConstructor_helper(node->right);
	}
}

//copy constructor
AVL::AVL(const AVL& tree)
{	
	this->root=nullptr;
	copyConstructor_helper(tree.root);
}

//PRE: none
//POST: assigns the value of the node to the calling object (assignment operator).
AVL& AVL::operator=(const AVL& tree)
{
	if(this==&tree)
		return *this;
	destructor_helper(this->root);
	copyConstructor_helper(tree.root);
	return *this;
}

//PRE: AVL tree is not empty
//POST: returns the root of the AVL tree.
Node* AVL::getRoot()
{
	return root;
}

//PRE: AVL tree is not empty
//POST: returns true if the tree is full and false otherwise.
bool AVL::isFull_helper(Node* node)
{
	//if the root or the provided node is nullptr then the function returns true.
	if(this->root==nullptr ||node==nullptr)
		return true;
	else if(node->left!=nullptr && node->right==nullptr || node->right!=nullptr && node->left==nullptr) //one child
		return false;
	else if(node->left==nullptr && node->right==nullptr && getBalance(this->root)==0) //two children and the left and right subtree are on same level.
		return true;
	else if(node->left!=nullptr && node->right!=nullptr) //two children
		return (isFull_helper(node->left) && isFull_helper(node->right));
	return false;
}

//PRE: AVL tree is not empty
//POST: returns true if the tree is full and false otherwise by using a helper function.
bool AVL::isFull()
{
	return isFull_helper(this->root);
}

//PRE: AVL tree is not empty
//POST: returns true if the tree is complete and false otherwise.
bool AVL::isComplete_helper(Node* node, int index)
{
	int n=size();
	if(this->root==nullptr || node==nullptr) //checks if root or the node is nullptr
		return true;
	else if(index>=n) // checks if the index is greater than the size of the tree.
		return false; 
	return (isComplete_helper(node->left,2*index+1) && isComplete_helper(node->right,2*index+2));
	//argument index=2*index+1 because of the odd indexes i.e checking the left subtree (say)
	//argument index=2*index+2 because of the even indexes i.e checking the right subtree (say)
	//it is a recursive call so that both left and right tree are covered.
}

//PRE: AVL tree is not empty
//POST: returns true if the tree is complete and false otherwise by using a helper function.
bool AVL::isComplete()
{
	return isComplete_helper(this->root,0);
}

//PRE: AVL tree is not empty
//POST: returns true if the tree is AVL and false otherwise.
bool AVL::isAVL()
{
	//a tree is AVL if the balance factor lies between -1 and 1.
	if(getBalance(this->root)>=-1 && getBalance(this->root)<=1)
		return true;
	else
		return false;
}

//PRE: the argument should be an integer.
//POST: inserts the integer to the AVL tree
void AVL::insert(int x)
{
	root=insert(x,root);
}

//PRE: the argument should be an integer.
//POST: removes the integer to the AVL tree.
void AVL::remove(int x)
{
	root=remove(x,root);
}

//PRE: none
//POST: displays the elements of the tree in inorder,preorder and postorder.
void AVL::printTree()
{
	cout << "-----------------DISPLAYING TREE-----------------" << endl;
	cout << "                 INORDER TRAVERSAL" << endl;
	inOrder();
	cout << "                 PREORDER TRAVERSAL" << endl;
	preOrder();
	cout << "                 POSTORDER TRAVERSAL" << endl;
	postOrder();
}