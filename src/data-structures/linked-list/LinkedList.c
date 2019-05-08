#include <stdio.h>

#include "LinkedList.h"

static void add(const XLinkedListNode node, const XLinkedList self) {
    printf("%d\n", 1);
}


XLinkedList xNewLinkedList() {
    XLinkedList ll;
    ll.add = &add;

    return ll;
}
