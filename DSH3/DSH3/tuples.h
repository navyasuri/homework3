#ifndef Tuples_h
#define Tuples_h

#include "OrderedMap.h"

#include <bits/stdc++.h>

template <typename KK, typename VV>
class TupleKeys{
    string A, B, C, D;
    char* DArray;
    TupleKeys(string a, string b, string c, string d):A(a), B(b), C(c), D(d){
        int dLen = D.length();
        DArray = new char[dLen];
    }
    
};

class TupleValues{
    string A, B, C, D;
    TupleValues(string a, string b, string c, string d):A(a), B(b), C(c), D(d){}
};

#endif
