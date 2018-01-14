#include <iostream>
#include <string>

#include "tlist.h"

using namespace std;

template <typename T> 
void PrintList(const TList<T>& L, string label)
{
   cout << label << " size is: " << L.GetSize() << "\n"
        << label << " = "; 
   L.Print(cout);
   cout << "\n\n";
}

int main()
{

    TList<string> L1;
    TList<char> L2;

    TListIterator<char> itr = L2.GetIterator();
//first use of iterator, use of different types
//first use of iterator, use of different types    
    L2.Insert(itr, 'i');
    itr = L2.GetIterator();
    L2.InsertFront('f');
    L2.Insert(itr, 'i');
    itr.Next();
    L2.InsertFront('f');
    itr.Next();
    L2.Insert(itr, 'i');
    L2.InsertFront('f');
    itr.Next();
    L2.Insert(itr, 'i');
    PrintList(L2, "L2");
    
    L2.InsertBack('b');	
    L2.Insert(itr, 'i');
    L2.Insert(itr, 'i');
    L2.InsertBack('b');	
    L2.InsertBack('b');
    L2.Insert(itr, 'i');
    itr.Next();
    PrintList(L2, "L2");
    
     L2.RemoveFront();
    L2.InsertBack('b');	
    L2.RemoveFront();
    L2.InsertBack('b');
    L2.RemoveFront();
    L2.InsertBack('b');	
    PrintList(L2, "L2");
    
    L2.RemoveFront();
    L2.RemoveBack();
    L2.RemoveFront();
    L2.RemoveBack();
    L2.RemoveFront();
    L2.RemoveBack();
    PrintList(L2, "L2");
    
    
    
    
    L2.Insert(itr, 'i');
    itr.Next();
    L2.RemoveBack();
    L2.Insert(itr, 'i');
    itr.Next();
    L2.RemoveBack();
    L2.Insert(itr, 'i');
    itr.Next();
    L2.RemoveBack();
    PrintList(L2, "L2");
    
     L2.InsertBack('b');	
    L2.InsertFront('f');
    L2.InsertFront('f');

    
     L2.InsertFront('f');
    L2.InsertFront('f');
    L2.RemoveBack();
    L2.InsertFront('f');
    
    
    PrintList(L2, "L2");
    
    L2.Remove(itr);
    L2.Remove(itr);
    L2.Remove(itr);
    L2.InsertBack('b');	
    PrintList(L2, "L2");
    
    L2.Remove(itr);
    L2.Remove(itr);
    L2.Remove(itr);
    L2.InsertBack('b');	
    PrintList(L2, "L2");
    L2.Remove(itr);
    L2.Remove(itr);
    L2.Remove(itr);
    L2.InsertBack('b');	
    PrintList(L2, "L2");

    

    
    L2.Remove(itr);
    PrintList(L2, "L2");
        L2.Remove(itr);
    PrintList(L2, "L2");
        L2.Remove(itr);
    PrintList(L2, "L2");
        L2.Remove(itr);
    PrintList(L2, "L2");
        L2.Remove(itr);
    PrintList(L2, "L2");
    
    L1.RemoveFront();
     L1.RemoveBack();
     PrintList(L2, "L2");
    
     L1.RemoveFront();
     L1.RemoveBack();
    PrintList(L1, "L1");
    
         L1.RemoveFront();
     L1.RemoveBack();
    PrintList(L1, "L1");
    
         L1.RemoveFront();
     L1.RemoveBack();
    PrintList(L1, "L1");
    
       L1.InsertFront("fstring1");
     L1.InsertBack("bstring1");
    L1.InsertFront("fstring2");
    L1.InsertBack("bstring2");
    L1.InsertFront("fstring3");
    L1.InsertBack("bstring3");
    PrintList(L1, "L1");
    
    TListIterator<string> itr1 = L1.GetIteratorEnd();
    
    cout << itr1.GetData();
    itr1.Previous();
    cout << itr1.GetData();

     L2.InsertBack('b');	
    L2.InsertFront('f');
    L2.InsertFront('f');
    L2.InsertFront('f');
    L2.RemoveBack();
    L2.InsertFront('f');    
    
    PrintList(L2, "L2"); 
    

    TList<double> L3(3.14,10);
    PrintList(L3, "L3");
    
    
    
    cout << "\n\n\n\n";
    
    
    
    
    
    
     
//use of getsize,isempty, and clear 
    cout << "\nGet size L3 function return: "<< L3.GetSize();
    cout << "\nIsempty test return 1 if it is true: " << L3.IsEmpty();
    cout << "\nclear function now for L3: "; L3.Clear();
    cout << "\nGet size L3 function return: "<< L3.GetSize();
    cout << "\nIsempty test return 1 if it is true: " << L3.IsEmpty();
    cout << '\n';



    cout << "\n\n\n\n";
    
    //use of getfirst and getlast
    PrintList(L1, "L1");
    cout << "L3 first: " << L1.GetFirst() << "\nL3 last: " <<L1.GetLast() << endl;
    
    
    L3.InsertFront(8.8);
    L3.InsertFront(7.7);
    L3.InsertFront(6.6);

    cout << "\n\n\n\n";


//use of constructor with two parameters
    TList<double> L5(3.14,10);
    
    TList<double>L4 = L3 + L5;
    
    PrintList(L4, "L4"); 
    
    
    cout << "\n\n\n\n";


//assignment operator/copy constructor 
    
    L3 = L4;
    
    PrintList(L3, "L3"); 
    
    
    
    
    }
