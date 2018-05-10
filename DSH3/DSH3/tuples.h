#ifndef Tuples_h
#define Tuples_h

#include "OrderedMap.h"

template <typename KK, typename VV>
class TupleKeys{
    string A, B, C, D;
    TupleKeys(string a, string b, string c, string d):A(a), B(b), C(c), D(d){}

};

class TupleValues{
    string A, B, C, D;
    TupleValues(string a, string b, string c, string d):A(a), B(b), C(c), D(d){}
};

#endif
