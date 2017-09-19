//
// Created by WF on 2017/9/17.
//

#ifndef FACTORIAL_LongObject_H
#define FACTORIAL_LongObject_H

#include "Object.h"
#include "IntBlockManager.h"
class LongObject {
private:

    long nSize;
    IntObject * _intobject_new(int var);
    int _sign;
    char **pDecimal_str;
    static int _long_to_decimal_string_internal(LongObject & longobject, char ** pDecimal_str);
public:
    LongObject(int iVal);
    ~LongObject();
    IntObject * pHead;
};


#endif //FACTORIAL_LongObject_H
