#include"bet.h"
#include <iostream>
#include <stack>



BET::BET()
{
	root = nullptr;
}

//builds bet from postfix
BET::BET( const string & postfix)
{
	root = nullptr;
	buildFromPostfix(postfix);
}

//copy constructor
BET::BET( const BET & b)
{
	root = NULL;
	root = clone(b.root);
}

//destructor
BET::~BET()
{
	makeEmpty(root);
}

bool BET::buildFromPostfix(const string & postfix)
{
	
	string element;
	string hold = postfix;
	stack<BinaryNode *> treenode;

while((hold.find(' ') >= 0 && hold.find(' ') < 200))
{	
	//finds the first space in the string
	//if the string starts with a space return false with an error
	int pos = hold.find(' ');
	if(pos==0)
		{cout << "error: postfix expression started with space";
		return false;}

	//puts the first element into element and deletes the substring from hold
	element = hold.substr(0, pos);
	hold.erase(0, pos+1);


	//creates a node based on an operand
	if(isoperand(element))
		{
			BinaryNode * n = new BinaryNode();
			n->element = element;
			n->right = NULL;
			n->left = NULL;		
			treenode.push(n);
		}	
	//creates a node based on an operator
	if(isoperator(element))
		{
			if(treenode.size() > 1){
			BinaryNode * n = new BinaryNode();
			n->element = element;
			n->right = treenode.top();treenode.pop();
			n->left = treenode.top();treenode.pop();
			treenode.push(n);}
			//error check if there are not enough operands for the operator
			else{
			cout << "\nerror: less than two operands\n";
			return false;}
		}


cout << '\n' << "element: " << element << '\n';
}
				{
			//takes care of what is remaining in hold, the last element
			cout << '\n' << "run last: " << hold << '\n';
					if(isoperand(hold))
						{
							BinaryNode * n = new BinaryNode();
							n->element = hold;
							n->right = NULL;
							n->left = NULL;	
							treenode.push(n);
						}	
					if(isoperator(hold))
						{
							if(treenode.size()>1){
							BinaryNode * n = new BinaryNode();
							n->element = hold;
							n->right = treenode.top();treenode.pop();			
							n->left = treenode.top();treenode.pop();
							treenode.push(n);}
							//same error check as above
							else{
							cout << "\nerror: less than two operands\n";
							return false;}
						}
					}
	//check if there is too much extra stuff in the stack remaining
	if(treenode.size()>=2)
		{cout<<"error: extraneous operands in stack\n"; return false;}

	root = treenode.top();
	treenode.pop();

	return true;
}

//assignment operator
const BET & BET::operator= (const BET & b)
{
	if(this != &b)
		root = clone(b.root);

	return *this;
}

//returns size
size_t BET::size()
{
	return size(root);
}

//returns leaf nodes
size_t BET::leaf_nodes()
{
	return leaf_nodes(root);
}

//checks if empty
bool BET::empty()
{
	if (size(root)==0)
		return true;
	
	return false;
}

void BET::printInfixExpression()
{
	return printInfixExpression(root);
}

void BET::printPostfixExpression()
{
	return printPostfixExpression(root);
}

void BET::printInfixExpression(BinaryNode *n)
{
	int i = 0;

//traverses the tree for infix expression
//couldnt figure out how to lose redundancy in time	

	if(n==NULL)
		cout << "its empty yo!" << endl;
	else
		{
			if(n-> left != NULL){
				if(isoperator(n->element))
					{cout << "( ";i++;}
				printInfixExpression(n->left);}

			cout << n->element << " ";
			
			if(n-> right != NULL)
				printInfixExpression(n->right);
		}

	//prints out right parentheses based on how many left were printed
	for(int j = 0; j < i; j++)
		cout << ") ";
}

//prints post fix expression
void BET::printPostfixExpression(BinaryNode *n)
{
	if(n==NULL)
		cout << "its empty yo!" << endl;
	else
		{
			if(n-> left != NULL)
				printPostfixExpression(n->left);
			if(n-> right != NULL)
				printPostfixExpression(n->right);

			cout << n->element << " ";
		}
}

//deletes tree
void BET::makeEmpty(BinaryNode* &t)
{
	if(t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;

}


BET::BinaryNode * BET::clone(BinaryNode *t) const
{
	if(t==NULL)
		return NULL;

	return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}

//recursive functions
size_t BET::size(BinaryNode *t)
{
	if (t==NULL)
		return 0;

	return 1+size(t->left)+size(t->right);
}



size_t BET::leaf_nodes(BinaryNode *t)
{
	if(t==NULL)
		return 0;
	else if(t!=NULL && t->left == NULL && t->right==NULL)
		return 1;

	return leaf_nodes(t->left)+leaf_nodes(t->right);
}

//extra helper functions
bool BET::isoperator(string s)
{
	if(s=="+"||s=="-"||s=="*"||s=="/")
		return true;

	return false;
}

bool BET::isoperand(string s)
{
	if(BET::isoperator(s))
		return false;

	return true;
}

bool BET::lowerprecedence(string s)
{
	if(s=="+" || s=="-")
		return true;
	return false;
}

bool BET::higherprecedence(string s)
{
	if(s=="*" || s =="/")
		return true;
	return false;
}

