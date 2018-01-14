#include <iostream>
#include <string>



//default constructor. first, last set to null, size set to zero.
template< typename T>
TList<T>::TList():first(nullptr),
                  last(nullptr),
                  size(0)
{   
    
}


//uses insert front to fill list if num is greater than zero
template< typename T>
TList<T>::TList(T val, int num)
{

    first = last= NULL;
    size = 0;
    
    for(int i = num; i>0; i--)
        InsertFront(val);       
}


//destructor
template< typename T>
TList<T>::~TList()
{
    Clear();
}


//copy constructor
//uses iterator to walk through tlist L and inserts 
//each element to insertback
template< typename T>
TList<T>::TList(const TList& L)
{
            first = last = NULL;

            TListIterator<T> itr;
            itr = L.GetIterator();
         
            size = 0;
            
            for(int i = L.size; i>0; i--){
                InsertBack(itr.TListIterator<T>::GetData());
                itr.TListIterator<T>::Next();}     
}


//assignmentoperator, similar to the copy constructor process, but if 
//the object == L then it is cleared before building
template< typename T>
TList<T> TList<T>::operator=(const TList& L)
{
    if( this!= &L)
        {
            TListIterator<T> itr;
            itr = L.GetIterator();
            
            Clear();
            size = 0;
            
            for(int i = L.size; i>0; i--){
                InsertBack(itr.TListIterator<T>::GetData());
                itr.TListIterator<T>::Next();}           
        }
        
    return *this;
}


//move copy constructor
template< typename T>
TList<T>::TList(TList && L)
{
    

    TListIterator<T> itr;
    itr = L.GetIterator();    
    size = L.size;
    
    for(int i = size; i>0; i--){
        InsertBack(itr.TListIterator<T>::GetData());
        itr.TListIterator<T>::Next();}
        
    L.Clear();       
}

//standard move assignment operator,
//saves temp copies of the passes in object data
//then switches data
template< typename T>
TList<T> TList<T>::operator=(TList && L)
{
    int temp = size;
    Node<T> *ptr1 = first;
    Node<T> *ptr2 = last;

    size = L.size;
    first = L.first;
    last = L.last;
    
    L.size = temp;
    L.first = ptr1;
    L.last = ptr2;    

    return *this;    
    
}   

//returns true if empty, false if not empty
template< typename T>
bool TList<T>::IsEmpty() const
{
    if(size == 0)
        return true;
    else
        return false;
}


//removes front for passed in size of object
template< typename T>
void TList<T>::Clear()
{
    for(int i=size;i>=0;i--)
    {
        RemoveFront();
    }
}


//returns size 
template< typename T>
int TList<T>::GetSize() const
{
    return size;
}


//if empty, set first and last to ptr1 and increase size by 1;
template< typename T>
void TList<T>::InsertFront(const T& d)
{
    Node<T> *ptr1  = new Node<T>(d);
    
    if(IsEmpty()){
        first = last = ptr1;
        size = size +1;}
    else{
        first->prev = ptr1;
        ptr1->next = first;
        first = ptr1;      
        size = size +1;}
        
    
    
}

//same idea as insertfront;
template< typename T>
void TList<T>::InsertBack(const T& d)
{
    Node<T> *ptr1  = new Node<T>(d);
    
    if(IsEmpty()){
        first = last = ptr1;
        size = size +1;}
    else{
        last->next = ptr1;
        ptr1->prev = last;
        last = ptr1;
        size = size +1;}
        
    
}


//if size is 1 then set first and last to null but decrease size by 1
//if size is 0 first and last are null but dont decrease size;
//else just arrange pointers accordingly;
template< typename T>
void TList<T>::RemoveFront()
{
    Node<T> *ptr1 = first;

    if(size == 1){
        first = last = NULL;
        size = size-1;}
    else if(size == 0)
        first = last = NULL;
    else{
        first = first->next;
        size = size - 1;}
        
    delete ptr1;    
}

template< typename T>
void TList<T>::RemoveBack()
{

    if(size == 1){
        first = last = NULL;
        size = size - 1;}
    else if(size==0)
        first = last = NULL;
    else{
        last = last->prev;
        size = size - 1;}
}

//return first if there is data; else return dummy;
template< typename T>
T& TList<T>::GetFirst() const
{
    if(size > 0)
        return first->data;
    else
        return dummy;
}

//return last if data else return dummy;
template< typename T>
T& TList<T>::GetLast() const
{
    if(size > 0)
        return last->data;
    else
        return dummy;
}

//sets an iterator to the first element of a tlist object
template< typename T>
TListIterator<T> TList<T>::GetIterator() const
{   
    TListIterator<T> itr;
        
    itr.ptr = first;
    return itr;
}

//sets an iterator to the last element of a tlistobject
template< typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const
{
    TListIterator<T> itr;
    
    itr.ptr = last;
    
    return itr;
}

//dynamically allocates the node to be inserted
//then if iterator position is at the front, insertfront
//otherwise set pointers accordingly
template< typename T>
void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
    Node<T> *ptr1  = new Node<T>(d);
    
    

    if(pos.ptr==first){
        InsertFront(d);}
    else{
        ptr1->next = pos.ptr;
        ptr1->prev = pos.ptr->prev;
        pos.ptr->prev->next = ptr1;
        pos.ptr->prev = ptr1;
        size = size+1;
        }    
} 

//if size is zero or 1 then removefront
//if pos points to last then remove last
//else set pointers accordingly and delete the node removed
template< typename T>
TListIterator<T> TList< T >::Remove(TListIterator<T> pos)
{    
    if(pos.ptr == first||size == 0){
        RemoveFront();
        }
    else if(pos.ptr == last)
        RemoveBack();
    else{
        pos.ptr->next->prev = pos.ptr->prev;
        pos.ptr->prev->next = pos.ptr->next;
        size = size-1;
        }   
    return pos;
    
}


//use of iterator to walk through the list
template< typename T >
void TList<T>::Print(std::ostream& os, char) const
{
    TListIterator<T> itr;
    
    itr = GetIterator();
    int i = size;
    
    while(i!=0){
        os << itr.ptr->data;
        
        itr.TListIterator<T>::Next(); os << ' ';
        
        i--;
        }
}




//sets iterator to null as default constructor
template <typename T>
TListIterator<T>::TListIterator()
{
    ptr = NULL;
        
}


//returns true if next is not null, false otherwise
template <typename T>
bool TListIterator<T>::HasNext() const
{
    if(ptr->next != '\0')
        return true;
    else
        return false;   
}

//returns true if prev is not null, false otherwise
template <typename T>
bool TListIterator<T>::HasPrevious() const
{
    if(ptr->prev != '\0')
        return true;
    else
        return false;
}

//move ieterator forward if possible
template <typename T>
TListIterator<T> TListIterator<T>::Next()

{
    if(HasNext()){
        ptr=ptr->next;}
        
    return *this;
}

//move iterator backwards if possible
template <typename T>
TListIterator<T> TListIterator<T>::Previous()
{
    if(HasPrevious()){
        ptr=ptr->prev;}
        
    return *this;
}


//return what the iterator is currently looking at
template <typename T>
T& TListIterator<T>::GetData() const
{
    return ptr->data;
}

//use of two iterators
//first iterator set to t1 and the second to t2
//walk through the list and insertback of the tlist t3
//repeat for the second list t2 into t3.
template <typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2)
{

    TList<T> t3; 
    TListIterator<T> itr,itr1;
   
    itr=t1.TList<T>::GetIterator();
    itr1=t2.TList<T>::GetIterator();
    
    for(int i = t1.TList<T>::GetSize(); i>0; i--)
    {
        t3.TList<T>::InsertBack(itr.TListIterator<T>::GetData());
        itr.TListIterator<T>::Next();
    }
    
    
    
    for(int i = t2.TList<T>::GetSize(); i>0; i--)
    {
        t3.TList<T>::InsertBack(itr1.TListIterator<T>::GetData());
        itr1.TListIterator<T>::Next();
   
    }
   
    return t3;

}













