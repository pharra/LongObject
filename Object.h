//
// Created by WF on 2017/9/17.
//

#ifndef FACTORIAL_OBJECT_H
#define FACTORIAL_OBJECT_H

#define INTOBJECT_SHIFT 15
#define N_INTOBJECT 100 // create the _IntObject[100]

typedef unsigned short digit;
typedef short sdigit;

struct _IntObject{
    struct _IntObject * pNext;
    digit ob_digit[1];
};
typedef struct _IntObject IntObject;

struct _IntBlock {
    struct _IntBlock *pNext;
    IntObject objects[N_INTOBJECT];
};
typedef struct _IntBlock IntBlock;


#endif //FACTORIAL_OBJECT_H
