#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include "stack.h"
//change
using namespace std;
using namespace cop4530;

bool isleftparenthesis(string s);
bool isrightparenthesis(string s);
bool isoperator(string s);
bool isoperand(string s);
bool lowerprecedence(string s1);
void infixtopostfix(string collect, Stack<string> & postfix, Stack<string> & hold);

void evaluate(Stack<string> postfix);
bool isnumber(const string);

int main()
{
	


	int pos;
	string collect, element, operatorhold;
	Stack<string> hold, postfix;

	cout << "enter expression or type exit: ";



while(!cin.eof())
{

	//collects the first expression into collect
	getline(cin,collect, '\n');
		
		//if user wants to exit, they must type exit
		//then break out of the loop and end program
		if(collect == "exit")
			break;
		
		//while find is within a reasonable range for the size
		//of operands the loop keeps looping
		while(collect.find(' ') >= 0 && collect.find(' ') < 200){
			
			//if there is a left parenthesis at the end of the collect string
			//break out of the loop since it is invalid
			if(collect[collect.size()-1] == '('){
			cout << "error: last element in expression\n is left parenthesis";
			break;}			

			//finds the first position of a space in the collect string
			//thenputs a substring into element for the string before the 
			//first space.
			//then collect erases what is before that first space
			//then element is passed into the postfix stack
			pos = collect.find(' ');			
			element = collect.substr(0, pos);
			collect.erase(0, pos+1);
			infixtopostfix(element, postfix, hold);
			
			//this if statement is for the last element in the collect string
			if(collect.find(' ') > 200 || collect.find(' ') < 0)
				{
					element = collect;
					infixtopostfix(element, postfix, hold);
				}	
			}
	//emptys out the hold stack and puts approprate elements into postfix stack
	while(!(hold.empty()))
		{postfix.push(hold.top()); hold.pop();}
	
	//prints results
	if(!cin.eof()){
	cout << endl << "postfix expression: " << postfix << endl;
	cout << "evaluating the expression: " ; evaluate(postfix);
	cout << endl << endl << endl;
	cout << "enter expression or type exit: ";}
	postfix.clear();
}
	


	return 0;
}



bool lowerprecedence(string s1)
{
	if(s1 == "+" || s1 == "-")
		return true;

	return false;
}





bool isleftparenthesis(string s)
{
	return s == "(";
}





bool isrightparenthesis(string s)
{
	return s == ")";
}






bool isoperator(string s)
{
	if(s=="+"||s=="-"||s=="*"||s=="/")
		return true;

	return false;
}







bool isoperand(string s)
{
	if(isleftparenthesis(s)||isrightparenthesis(s)||isoperator(s))
		return false;

	return true;
}







void infixtopostfix(string collect, Stack<string> & postfix, Stack<string> & hold)
{
	string operatorhold;

	//if block for processing data follows the algorithm described in the
	//homework assignment page
	if(isoperand(collect))
		postfix.push(collect);
	else if(isleftparenthesis(collect))
		hold.push(collect);
	else if(isrightparenthesis(collect)){
		while(hold.top() != "(")
		{	

		postfix.push(hold.top());hold.pop();

		if(hold.empty()){
		cout << "imbalanced parenthesis: error " << endl;break;}}
				hold.pop();
		}
	else if(isoperator(collect)){
			if(hold.empty() || hold.top() == "(")
				hold.push(collect);
			else{	
			while(!(hold.empty()) && hold.top() != "(" && (!(lowerprecedence(hold.top()))||lowerprecedence(hold.top()))==lowerprecedence(collect))
			{postfix.push(hold.top()); hold.pop();}
			
			hold.push(collect);
				}
	}

}

//used in the evaluate function to find out if the operand is a number
bool isnumber(const string s)
{
	for(unsigned int i = 0; i< s.size(); i++)
		{
			if(isdigit(s[i]) || s[i] == '.')
				return true;		
		}
	return false;
}



void evaluate(Stack<string> postfix)
{
	double j;
	Stack<double> evalstack;
	Stack<string> posteval;
	Stack<string> hold;
	
	hold = postfix;

	stringstream ss;
	
	//reverses the order of postfix expression
	//in order to process the data correctly
	while(!postfix.empty())
		{posteval.push(postfix.top());postfix.pop();}


	//evaluates numbers from postfix
	while(!posteval.empty())
{
	if(isoperand(posteval.top()))
	{

	//convert string to const string to use the stod function
	const string b = posteval.top();
			if(isnumber(b))
			{
				j = stod(b);
				ss >> j;
				ss << posteval.top();

				evalstack.push(j);
			}
			else//if no number is found then return to main page and print orig
				{cout << hold;return;}

	}
	//processes the operators and operands approprately
	else if(isoperator(posteval.top()))
		{
			double operand1, operand2, result;

			operand2 = evalstack.top(); evalstack.pop();
			operand1 = evalstack.top(); evalstack.pop();

			if(posteval.top() == "+")
				{result = operand1 + operand2;}
			else if(posteval.top() == "*")
				{result = operand1 * operand2;}
			else if(posteval.top() == "-")
				{result = operand1- operand2;}
			else
				{result = operand1 / operand2;}

			evalstack.push(result);

		}		

	posteval.pop();
}
	//show results of the evaluate function
	cout << evalstack;
}












