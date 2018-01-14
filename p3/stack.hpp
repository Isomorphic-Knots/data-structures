
template <typename T>
Stack<T>::Stack()                             //default constructor
{
	std::vector<T> v;   
}


template <typename T>
Stack<T>::~Stack()                            //destructor
{
	clear();
}



template <typename T>
Stack<T>::Stack(const Stack<T> & rhs)             //copy constructor
{

	v = rhs.v;
}




template <typename T>
Stack<T>::Stack(Stack<T> && rhs)                  //move constructor
{
	
	v = rhs.v;

	rhs.clear();


}




template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> & rhs)   //copy assignment
{
	v = rhs.v;
	return *this;
}




template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> && rhs)    //move assignment
{
	std::swap(v, rhs.v);

	return *this;
}






template <typename T>    
bool Stack<T>::empty() const
{
    return v.size() == 0;
}



template <typename T>
void Stack<T>::clear()
{
	v.std::vector<T>::clear();
}




template <typename T>
void Stack<T>::push(const T& x)
{
	v.std::vector<T>::push_back(x);
}




template <typename T>
void Stack<T>::push(T &&x)                    //add x to stack (move)
{
	v.std::vector<T>::push_back(std::move(x));
}




template <typename T>
void Stack<T>::pop()                          //remove most recently added
{
	v.std::vector<T>::pop_back();
}



template <typename T>
T & Stack<T>::top()                           //returns reference to most recent
{
	return v.std::vector<T>::back();
}



template <typename T>
const T& Stack<T>::top() const                //accessor returns top
{
	return v.std::vector<T>::back();
}



template <typename T>
int Stack<T>::size() const    //returns number of elements in stack
{
    return v.std::vector<T>::size();
}




template <typename T>    
void Stack<T>::print(std::ostream& os, char) const
{

	for(unsigned int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ' ';
	}
}   



    
//non member function
//invokes the print function to print stack in specified ostream
template<typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T> & a)
{
	a.Stack<T>::print(os);
	return os;
}





    
template<typename T>
bool operator== (const Stack<T>& s1, const Stack <T>& s2)
{	
	if(s1.Stack<T>::size() !=  s2.Stack<T>::size())
		return false;
	
	Stack<T> s1copy = s1;
	Stack<T> s2copy = s2;

	while(!(s1copy.Stack<T>::empty()))
	{
		if(s1copy.Stack<T>::top() != s2copy.Stack<T>::top())
			{return false;}

		s1copy.Stack<T>::pop();s2copy.Stack<T>::pop();
	}
    return true;
}




    
template<typename T>
bool operator!= (const Stack<T>& s1, const Stack <T>& s2)
{

    return (s1==s2);
}



    
template<typename T>
bool operator<= (const Stack<T>& s1, const Stack <T>& s2)
{
	if(s1.Stack<T>::size() <  s2.Stack<T>::size())
		{return true;}
	
	Stack<T> s1copy = s1;
	Stack<T> s2copy = s2;

	while(!(s1copy.Stack<T>::empty()))
	{
		if(s1copy.Stack<T>::top() > s2copy.Stack<T>::top())
			{return false;}

		s1copy.Stack<T>::pop();s2copy.Stack<T>::pop();
	}

    return true;
}





/*


run = true;
	while(run)
	{	
		if(i==1)
			{infixtopostfix(newlinecollect2, postfix, hold);i=0;}
			
		
		getline(cin,collect, ' ');	
		if(collect.find('\n') > 0 && collect.find('\n') < 200){
			pos = collect.find('\n');
			newlinecollect1 = collect.substr(0,pos);
			newlinecollect2 = collect.substr(pos+1,collect.length());
			infixtopostfix(newlinecollect1, postfix, hold); run = false;}
		else
			infixtopostfix(collect, postfix, hold);
		
	}

	while(!(hold.empty()))
		{postfix.push(hold.top()); hold.pop();}
	i++;
	cout << postfix << endl;
	postfix.clear();

*/



    
