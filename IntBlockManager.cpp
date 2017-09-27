//
// Created by WF on 2017/9/17.
//

#include "IntBlockManager.h"
/*


IntObject * IntBlockManager::_fill_free_list()
{
    IntObject *p, *q;
    IntBlock *r;
 //申请大小为sizeof（Block）的内存空间，并链接到已有的block list中

    r = pBlock_list;
    while (r != nullptr){
        r = r->pNext;
    }
    r = new IntBlock;
    r->pNext = nullptr;
 //将IntBlock中的IntObject数组——objects转变成单向链表

    p = &(r->objects[0]);
    q = p + N_INTOBJECT;
    (q-1)->pNext = nullptr;
    while (--q > p){
        (q-1)->pNext = q;
    }
    return p;
}

IntBlockManager::IntBlockManager(){

}
IntBlockManager::~IntBlockManager(){
    IntBlock *p = pBlock_list;
    while (p != nullptr){
        p = p->pNext;
        delete pBlock_list;
        pBlock_list = p;
    }
}
*/
