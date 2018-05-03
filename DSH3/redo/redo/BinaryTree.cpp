//
//  BinaryTree.cpp
//  redo
//
//  Created by NYUAD on 5/2/18.
//  Copyright © 2018 NYUAD. All rights reserved.
//

#include "BinaryTree.hpp"

BinaryTree::BinaryTree(): _root(NULL), n(0) {}
int BinaryTree::size() const
    {return n;}
bool BinaryTree::empty() const
{
        return n==0;
}
BinaryTree::Position BinaryTree::root() const
{
    return Position(_root);
}

void BinaryTree::addRoot() // adding root to empty tree
{
    _root=new Node; n=1;
}
void BinaryTree::expandExternal(const Position&p)
{
    Node*v=p.v;
    v->left=new Node;
    v->left->par=v;
    v->right=new Node;
    v->right->par=v;
    n+=2;
}

BinaryTree::Position BinaryTree::removeAboveExternal(const BinaryTree::Position &p)
{
    Node*w=p.v;
    Node*v=w->par;
    Node*sib = (w==v->left ? v-> right : v->left);
    if(v==_root){
        _root=sib;
        sib->par=NULL;
    }
    else{
        Node* gpar=v->par;
        if (v==gpar->left) gpar->left=sib;
        else gpar->right=sib;
        sib->par=gpar;
        sib->par=gpar;
    }
    delete w; delete v;
    n-=2;
    return Position(sib);
}

BinaryTree::PositionList BinaryTree::positions() const{
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}

void BinaryTree::preorder(Node* v, PositionList& pl)const {
    pl.push_back(Position(v));
    if (v-> left !=NULL)
        preorder(v->left,pl);
    if (v->right !=NULL)
        preorder(v->right,pl);

}

SearchTree::Iterator& SearchTree::Iterator::operator++(){
    Tpos w= t.right();
    if (w.isInternal()){
        do{t=w; w=w.left();}
            while(w.isInternal());
    }
        else {
            w = t.parent(); {
                t = w; w = w.parent();
            }
            t = w;
        }
    return *this;
}

int SearchTree::size() const{
    return n;
}

bool SearchTree::empty() const {
    return n==0;
}

SearchTree::Tpos SearchTree::finder(const int& k, const Tpos& x) {

    
    if (x.isExternal()) {
        return x;
    }
    
    if (k < x.v->elt.key()) {
        return finder(k, x.left());
    }
    else if (k > x.v->elt.key()) {
        return finder(k, x.right());
    }
    else {
        return x;
    }
    

    if (k < (*x).key()) {
        finder(k, x.left());
    }
    
}

//SearchTree::Iterator SearchTree::find(const int& K) { // returns an iterator rather than a Tpos
//
//    Tpos v = finder(K, root()); //begin by looking at the root
//
//    if (v.isInternal()) {
//        return Iterator(v);
//    }
//    else {
//        return end(); // this means it did not find it
//    }
//
//}

SearchTree::Tpos SearchTree::inserter(const int& k, const string& v) {
    Tpos w = finder(k, root());
    while (w.isInternal()) { // the key is already there, we have to look to the right because whenever a key is the same, we gon right rather than left
        w = finder(k, w.right());
    }
    
    T.expandExternal(w);
    w.v->elt.setKey(k);
    w.v->elt.setValue(v);
    n++;
    return w;
}

SearchTree::Iterator SearchTree::insert(const int& k, const string& x) { //only purpose is to call the inserter and return an iterator
    Tpos v = inserter(k, x);
    return Iterator(v);
}

SearchTree::Tpos SearchTree::eraser(Tpos& s) {
    Tpos w;
    if(s.left().isExternal()) {
        w=s.left();
    }
    else if (s.right().isExternal()) {
        w=s.right();
    }
    else {
        w = s.right(); // start searching right subtree
        do {
            w = s.left();
        }
        while (
               w.isInternal() // keet doing this until w is external
               );
        Tpos u = w.parent();
        s.v->elt.setKey(u.v->elt.key());
        s.v->elt.setValue(u.v->elt.value());
    }
    n--;
    return T.removeAboveExternal(w);
}

void SearchTree::erase(const int& K) {
    Tpos v = finder(K, root());
    eraser(v);
    // throw an exception for when v.isExternal
}

void SearchTree::erase(Iterator& p){
    eraser(p.t); // the Tpos in class Iterator is called t;
}

SearchTree::Tpos SearchTree::root() const {
    return T.root().left(); // there is a super root that is created in the constructor, so the "real root" is this one
}






