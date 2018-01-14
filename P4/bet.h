#ifndef _BET_H_
#define _BET_H_

#include <iostream>
#include <string>
using namespace std;

//all private functions are depth first search
//post order traversal to in order traversal



class BET 
{
public:
        BET();			//default constructor
        BET(const string & postfix);//build a BET with the postfix string passed
        BET(const BET&);//copy constructor
        ~BET();			//destructor
        bool buildFromPostfix(const string & postfix);
        const BET & operator= (const BET &); //assignment operator
        void printInfixExpression();
		void printPostfixExpression();
		size_t size();	//return size
		size_t leaf_nodes(); //return leafnode count
        bool empty();	//checks if empty

		//
		struct BinaryNode 
    		{
    		    string element;
    		    BinaryNode * left, * right;
    		};

private:
        void printInfixExpression(BinaryNode *n);
		void printPostfixExpression(BinaryNode *n);
        void makeEmpty(BinaryNode* &t);
        BinaryNode * clone(BinaryNode *t) const;
		size_t size(BinaryNode *t);
		size_t leaf_nodes(BinaryNode *t);
		bool isoperator(string s);
		bool isoperand(string s);
		bool higherprecedence(string s);
		bool lowerprecedence(string s);
		BinaryNode * root;
};



#include "bet.hpp"
#endif
