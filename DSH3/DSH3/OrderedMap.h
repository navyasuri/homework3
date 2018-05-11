#ifndef DirectedMap_h
#define DirectedMap_h

#include "BinarySearchTrees.h"

#define COUNT 10

template <typename KK, typename VV>
class OrderedMap: public SearchTree<Entry<KK,VV> > {
public:
    // Usefull Typedef
    typedef  SearchTree<Entry<KK,VV> > BST;
    typedef typename SearchTree<Entry<KK,VV> >::Iterator BSTIterator;

public:
    OrderedMap(): SearchTree<Entry<KK,VV> >(){}
    int size () const ;
    bool empty () const ;
    BSTIterator find ( const KK& k) const {find(k);}
    BSTIterator put ( const KK& k, const VV& v){return BST::insert(k,v) ;}
    void erase ( const KK& k) ;
    void erase ( const BSTIterator & p);
    BSTIterator begin () {return BST::begin(); }
    BSTIterator end () {return BST::end();}
    // void print2DUtil(int space);


    BSTIterator firstEntry(){
        return BST::begin();
    }

    BSTIterator lastEntry(){
        BSTIterator starter = BST::begin();
        for (int i = 0; i<size(); i++){
            ++starter;
        }
        return starter;
    }

    BSTIterator ceilingEntry(const KK& key){
        BSTIterator starter = firstEntry();
        while (!(starter == BST::end()) && key>(*starter).key()){
            ++starter;
        }
        return starter;
    }

    BSTIterator floorEntry(const KK& key){
        BSTIterator starter = firstEntry();
        BSTIterator oneAhead = ++starter;
        while (!(oneAhead == BST::end()) && key>=(*oneAhead).key()){
            ++oneAhead;
            ++starter;
        }
        return starter;
    }

    BSTIterator lowerEntry(const KK& key){
        BSTIterator starter = firstEntry();
        BSTIterator oneBehind = starter;
        if (!(starter == BST::end()) && key>(*starter).key()){
            ++starter;
        }

        while(!(starter == BST::end()) && key>(*starter).key()){
            ++starter;
            ++oneBehind;
        }
        return oneBehind;
    }

    BSTIterator higherEntry(const KK& key){
        BSTIterator starter = firstEntry();
        while (!(starter == BST::end()) && key>=(*starter).key()){
            ++starter;
        }
        return starter;
    }
    
    
} ;

template <typename KK, typename VV>
int OrderedMap<KK,VV>::size() const {return SearchTree<Entry<KK,VV> >::getSize() ;}

template <typename KK, typename VV>
bool OrderedMap<KK,VV>::empty() const {return SearchTree<Entry<KK,VV> >::isEmpty() ; }


#endif /* DirectedMap_h */
