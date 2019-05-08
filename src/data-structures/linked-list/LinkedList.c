#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

static void _add(XLinkedList* self, int value) {
    XLinkedListNode node;
    node.value = value;
    node.next = NULL;

    if(self->head == NULL) {
        self->head = &node;
        self->tail = &node;
    } else {
        self->tail->next = &node;
        self->tail = &node;
    }
}

static void _prepend(XLinkedList* self, XLinkedListNode value) {
}

static bool _contains(XLinkedList* self, int value) {
    XLinkedListNode* n = self->head;
    int i = 1;
    while(n != NULL && n->value != value) {
        printf("%p\n",n->next);
        n = n->next;
        i++;
        if(i==5){
            exit(1);
        }
    }

    return n != NULL;
}

static void _remove(XLinkedList* self, XLinkedListNode node) {
    printf("%d\n", 1);
}

static void _traverse(XLinkedList* self, XLinkedListNode node) {
    printf("%d\n", 1);
}

static void _traverseReverse(XLinkedList* self, XLinkedListNode node) {
    printf("%d\n", 1);
}



void xInitLinkedList(XLinkedList* linkedList) {
    // Setup function pointers
    linkedList->add = &_add;
    linkedList->contains = &_contains;

    // Setup sentinel values
    linkedList->head = NULL;
    linkedList->tail = NULL;
}
