#ifndef Tuples_h
#define Tuples_h

#include "OrderedMap.h"

#include <bits/stdc++.h>
#include <algorithm>
#include <sstream>

// using namespace std;

string RemoveChar(string str, char c) 
{
   string result;
   for (size_t i = 0; i < str.size(); i++) 
   {
          char currentChar = str[i];
          if (currentChar != c)
              result += currentChar;
   }
       return result;
}

// template <typename KK, typename VV>
class TupleKeys{
    public:
    string A, B, C, D;
    int DTime;
    TupleKeys(string a, string b, string c, string d):A(a), B(b), C(c), D(d){
        string timer = RemoveChar(D, ':');
        int timeInt = atoi(timer.c_str());
        DTime = timeInt;
    }

    bool operator <(const TupleKeys& tk){
        return DTime < tk.DTime;
    }

    bool operator >(const TupleKeys& tk){
        return DTime > tk.DTime;
    }

    bool operator == (const TupleKeys& tk){
        return DTime == tk.DTime;
    }

    bool operator != (const TupleKeys& tk){
        return DTime != tk.DTime;
    }
    
};

class TupleValues{
    public:
    string A, B, C, D, E;
    TupleValues(string a, string b, string c, string d, string e):A(a), B(b), C(c), D(d), E(e){}
};


#endif
