//
//  BinaryTree2.cpp
//  BinaryTree
//
//  Created by Maria Jaramillo on 4/6/18.
//  Copyright © 2018 Maria Jaramillo. All rights reserved.
//

#include "BinaryTree2.hpp"
#include <iostream>

using namespace std;

LinkedBinaryTree::Position::Position(Node* u) {
    v = u;
}

int& LinkedBinaryTree::Position::operator*() {
    return v->elem;
}

LinkedBinaryTree::Position LinkedBinaryTree::Position::left() const{
    return Position(v->left);
}

LinkedBinaryTree::Position LinkedBinaryTree::Position::right() const {
    return Position(v->right);
}

LinkedBinaryTree::Position LinkedBinaryTree::Position::parent() const {
    return Position(v->parent);
}

bool LinkedBinaryTree::Position::isRoot() const {
    return (v->parent == nullptr);
}

bool LinkedBinaryTree::Position::isExternal() const {
    return (v->left == nullptr && v->right == nullptr);
}

LinkedBinaryTree::LinkedBinaryTree() {
    _root = nullptr;
    n = 0;
}

int LinkedBinaryTree::size() const {
    return n;
}

bool LinkedBinaryTree::empty() const {
    return (n==0);
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {
    return Position(_root);
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
    
    pl.push_back(Position(v)); // why cant i just push back v
    
    if (v->left != nullptr) {
        preorder(v->left, pl);
    }
    
    if (v->right != nullptr) {
        preorder(v->right, pl);
    }
    
    else {
        return;
    }
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const {
    PositionList pl;
    LinkedBinaryTree::preorder(_root, pl);
    return PositionList(pl);
}

void LinkedBinaryTree::addRoot(int e) {
    _root = new Node;
    _root->elem = e;
    n = 1;
}

void LinkedBinaryTree::expandExteral(const LinkedBinaryTree::Position &e, int a, int b) {
    Node* parent = e.v;
    Node* left = new Node;
    left->elem = a;
    Node* right = new Node;
    right->elem = b;
    left->parent = parent;
    right->parent = parent;
    parent->left = left;
    parent->right = right;
    left->left = nullptr;
    left->right = nullptr;
    right->left = nullptr;
    right->right = nullptr;
    n+=2;
}

LinkedBinaryTree::Position LinkedBinaryTree::removeAboveExternal(const Position& p) {
    Node* currentNode = p.v;
    Node* parentofCurrent = currentNode->parent;
    
    Node* sibling = (currentNode == parentofCurrent -> left ? parentofCurrent -> right : parentofCurrent -> left );
    
    if (parentofCurrent == _root) {
        _root = sibling;
        sibling->parent = nullptr;
    }
    
    else {
        Node* grandpa = parentofCurrent->parent;
        
        if(parentofCurrent == grandpa->left) {
            grandpa->left  = sibling; //replace the two
        }
        else if (parentofCurrent == grandpa->right) {
            grandpa->right = sibling;
        }
        sibling->parent = grandpa; //connect it to the new parent
    }
    delete currentNode;
    delete parentofCurrent;
    n-=2;
    return Position(sibling);
}

void LinkedBinaryTree::display(PositionList& a) {
    for(list<Position>::iterator p= a.begin();  p != a.end(); ++p) {
        cout << **p << " ";
    }
}

void LinkedBinaryTree::printPreOrder(const LinkedBinaryTree::Position &a) {
    Node* current = a.v;
    
    cout << current->elem;
    if (current->left != nullptr) {
        printPreOrder(a.left());
    }
    
    if(current->right != nullptr) {
        printPreOrder(a.right());
    }
}


int LinkedBinaryTree::maxValue(PositionList& a) {
    int maxValue = *a.front();
    for(list<Position>::iterator p= a.begin();  p != a.end(); ++p) {
        if(**p > maxValue) {
            maxValue = **p;
        }
    }
    return maxValue;
}


void LinkedBinaryTree::addNode(int a) {
    LinkedBinaryTree::Position p = root();
    cout << "The current size of the tree is " << size() << " and our tree looks like " << endl;
    PositionList tree = positions();
    display(tree);
    cout << endl;
    while (!p.isExternal()) {
            if (a > *p) {
                if (p.v->right != nullptr) {
                    p = p.right();
                }
                else {
                    addRightChild(p, a);
                    return;
                }
            }
            else if (a < *p) {
                if(p.v->left != nullptr) {
                    p = p.left();
                }
                else {
                    addLeftChild(p, a);
                    return;
                }
            }
    }


    if (a > *p) {
        cout << a << " is greater than " << *p << endl;
        addRightChild(p, a);
    }
    else {
         cout << a << " is less  than " << *p << endl;
        addLeftChild(p, a);

    }
    
}
    
bool LinkedBinaryTree::hasTwoChildren(LinkedBinaryTree::Position &p) {
    if (p.v->left != nullptr && p.v->right != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void LinkedBinaryTree::addRightChild(LinkedBinaryTree::Position& p, int a) {
    Node* parent = p.v;
    Node* rightChild = new Node;
    rightChild->elem = a;
    rightChild->parent = parent;
    parent->right = rightChild;
    n++;
    
}

void LinkedBinaryTree::addLeftChild(LinkedBinaryTree::Position& p, int a) {
    Node* parent = p.v;
    Node* leftChild = new Node;
    leftChild->elem = a;
    leftChild->parent = parent;
    parent->left = leftChild;
    n++;
    
}


void LinkedBinaryTree::printPostOrder(const LinkedBinaryTree::Position& p) {
    Node* current = p.v;
    LinkedBinaryTree::Position left = p.left();
    LinkedBinaryTree::Position right = p.right();
    if (current->left != nullptr) {
        printPostOrder(left);
    }
    if (current->right != nullptr) {
        printPostOrder(right);
    }
    
    cout << current->elem;
}

int LinkedBinaryTree::minValue(const LinkedBinaryTree::Position& x) {
    LinkedBinaryTree::Position p = root();
    while (p.v->left != nullptr) {
        p = p.left();
    }
    return p.v->elem;
}

void LinkedBinaryTree::printInOrder(const LinkedBinaryTree::Position &p) {
    Node* current = p.v;
    LinkedBinaryTree::Position left = p.left();
    LinkedBinaryTree::Position right = p.right();
    
    if (current->left != nullptr) {
        printInOrder(left);
    }
    cout << current->elem;
    
    if(current->right != nullptr) {
        printInOrder(right);
    }
}
int LinkedBinaryTree::maxDepth(const LinkedBinaryTree::Position& a, int currentDepth) {
    int depthLeft = 0;
    int depthRight = 0;
    
    if(a.isExternal()) {
        return currentDepth;
    }
    if (a.v->left != nullptr) {
        depthLeft = maxDepth(a.left(), currentDepth+1);
    }
    if (a.v->right != nullptr) {
         depthRight = maxDepth(a.right(), currentDepth+1);
    }
    
    if (depthLeft > depthRight) {
        cout << "depth left is more" << endl;
        return depthLeft;
    }
    else {
        cout << "depth right is more" << endl;
        return depthRight;
    }
}

int LinkedBinaryTree::height(const LinkedBinaryTree::Position &p) {
    int heightLeft = 0;
    int heightRight = 0;
    if (p.isExternal()) {
        return 0;
    }
    if(p.v->left != nullptr) {
        heightLeft = height(p.left()) + 1;
    }
    if(p.v->right != nullptr) {
        heightRight = height(p.right()) + 1;
    }
    
    if (heightLeft > heightRight) {
        return heightLeft;
    }
    
    else {
        return heightRight;
    }
}

void LinkedBinaryTree::EulerWalk(const LinkedBinaryTree::Position &p) {
    if (p.isExternal()) {
        cout << p.v->elem;
    }
    else {
        cout << "(";
        if (p.v->left != nullptr) {
            EulerWalk(p.left());
            cout << p.v->elem;
        }
        if (p.v->right != nullptr) {
            EulerWalk(p.right());
            cout << p.v->elem;
        }
        cout << ")";
    }
}

void LinkedBinaryTree::EulerWalk2(const LinkedBinaryTree::Position &p) {
    cout << p.v->elem;
    if(!p.isExternal()) {
        EulerWalk2(p.left());
    }
    if(!p.isExternal()) {
        cout << p.v->elem;
    }
    
    if (!p.isExternal()) {
        EulerWalk2(p.right());
    }
    
    if(!p.isExternal()) {
        cout << p.v->elem;
    }

}



