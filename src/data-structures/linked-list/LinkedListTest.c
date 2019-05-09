#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"

int main() {
    XLinkedList linkedList;
    xInitLinkedList(&linkedList);

    /* Test add and contains */
    linkedList.add(&linkedList, 8);
    bool result1 = linkedList.contains(&linkedList, 8);
    bool result2 = linkedList.contains(&linkedList, 3);

    assert(result1 == true);
    assert(result2 == false);

    /* Test prepend */
    linkedList.prepend(&linkedList, 3);
    assert(linkedList.head->value == 3);

    /* Test remove */
    linkedList.remove(&linkedList, 3);

    assert(linkedList.head->value != 3);

    linkedList.destroy(&linkedList);

    return EXIT_SUCCESS;
}

