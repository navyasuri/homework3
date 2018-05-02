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

SearchTree::
