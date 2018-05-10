#include <iostream>
#include "BinaryTrees.h"
#include "BinarySearchTrees.h"
#include "OrderedMap.h"

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
    OrderedMap<int, int> oMap ;
    cout<<"nSize= "<<oMap.getSize()<<endl ;
    oMap.put(25,125) ;
    oMap.put(35,135) ;
    oMap.put(55,145) ;
    oMap.put(55,155) ;
  
    SearchTree<Entry<int,int>>::Iterator iter=oMap.begin() ;
    while( !(iter == oMap.end())) {
        cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
        ++iter;
    }
    
#endif
    return 0;
}
