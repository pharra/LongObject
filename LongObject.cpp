//
// Created by WF on 2017/9/17.
//

#include "LongObject.h"


char * LongObject::_long_to_decimal_string_internal(LongObject *a) {
    //PyObject *str = NULL;
    int size, strlen, size_a, i, j;
    digit *pout, *pin, rem, tenpow;
    int negative;
    int d;

    size_a = a->nSize;
    negative = a->_sign < 0 ? 1 : 0;
    /* quick and dirty upper bound for the number of digits
       required to express a in base INTOBJECT_DECIMAL_BASE:

         #digits = 1 + floor(log2(a) / log2(INTOBJECT_DECIMAL_BASE))

       But log2(a) < size_a * INTOBJECT_SHIFT, and
       log2(INTOBJECT_DECIMAL_BASE) = log2(10) * INTOBJECT_DECIMAL_SHIFT
                                  > 3.3 * INTOBJECT_DECIMAL_SHIFT

         size_a * INTOBJECT_SHIFT / (3.3 * INTOBJECT_DECIMAL_SHIFT) =
             size_a + size_a / d < size_a + size_a / floor(d),
       where d = (3.3 * INTOBJECT_DECIMAL_SHIFT) /
                 (INTOBJECT_SHIFT - 3.3 * INTOBJECT_DECIMAL_SHIFT)
    */
    d = (33 * INTOBJECT_DECIMAL_SHIFT) /
        (10 * INTOBJECT_SHIFT - 33 * INTOBJECT_DECIMAL_SHIFT);
    size = 1 + size_a + size_a / d;
    IntObject *scratch = _int_object_new(size);

    /* convert array of base _PyLong_BASE digits in pin to an array of
       base INTOBJECT_DECIMAL_BASE digits in pout, following Knuth (TAOCP,
       Volume 2 (3rd edn), section 4.4, Method 1b). */
    pin = a->pHead->ob_digit;
    pout = scratch->ob_digit;
    size = 0;
    for (i = size_a; --i >= 0;) {
        digit hi = pin[i];
        for (j = 0; j < size; j++) {
            unsigned long z = (unsigned long) pout[j] << INTOBJECT_SHIFT | hi;
            hi = (digit) (z / INTOBJECT_DECIMAL_BASE);
            pout[j] = (digit) (z - (unsigned long) hi *
                                   INTOBJECT_DECIMAL_BASE);
        }
        while (hi) {
            pout[size++] = hi % INTOBJECT_DECIMAL_BASE;
            hi /= INTOBJECT_DECIMAL_BASE;
        }
    }
    /* pout should have at least one digit, so that the case when a = 0
       works correctly */
    if (size == 0)
        pout[size++] = 0;

    /* calculate exact length of output string, and allocate */
    strlen = negative + 1 + (size - 1) * INTOBJECT_DECIMAL_SHIFT;
    tenpow = 10;
    rem = pout[size - 1];
    while (rem >= tenpow) {
        tenpow *= 10;
        strlen++;
    }
    a->pDecimal_str = new char[strlen + 1];
    a->pDecimal_str += strlen;
    *a->pDecimal_str = '\0';
    a->pDecimal_str--;
    for(int b = 0;b < size;b ++){
        digit hi = pout[b];
        if(hi == 0){
            for(int c = 0; c < 4; c++){
                *a->pDecimal_str = '0';
                a->pDecimal_str--;
            }
        }
        while (hi){
            *a->pDecimal_str = static_cast<char>('0' + hi % 10);
            hi /= 10;
            a->pDecimal_str--;
        }
    }
    if(a->_sign < 0 ){
        *a->pDecimal_str = '-';
        a->pDecimal_str--;
    }
    a->pDecimal_str++;
    delete [] scratch;
    return a->pDecimal_str;
}

IntObject *LongObject::_int_object_new(int var) {
    /*if (IntBlockManager::pFree_list == nullptr) {
        IntBlockManager::pFree_list = IntBlockManager::_fill_free_list();
    }
    IntObject *pHead = IntBlockManager::pFree_list;
    while (var > 0) {
        IntBlockManager::pFree_list = IntBlockManager::pFree_list->pNext;
        if (IntBlockManager::pFree_list == nullptr) {
            IntBlockManager::pFree_list = IntBlockManager::_fill_free_list();
        }
        var--;
    }*/
    IntObject * pHead = new IntObject[var];
    IntObject * pV = pHead;
    while (var > 1){
        pV->pNext = pV++;
        var--;
    }
    pV ->pNext = nullptr;
    return pHead;
}


LongObject::~LongObject() {
    /*IntObject *p = IntBlockManager::pFree_list;
    while (p->pNext != nullptr) {
        p = p->pNext;
    }
    p->pNext = pHead;
    while (nSize > 0) {
        pHead = pHead->pNext;
        nSize--;
    }
    pHead = nullptr;*/
    delete []pHead;
    pHead = nullptr;
    delete []pDecimal_str;
    pDecimal_str = nullptr;
}


LongObject::LongObject(int ival) {
    IntObject *v;
    unsigned int abs_ival;
    unsigned int t;  /* unsigned so >> doesn't propagate sign bit */
    int ndigits = 0;
    if (ival < 0) {
        /* negate: can't write this as abs_ival = -ival since that
           invokes undefined behaviour when ival is LONG_MIN */
        abs_ival = 0U - (unsigned int) ival;
        _sign = -1;
    } else {
        abs_ival = (unsigned int) ival;
        _sign = ival == 0 ? 0 : 1;
    }

    /* Fast path for single-digit ints */
    /* if (!(abs_ival >> INTOBJECT_SHIFT)) {
         v = _intobject_new(1);
         if(v){
             _sign = sign;
             v->ob_digit[0] = (digit) abs_ival;
         }
     }*/

    /* Larger numbers: loop to determine number of digits */
    //else {
    t = abs_ival;
    while (t) {
        ++ndigits;
        t >>= INTOBJECT_SHIFT;
    }
    nSize = ndigits;
    v = _int_object_new(ndigits);
    pHead = v;
    if (v != nullptr) {
        digit *p = v->ob_digit;
        t = abs_ival;
        while (t) {
            *p++ = static_cast<digit>(t & INTOBJECT_MASK);
            t >>= INTOBJECT_SHIFT;
        }
    }
    //}
    LongObject::_long_to_decimal_string_internal(this);
}

ostream &operator<<(ostream &ostream1, LongObject &a) {
    ostream1 << a.pDecimal_str;
    return ostream1;
}

