//
//  binaryTree1.cpp
//  DataStruct
//
//  Created by NYUAD on 5/1/18.
//  Copyright © 2018 NYUAD. All rights reserved.
//

#include "binaryTree1.hpp"

int SearchTree::size() const
{
    return n;
}

bool SearchTree::empty() const
{
    return n == 0;
}

typedef typename BinaryTree::Position TPos;
TPos SearchTree::eraser(TPos &v)
{
    TPos w;
    if (v.left().isExternal())
        w = v.left(); // remove from left
    else if (v.right().isExternal())
        w = v.right(); // remove from right
    else
    {                  // both internal?
        w = v.right(); // go to right subtree
        do
        {
            w = w.left();
        } while (!w.isExternal()); // get leftmost node
        TPos u = w.parent();
        v−> setKey(u−> key());
        v−> setValue(u−> value()); // copy w’s parent to v
    }
    n−−;                             // one less entry
    return T.removeAboveExternal(w); // remove w and parent
}

void SearchTree::erase(const int &k)
{
}