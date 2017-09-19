#include <iostream>
#include "LongObject.h"

IntObject * IntBlockManager::pFree_list = nullptr;
IntBlock * IntBlockManager::pBlock_list = nullptr;

int main() {
    LongObject a = LongObject(1 << 15);
    std::cout << a.pHead->ob_digit[0] << std::endl;
    return 0;
}