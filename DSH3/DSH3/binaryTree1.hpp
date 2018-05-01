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
#include <string>
using namespace std;

class Entry
{
    public:
    Entry(const int& k = 0, const string& v = "") : _key(k), _value(v) {}

    // Getters
    const int& key() const{return _key;}
    const string& value() const{return _value;}

    // Setters
    void setKey(const int& k){_key = k;}
    void setValue(const string& v){_value = v;}

    private:
    int _key;
    string _value;


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
