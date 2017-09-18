//
// Created by WF on 2017/9/17.
//

#include "LongObject.h"


IntObject * LongObject::_intobject_new(int var){
    if(IntBlockManager::pFree_list == nullptr){
        IntBlockManager::pFree_list = IntBlockManager::_fill_free_list();
    }
    pHead = IntBlockManager::pFree_list;
    while (var > 0){
        IntBlockManager::pFree_list = IntBlockManager::pFree_list->pNext;
        if(IntBlockManager::pFree_list == nullptr){
            IntBlockManager::pFree_list = IntBlockManager::_fill_free_list();
        }
        var--;
    }
    nSize = var;
    return pHead;
}



LongObject::~LongObject(){
    IntObject *p = IntBlockManager::pFree_list;
    while (p->pNext != nullptr){
        p = p->pNext;
    }
    p->pNext = pHead;
    while (nSize > 0){
        pHead  = pHead->pNext;
        nSize --;
    }
    pHead = nullptr;
}


LongObject::LongObject(int ival){

    IntObject *v;
    unsigned int abs_ival;
    unsigned int t;  /* unsigned so >> doesn't propagate sign bit */
    int ndigits = 0;
    int sign;
    if (ival < 0) {
        /* negate: can't write this as abs_ival = -ival since that
           invokes undefined behaviour when ival is LONG_MIN */
        abs_ival = 0U-(unsigned int)ival;
        sign = -1;
    }
    else {
        abs_ival = (unsigned int)ival;
        sign = ival == 0 ? 0 : 1;
    }

    /* Fast path for single-digit ints */
    if (!(abs_ival >> INTOBJECT_SHIFT)) {
        v = _intobject_new(1);
        if(v){
            _sign = sign;
            v->ob_digit[0] = (digit) abs_ival;
        }
    }

    /* Larger numbers: loop to determine number of digits */
    else {
        t = abs_ival;
        while (t) {
            ++ndigits;
            t >>= INTOBJECT_SHIFT;
        }
        v = _intobject_new(ndigits);
        if (v != nullptr) {
            digit *p = v->ob_digit;
            _sign = sign;
            t = abs_ival;
            while (t) {
                *p++ = t & (digit) (((digit) 1 << INTOBJECT_SHIFT) - 1);
                t >>= INTOBJECT_SHIFT;
            }
        }
    }
}