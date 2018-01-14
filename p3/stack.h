#include <iostream>
#include <vector>

namespace cop4530

{


template <typename T>
class Stack
{

public:
    Stack();                            //default constructor
    ~Stack();                           //destructor
    Stack(const Stack<T> &);            //copy constructor
    Stack(Stack<T> &&);                 //move constructor
    Stack<T>& operator=(const Stack<T> &);  //copy assignment
    Stack<T>& operator=(Stack<T> &&);   //move assignment
    
    bool empty() const;
    void clear();
    void push(const T& x);
    void push(T &&x);                   //add x to stack (move)
    void pop();                         //remove most recently added
    T & top();                          //returns reference to most recent
    const T& top() const;               //accessor returns top
    int size() const;                   //returns number of elements in stack
    
    void print(std::ostream& os, char ofc = ' ') const;
    
private:
	std::vector<T> v;

};
    
    //non member function
    //invokes the print function to print stack in specified ostream
    template<typename T>
    std::ostream& operator<< (std::ostream& os, const Stack<T>& a);
    
    template<typename T>
    bool operator== (const Stack<T>&, const Stack <T>&);
    
    template<typename T>
    bool operator!= (const Stack<T>&, const Stack <T>&);
    
    template<typename T>
    bool operator<= (const Stack<T>& a, const Stack <T>& b);
    
    
    
    #include "stack.hpp"
    
}
    
    
    
