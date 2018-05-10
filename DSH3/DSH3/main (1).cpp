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
    OrderedMap<int, string> oMap ;
    cout<<"nSize= "<<oMap.getSize()<<endl ;
    oMap.put(400,"f1") ;
    oMap.put(520,"f2") ;
    oMap.put(1800,"f3") ;
    oMap.put(2245,"f4") ;
    oMap.put(840,"f5") ;
    oMap.put(30,"f6") ;
    oMap.put(200,"f7") ;
    oMap.put(0,"f8") ;
    oMap.put(1230,"f9") ;
    oMap.put(1100,"f10") ;
    oMap.put(740,"f11") ;
    oMap.put(1930,"f12") ;
    oMap.put(2100,"f13") ;
    oMap.put(2330,"f14") ;
    oMap.put(1420,"f15") ;
    oMap.put(1315,"f16") ;
    oMap.put(1545,"f17") ;
    oMap.put(920,"f18") ;
    oMap.put(2010,"f19") ;
    oMap.put(630,"f20") ;
  
    SearchTree<Entry<int,string> >::Iterator iter=oMap.begin() ;
    while( !(iter == oMap.end())) {
        cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
        ++iter;
    }

    SearchTree<Entry<int,string> >::Iterator lower = oMap.lowerEntry(1200);
    cout<<"lower is "<<(*lower).key()<<", "<<(*lower).value() <<endl;  
    
#endif
    return 0;
}
