//
// Created by WF on 2017/9/17.
// The class which manage the memory for IntBlockManager and IntObject.
//

#ifndef FACTORIAL_IntBlockManager_H
#define FACTORIAL_IntBlockManager_H
#include "Object.h"

class IntBlockManager {
public:
    static IntObject *_fill_free_list();
    static IntBlock *pBlock_list;
    static IntObject *pFree_list;
    IntBlockManager();
    ~IntBlockManager();
    friend class LongObject;
};


#endif //FACTORIAL_IntBlockManager_H
