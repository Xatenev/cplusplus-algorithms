#include <stdlib.h>
#include <stdio.h>

#include "DoublyLinkedList.h"

int main() {
    XDLinkedList *linkedList = xInitDoublyLinkedList();

    /* Test add and contains */
    linkedList->add(linkedList, 8);
    bool result1 = linkedList->contains(linkedList, 8);
    bool result2 = linkedList->contains(linkedList, 3);

    assert(result1 == true);
    assert(result2 == false);

    /* Test prepend */
    linkedList->prepend(linkedList, 3);
    assert(linkedList->head->value == 3);

    /* Test remove */
    linkedList->clear(linkedList);
    linkedList->add(linkedList, 1);
    linkedList->add(linkedList, 2);
    linkedList->add(linkedList, 3);
    linkedList->add(linkedList, 4);
    linkedList->remove(linkedList, 1);

    assert(linkedList->head->value != 1);


    /* Test reverse */
    linkedList->clear(linkedList);
    linkedList->add(linkedList, 1);
    linkedList->add(linkedList, 2);
    linkedList->add(linkedList, 3);

    assert(linkedList->head->value == 1);

    linkedList->reverse(linkedList);
    assert(linkedList->head->value == 3);

    /* Test destroy */
    linkedList->destroy(&linkedList);

    assert(linkedList == NULL);


    return EXIT_SUCCESS;
}

