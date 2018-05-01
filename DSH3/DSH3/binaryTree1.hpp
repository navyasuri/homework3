//
//  binaryTree1.hpp
//  DataStruct
//
//  Created by NYUAD on 5/1/18.
//  Copyright © 2018 NYUAD. All rights reserved.
//

#ifndef binaryTree1_hpp
#define binaryTree1_hpp

#include <stdio.h>
using namespace std
#include <string> 

class Entry
{
    int Key;
    string Value;

  public:
    Entry(const int &k = int(), const string &v = ()) : _key(k), _value(v) {}
};

class SearchTree
{
  public:
    class Iterator;

  public:
    SearchTree();
    int size() const;
    bool empty() const;
    Iterator find(const int &k);
    Iterator insert(const int &k, const string &x);
    void erase(const int &k) throw(NonexistentElement);
    void erase(const Iterator &p);
    Iterator begin();
    Iterator end();

  protected:
    typedef BinaryTree<Entry> BinaryTree;
    typedef typename BinaryTree::Position TPos;
    TPos root() const;
    TPos finder(const int &k, const TPos &v);
    TPos inserter(const int &k, const string &x);
    TPos eraser(TPos &v);
    TPos restructure(const TPos &v) throw(BoundaryViolation);

  private:
    BinaryTree T;
    int n;

  public:
    // . . .insert Iterator class declaration here
    // I made a change
};

#endif /* binaryTree1_hpp */
