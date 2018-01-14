
                            //const_iterator 
//****************************************************************************
//default constructor, empty list
template< typename T>
List<T>::const_iterator::const_iterator() : current{nullptr}
{}


//use the retrieve function
template< typename T>
const T & List<T>::const_iterator::operator*() const// operator*() to return element
{return retrieve();}
 
 
 
// increment/decrement operators
template< typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++()
{current = current->next;
 return *this;}



template< typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{const_iterator old = *this;
 ++(*this);
 return old;}


template< typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator--()
{current = current->prev;
 return *this;}


template< typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
{const_iterator old = *this;
 --(*this);
 return old;}


// comparison operators
template< typename T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
{return current == rhs.current;}


template< typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
{return !(*this == rhs);}


template< typename T>
T & List<T>::const_iterator::retrieve() const
{return current->data;}


template <class T>
List<T>::const_iterator::const_iterator(Node *p) : current{p}
{}

//****************************************************************************

































                            //iterator
//****************************************************************************
template <typename T>
List<T>::iterator::iterator()
{}


template <typename T>
T & List<T>::iterator::operator*()
{return const_iterator::retrieve();}


template <typename T>
const T & List<T>::iterator::operator*() const
{return const_iterator::operator*();}


// increment/decrement operators
template <typename T>
typename List<T>::iterator & List<T>::iterator::operator++()
{
    this->current = this->current->next;
    return *this;
}


template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{
    iterator old = *this;
    ++(*this);
    return old;
}


template <typename T>
typename List<T>::iterator & List<T>::iterator::operator--()
{
    this->current = this->current->prev;
    return *this;   
}


template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int)
{
    iterator old = *this;
    --(*this);
    return old;
}
 
 
template <class T>
List<T>::iterator::iterator(Node *p) : const_iterator{p}
{}


//****************************************************************************


































                                //LIST!!!!!!!!!!!
//----------------------------------------------------------------------------
template< typename T>
List<T>::List()                  // default zero parameter constructor
{
    init();
}

template< typename T>
List<T>::List(const List &rhs)   // copy constructor
{
    init( );
    for(auto & x:rhs )
    push_back( x );
}

template< typename T>
List<T>::List(List && rhs) : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }     // move constructor
{
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

template< typename T>       // num elements with value of val
List<T>::List(int num, const T& val)
{
    init();
    
    for(int i = 0; i != num; i++)
        push_front(val);
}

template< typename T>// constructs with elements [start, end)
List<T>::List(const_iterator start, const_iterator end) 
{
    init();   
    auto itr = start;  
    
    //sets itr to start then loops to end
        while(itr!=end)
            {
                push_front(*itr);
                itr++;
            }  
}

template< typename T>// constructs with a copy of each of the elements in the initalizer_list
List<T>::List (std::initializer_list<T> iList)
{
    init();
    
    //use of initializer list begin to collect data being passed
    auto itr = iList.std::initializer_list<T>::begin();
    
    //loop until the initializer list is empty
    for(int i = iList.std::initializer_list<T>::size(); i!=0 ; i--)
        {
            push_back(*itr);
            itr++;
        }
}


template< typename T>
List<T>::~List() // destructor
{
    clear();
    delete head;
    delete tail;
}


template< typename T>// copy assignment operator
const List<T>& List<T>::operator=(const List &rhs)
{
    List copy = rhs;
    std::swap( *this, copy );
    return *this;
}


template< typename T>// move assignment operator
List<T> & List<T>::operator=(List && rhs)
{
    std::swap( theSize, rhs.theSize );
    std::swap( head, rhs.head );
    std::swap( tail, rhs.tail );

    return *this;
}

template< typename T>// sets list to the elements of the initializer_list
List<T>& List<T>::operator= (std::initializer_list<T> iList)
{
    this->clear();
    auto itr = iList.std::initializer_list<T>::begin();
    
    for(int i = iList.std::initializer_list<T>::size(); i!=0 ; i--)
        {
            push_back(*itr);
            itr++;
        }   
    return *this;
}


template< typename T>// member functions
int List<T>::size() const       // number of elements
{
    return theSize;
}

template< typename T>
bool List<T>::empty() const     // check if list is empty
{
    return size()==0;
}


template< typename T>
void List<T>::clear()           // delete all elements
{
    while(theSize!=0)
        pop_front();
}


template< typename T>
void List<T>::reverse()         // reverse the order of the elements
{   
    List t= *this; 
    this->clear();
    
    
    auto itr = t.end();
    itr--;
    //uses for loop to put the list in reverse
    for(int i = t.size(); i >0; i--)
    {
        push_back(*itr);
        itr--;
    }
}


template< typename T>
T& List<T>::front()             // reference to the first element
{
    return *begin();
}


template< typename T>
const T& List<T>::front() const
{
    return *begin();
}


template< typename T>
T& List<T>::back()              // reference to the last element
{
    return *--end();
}


template< typename T>
const T& List<T>::back() const 
{
    return *--end();
}


template< typename T>
void List<T>::push_front(const T & val) // insert to the beginning
{
    insert(begin(),val);
}


template< typename T>
void List<T>::push_front(T && val)      // move version of insert
{
    insert(begin(),std::move(val));
}


template< typename T>
void List<T>::push_back(const T & val)  // insert to the end
{
    insert(end(),val);
}

template< typename T>
void List<T>::push_back(T && val)       // move version of insert
{
    insert(end(),std::move(val));
}

template< typename T>
void List<T>::pop_front()               // delete first element
{
    erase(begin());
}

template< typename T>
void List<T>::pop_back()                // delete last element
{
    erase(--end());
}

template< typename T>
void List<T>::remove(const T &val)      // remove all elements with value = val
{
    auto itr = this->begin();
    
    while(itr!=tail){
        if(*itr == val)
            erase(itr);
        itr++;}
    
}



//if functor is true then erase node, then increment
template< typename T>
template <typename PREDICATE>
void List<T>::remove_if(PREDICATE pred)
{
    for(auto itr = begin(); itr != end();)
        {   
        if(pred(*itr)==true)
            erase(itr);
       
            itr++;
        }
}







//print each node data 
template< typename T>
void List<T>::print(std::ostream& os, char) const
{
   auto itr = begin();
   
   while( itr != tail){
   os << *itr << ' ';
   itr++;}
}


template< typename T>
typename List<T>::iterator List<T>::begin()               // iterator to first element
{
    return iterator(head->next);
}


template< typename T>
typename List<T>::const_iterator List<T>::begin() const
{
    return const_iterator(head->next);
}


template< typename T>
typename List<T>::iterator List<T>::end()                 // end marker iterator
{
    return iterator(tail);
}


template< typename T>
typename List<T>::const_iterator List<T>::end() const 
{   
    return const_iterator(tail);
}


template< typename T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& val)  // insert val ahead of itr
{
    Node *p = itr.current;
    theSize++;
    return { p->prev = p->prev->next = new Node{ val, p->prev, p } };
}


template< typename T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val)      // move version of insert
{
    Node *p = itr.current;
    theSize++;
    return { p->prev = p->prev->next = new Node{ std::move( val ), p->prev, p } };
}


template< typename T>
typename List<T>::iterator List<T>::erase(iterator itr)                // erase one element
{
    Node *p = itr.current;
    iterator retVal{ p->next };
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    theSize--;

    return retVal;
}


template< typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end) // erase [start, end)
{
    for( iterator itr = start; itr != end; )
    itr = erase( itr );

    return end;
}

//check if size is equal first, return false if not
//then compare each node of each list
template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{   
    if(lhs.List<T>::size() != rhs.List<T>::size())
        return false;
        
    auto itr1 = lhs.begin();
    auto itr2 = rhs.begin(); 
        
    for(int i = 0; i !=lhs.List<T>::size(); i++)
        {
            if(*itr1 != *itr2)
            return false;

            itr1++;
            itr2++;   
        }
            
    return true;
}

//use of == overload
template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{
    if(lhs == rhs)
    return false;
    
    return true;
}


// overloading output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l)
{
    l.List<T>::print(os);

    return os;
}


//initilize a list
template <typename T>
void List<T>::init()
{
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}


















