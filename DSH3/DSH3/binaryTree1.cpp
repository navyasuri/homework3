//
//  binaryTree1.cpp
//  DataStruct
//
//  Created by NYUAD on 5/1/18.
//  Copyright © 2018 NYUAD. All rights reserved.
//

#include "binaryTree1.hpp"

int SearchTree::size() const{
    return n;
}

bool SearchTree::empty() const{
    return n==0;
}

SearchTree::Iterator& SearchTree::Iterator::operator++(){
SearchTree::TPos w=v.right();
if(!w.isExternal()){
do {v=w; w=w.left();}
while (!w.isExternal());}
else{
    w=v.parent();
    while(v==w.right())
    {v=w; w=w.parent();}
    v=w;
}
return this;
}