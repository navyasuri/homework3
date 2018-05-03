//
//  BinaryTree.hpp
//  redo
//
//  Created by NYUAD on 5/2/18.
//  Copyright © 2018 NYUAD. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp
#include<iostream>
#include<list>
using namespace std;
#include <stdio.h>

class Entry
{
public:
    Entry(const int &k = 0, const string &v = "") : _key(k), _value(v) {}
    
    // Getters
    const int key() const { return _key; }
    const string value() const { return _value; }
    
    // Setters
    void setKey(const int &k) { _key = k; }
    void setValue(const string &v) { _value = v; }
private:
    int _key;
    string _value;
    friend class SearchTree;
};
class BinaryTree{
public:
    
    struct Node{
        Entry elt;
        Node* par;
        Node* left;
        Node* right;
        Node():elt(),par(NULL),left(NULL),right(NULL){}
    };
public:
    class Position{
    private:
        Node* v;
    public:
       
        Position(Node* _v=NULL):v(_v){}
        Entry& operator*() const {return v->elt;}
        //int operator*(){return v->elt.key();}
        Position left() const {return Position(v->left);}
        Position right() const {return Position(v->right);}
        Position parent() {return Position(v->par);}
        bool isRoot() const{return v->par==NULL;}
        bool isExternal() const {return v->left==NULL && v->right==NULL;}
        bool isInternal() const {return !isExternal();}
        friend class BinaryTree;
        friend class SearchTree;
    }; typedef list<Position> PositionList;
public:
    BinaryTree();
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expandExternal(const Position&p);
    Position removeAboveExternal(const Position& p);
    
protected:
    void preorder(Node* v, PositionList& pl) const;
private:
    Node* _root;
    int n;
public:
    friend class SearchTree;
};


class SearchTree{
public:
    class Iterator;
public:
    SearchTree(): T(), n(0) {T.addRoot(); T.expandExternal(T.root());}
    int size() const;
    bool empty() const;
    Iterator find(const int& K);
    Iterator insert(const int& k, const string& x);
    void erase(const int& K); //need to add the exception
    void erase(Iterator& p); //we need to drop the const for it to work
    Iterator begin();
    Iterator end();
protected:
    //typedef typename BinaryTree::Position Tpos;
    typedef  BinaryTree::Position Tpos;
    Tpos root() const;
    Tpos finder(const int& k, const Tpos& x);
    Tpos inserter(const int& k, const string& v);
    Tpos eraser(Tpos& s);
    Tpos restructure(const Tpos& v); // why would we need a restructure operation
private:
    BinaryTree T;
    int n;
public:
    
    class Iterator{
    private:
        Tpos t;
    public:
        Iterator(Tpos& vv):t(vv){}
        const Entry& operator*() const { return *t;};
        Entry& operator*() { return *t;};
        
//        int operator*() {return t.v->elt.key();}
//        bool operator==(const Iterator& p) const {
//            //return &(t.v->elt) == &(p.t.v->elt); //this would compare addresses
//            return t.v->elt.key() == p.t.v->elt.key();} //this would compare the keys
        Iterator& operator++();
        friend class SearchTree;
    };
    
};
    
    

#endif /* BinaryTree_hpp */
