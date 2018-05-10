#ifndef BINARYTREES_H_INCLUDED
#define BINARYTREES_H_INCLUDED

#include<iostream>
#include<list>
#include<stdio.h>

using namespace std ;

template <typename E>
class LinkedBinaryTree {

public:
    struct Node{
        E elt;
        Node* par;
        Node* left;
        Node* right;
        Node() : elt(), par(NULL), right(NULL), left(NULL){}
    };

public:
    class Position{
        public:
            Node* v;
        public:
            Position(Node* _v = NULL):v(_v){}
            E& operator*()
                {return v->elt;}
            Position left() const
                {return Position(v->left);}
            Position right() const
                {return Position(v->right);}
            Position parent() const
                {return Position(v->par);}
            bool isRoot() const
                {return v->par == NULL;}
            bool isExternal() const
                {return v->left == NULL && v->right == NULL;}
            bool isInternal() const
                {return !isExternal();}
            // 2 functions add by SF
            const E& operator*() const {return v->elt;}
            bool operator==(const Position& ppos) const { return this->v == ppos.v ;}
   
            friend class LinkedBinaryTree;
    

    };
typedef std::list<Position> PositionList;

public:
    LinkedBinaryTree();
    int getSize() const;
    bool isEmpty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expandExternal(const Position& p);
    Position removeAboveExternal(const Position& p);

protected:
    void preorder(Node* v, PositionList& pl) const;
private:
    Node* _root;
    int n;
};

template <typename E>
LinkedBinaryTree<E>::LinkedBinaryTree()
:_root(NULL), n(0) {}

template <typename E>
int LinkedBinaryTree<E>::getSize() const
{return n;}

template <typename E>
bool LinkedBinaryTree<E>::isEmpty() const
{return getSize() == 0;}

template <typename E>
typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::root() const
{return Position(_root);}

template <typename E>
void LinkedBinaryTree<E>::addRoot()
{_root = new Node; n = 1;}

template <typename E>
void LinkedBinaryTree<E>::expandExternal(const Position& p){
    Node* v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
}

template <typename E>
typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::removeAboveExternal(const Position& p){
    Node* w = p.v; Node* v = w->par;
    Node* sib = (w==v->left ? v->right:v->left);
    if(v == _root){
        _root = sib;
        sib->par = NULL;
    }
    else{
        Node* gpar = v->par;
        if(v == gpar->left) gpar->left = sib;
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w; delete v;
    n -= 2;
    return Position(sib);
};

template <typename E>
typename LinkedBinaryTree<E>::PositionList LinkedBinaryTree<E>::positions() const{
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}

template <typename E>
void LinkedBinaryTree<E>::preorder(Node* v, PositionList& pl) const{
    pl.push_back(Position(v));
    if(v->left != NULL)
        preorder(v->left, pl);
    if(v->right != NULL)
        preorder(v->right, pl);
}
#endif // BINARYTREES_H_INCLUDED
