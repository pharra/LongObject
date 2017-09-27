//
// Created by WF on 2017/9/17.
//

#pragma once
#include "Object.h"
#include <iostream>
using namespace std;
class LongObject {
private:

    long nSize;
    int _sign;
    IntObject * pHead;
    char *pDecimal_str;
    static IntObject * _int_object_new(int var);
    static char * _long_to_decimal_string_internal(LongObject * longobject);
public:
    explicit LongObject(int iVal);
    ~LongObject();
    friend ostream &operator << (ostream & ostream1, LongObject & a);
};

