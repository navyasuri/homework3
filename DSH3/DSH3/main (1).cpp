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
    
    oMap.put(TupleKeys("ORD", "PVD", "05May", "19:50"), TupleValues("AA 1828", "F9", "Y25", "02:13", "$186"));
    oMap.put(TupleKeys("ORD", "PVD", "05May", "09:53"), TupleValues("AA 1840", "F5", "Y15", "02:05", "$251"));
    oMap.put(TupleKeys("ORD", "PVD", "05May", "13:29"), TupleValues("AA 600", "F2", "Y0", "02:16", "$713"));
    oMap.put(TupleKeys("ORD", "PVD", "05May", "17:39"), TupleValues("AA 416", "F3", "Y9", "02:09", "$365"));
    
    // oMap.put(TupleKeys("", "", "", ""), TupleValues("", "", "", "", ""));
    
  
    SearchTree<Entry<TupleKeys,TupleValues> >::Iterator iter=oMap.begin() ;
    while( !(iter == oMap.end())) {
        cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
        ++iter;
    }

    SearchTree<Entry<TupleKeys,TupleValues> >::Iterator lower = oMap.lowerEntry(TupleKeys("ORD", "PVD", "05May", "13:00"));
    cout<<"lower than 13:00 is "<<(*lower).key()<<", "<<(*lower).value() <<endl;  

    
    SearchTree<Entry<TupleKeys,TupleValues> >::Iterator higher = oMap.higherEntry(TupleKeys("ORD", "PVD", "05May", "13:00"));
    cout<<"higher than 13:00 is "<<(*higher).key()<<", "<<(*higher).value() <<endl;  


    SearchTree<Entry<TupleKeys,TupleValues> >::Iterator ceiler = oMap.ceilingEntry(TupleKeys("ORD", "PVD", "05May", "13:29"));
    cout<<"ceiling of 13:29 is "<<(*ceiler).key()<<", "<<(*ceiler).value() <<endl;  


    SearchTree<Entry<TupleKeys,TupleValues> >::Iterator floorer = oMap.floorEntry(TupleKeys("ORD", "PVD", "05May", "13:29"));
    cout<<"floor of 13:29 is "<<(*floorer).key()<<", "<<(*floorer).value() <<endl;  

    SearchTree<Entry<TupleKeys,TupleValues> >::Iterator lower1 = oMap.lowerEntry(TupleKeys("ORD", "PVD", "05May", "13:29"));
    cout<<"lower than 13:29 is "<<(*lower1).key()<<", "<<(*lower1).value() <<endl;  

    
    SearchTree<Entry<TupleKeys,TupleValues> >::Iterator higher1 = oMap.higherEntry(TupleKeys("ORD", "PVD", "05May", "13:29"));
    cout<<"higher than 13:29 is "<<(*higher1).key()<<", "<<(*higher1).value() <<endl;  


    SearchTree<Entry<TupleKeys,TupleValues> >::Iterator ceiler1 = oMap.ceilingEntry(TupleKeys("ORD", "PVD", "05May", "13:00"));
    cout<<"ceiling of 13:00 is "<<(*ceiler1).key()<<", "<<(*ceiler1).value() <<endl;  


    SearchTree<Entry<TupleKeys,TupleValues> >::Iterator floorer1 = oMap.floorEntry(TupleKeys("ORD", "PVD", "05May", "13:00"));
    cout<<"floor of 13:00 is "<<(*floorer1).key()<<", "<<(*floorer1).value() <<endl;

    
#elif PART==4
    TupleKeys tkeys("ORD", "PVD", "05May", "09:53");
    
#endif
    return 0;
}
