//
//  BinaryTree2.hpp
//  BinaryTree
//
//  Created by Maria Jaramillo on 4/6/18.
//  Copyright © 2018 Maria Jaramillo. All rights reserved.
//

#ifndef BinaryTree2_hpp
#define BinaryTree2_hpp

#include <stdio.h>

using namespace std;
//#include <int>
#include <list>





class LinkedBinaryTree {
protected:
    struct Node {
        int elem;
        Node* parent;
        Node* left;
        Node* right;
        
        Node () : elem () , parent( NULL ) , left ( NULL ) , right ( NULL ) { };
    };
    
public:
    class Position {
    public:
        Position(Node* u = nullptr);
        int& operator*();
        Position left() const;
        Position right() const;
        Position parent() const;
        bool isRoot() const;
        bool isExternal() const;
        
        friend class LinkedBinaryTree;
        
    private:
        Node* v;
    };
    typedef std::list<Position> PositionList;
    
public:
    LinkedBinaryTree();
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot(int e);
    void expandExteral(const Position& e, int a, int b);
    Position removeAboveExternal(const Position& e);
    void display(PositionList& a);
    void printPreOrder(const Position& a);
    int maxDepth(const Position& a, int currentDepth);
    int maxValue(PositionList& a);
    void addNode(int a);
    bool hasTwoChildren(Position& p);
    void printPostOrder(const Position& p);
    int minValue(const Position& x); // use the fact that its a binary search tree
    void printInOrder(const Position& p);
    int height(const Position& p);
    void EulerWalk(const Position& p);
    void EulerWalk2(const Position& p);
    
protected:
    void preorder(Node* v, PositionList& pl) const;
    void addRightChild(Position& p, int a);
    void addLeftChild(Position& p, int a);
    bool isValid(Position& p) const;
    
private:
    Node* _root;
    int n;
};

#endif /* BinaryTree2_hpp */
