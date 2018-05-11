#include <iostream>
#include "BinaryTrees.h"
#include "BinarySearchTrees.h"
#include "OrderedMap.h"
#include "tuples.h"

#define PART  3

using namespace std;

int main()
{
#if PART==1
    // LinkedBinaryTree of int type elems
    LinkedBinaryTree<int>  tr ;
    cout<<"Size tr1= "<<tr.getSize()<<endl ;
    tr.addRoot() ;
    tr.expandExternal(tr.root()) ;
    cout<<"Size tr1= "<<tr.getSize()<<endl ;
    
    // LinkedBinaryTree of Entry type elems
    LinkedBinaryTree<Entry<int, string>>  tr2 ;
    cout<<"\nSize tr2= "<<tr2.getSize()<<endl ;
    tr2.addRoot() ;
    tr2.expandExternal(tr2.root()) ;
    cout<<"Size tr2= "<<tr2.getSize()<<endl ;
    
    
#elif PART==2
    // Create a Search tree, fill it, then disply it
    SearchTree<Entry<int,int>> search ;
    cout<<"nSize= "<<search.getSize()<<endl ;

    search.insert(25,125) ;
    search.insert(35,135) ;
    search.insert(55,145) ;
    search.insert(55,155) ;
    cout<<"Size= "<<search.getSize()<<endl ;
    
    SearchTree<Entry<int,int>>::Iterator iter=search.begin() ;
    while( !(iter == search.end())) {
        cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
        ++iter;
    }

#elif PART==3
    // Create an OrderedMap, fill it, then disply it
    OrderedMap<TupleKeys, TupleValues > oMap ;
    cout<<"nSize= "<<oMap.getSize()<<endl ;

    oMap.put(TupleKeys("ORD", "PVD", "05May", "09:53"), TupleValues("AA 1840", "F5", "Y15", "02:05", "$251"));

    // oMap.put(TupleKeys("", "", "", ""), TupleValues("", "", "", "", ""));
    
  
    // SearchTree<Entry<TupleKeys,TupleValues> >::Iterator iter=oMap.begin() ;
    // while( !(iter == oMap.end())) {
    //     cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
    //     ++iter;
    // }

    // SearchTree<Entry<int,string> >::Iterator lower = oMap.lowerEntry(1200);
    // cout<<"lower is "<<(*lower).key()<<", "<<(*lower).value() <<endl;  


#elif PART==4
    TupleKeys tkeys("ORD", "PVD", "05May", "09:53");
    
#endif
    return 0;
}
