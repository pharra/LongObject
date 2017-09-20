//
// Created by WF on 2017/9/17.
//

#include "LongObject.h"


int LongObject::_long_to_decimal_string_internal(LongObject *a, char *pDecimal_str) {
    LongObject *scratch;
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
    scratch->pHead = _intobject_new(size);

    /* convert array of base _PyLong_BASE digits in pin to an array of
       base INTOBJECT_DECIMAL_BASE digits in pout, following Knuth (TAOCP,
       Volume 2 (3rd edn), section 4.4, Method 1b). */
    pin = a->pHead->ob_digit;
    pout = scratch->pHead->ob_digit;
    size = 0;
    for (i = size_a; i >= 0;i--) {
        digit hi = pin[i];
        for (j = 0; j < size; j++) {
            unsigned long z = (unsigned long) pout[j] ;//<< INTOBJECT_SHIFT | hi;
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
    pDecimal_str = new char[strlen];
    pDecimal_str += strlen;
    *pDecimal_str = '\0';
    pDecimal_str --;
    for(int b = 0; b < size_a; b++){
        digit hi = a->pHead->ob_digit[i];
        while (hi > 0){
            *pDecimal_str = static_cast<char>('0' + (hi % 10));
            pDecimal_str --;
            hi = static_cast<digit>(hi / 10);
        }
    }

}

IntObject *LongObject::_intobject_new(int var) {
    if (IntBlockManager::pFree_list == nullptr) {
        IntBlockManager::pFree_list = IntBlockManager::_fill_free_list();
    }
    IntObject *pHead = IntBlockManager::pFree_list;
    while (var > 0) {
        IntBlockManager::pFree_list = IntBlockManager::pFree_list->pNext;
        if (IntBlockManager::pFree_list == nullptr) {
            IntBlockManager::pFree_list = IntBlockManager::_fill_free_list();
        }
        var--;
    }
    return pHead;
}


LongObject::~LongObject() {
    IntObject *p = IntBlockManager::pFree_list;
    while (p->pNext != nullptr) {
        p = p->pNext;
    }
    p->pNext = pHead;
    while (nSize > 0) {
        pHead = pHead->pNext;
        nSize--;
    }
    pHead = nullptr;
}


LongObject::LongObject(int ival) {
    char **a;

    IntObject *v;
    unsigned int abs_ival;
    unsigned int t;  /* unsigned so >> doesn't propagate sign bit */
    int ndigits = 0;
    int sign;
    if (ival < 0) {
        /* negate: can't write this as abs_ival = -ival since that
           invokes undefined behaviour when ival is LONG_MIN */
        abs_ival = 0U - (unsigned int) ival;
        sign = -1;
    } else {
        abs_ival = (unsigned int) ival;
        sign = ival == 0 ? 0 : 1;
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
    v = _intobject_new(ndigits);
    pHead = v;
    if (v != nullptr) {
        digit *p = v->ob_digit;
        _sign = sign;
        t = abs_ival;
        while (t) {
            *p++ = static_cast<digit>(t & INTOBJECT_MASK);
            t >>= INTOBJECT_SHIFT;
        }
    }
    //}
    _long_to_decimal_string_internal(this, pDecimal_str);
}