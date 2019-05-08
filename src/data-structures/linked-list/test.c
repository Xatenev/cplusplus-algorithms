#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"

int main() {
    XLinkedList linkedList;
    
    xInitLinkedList(&linkedList);

    linkedList.add(&linkedList, 8);

    bool result1 = linkedList.contains(&linkedList, 8);
    bool result2 = linkedList.contains(&linkedList, 3);

    assert(result1 == true);
    assert(result2 == false);
    
    return EXIT_SUCCESS;
}

