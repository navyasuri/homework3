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
template <typename K, typename V>
class Entry
{
    typedef K Key;
    typedef V Value;

  public:
    Entry(const K &k = K(), const V &v = V()) : _key(k), _value(v) {}
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
    typedef BinaryTree<int, string> BinaryTree;
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
