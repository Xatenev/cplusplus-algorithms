#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

static void _add(XLinkedList *self, int value) {
    XLinkedListNode *node = malloc(sizeof *node);
    node->value = value;
    node->next = NULL;

    if (self->head == NULL) {
        self->head = node;
        self->tail = node;
    } else {
        self->tail->next = node;
        self->tail = node;
    }
}

static void _prepend(XLinkedList *self, int value) {
    XLinkedListNode *node = malloc(sizeof *node);
    node->value = value;
    node->next = self->head;

    self->head = node;

    if (self->tail == NULL) {
        self->tail = node;
    }
}

static bool _contains(XLinkedList *self, int value) {
    XLinkedListNode *n = self->head;
    while (n != NULL && n->value != value) {
        n = n->next;
    }

    return n != NULL;
}

static bool _remove(XLinkedList *self, int value) {
    XLinkedListNode **head = &self->head;
    XLinkedListNode **tail = &self->tail;


    if (*head == NULL || *tail == NULL) { // List is still empty
        return false;
    }

    // Value found
    if ((*head)->value == value) {
        if (*head == *tail) { // Only one entry, clear head and tail
            *head = NULL;
            *tail = NULL;
        } else { // Entry is at head
            *head = (*head)->next;
        }

        return true;
    }

    XLinkedListNode *tmp = (*head);
    while (tmp->next != NULL && tmp->next->value != value) {
        tmp = tmp->next;
    }

    if ((*head)->next != NULL) {
        if ((*head)->next == *tail) {
            *tail = *head;
        }

        (*head)->next = (*head)->next->next;

        return true;
    }

    return false;
}

static void _reverse(XLinkedList *self) {
    XLinkedListNode *iteratorNode = self->head;
    XLinkedListNode *previousNode = NULL;
    XLinkedListNode *nextNode = NULL;

    while (iteratorNode != NULL) {
        nextNode = iteratorNode->next;


        if(previousNode) { // Not head(first)
            iteratorNode->next = previousNode;
        }

        if(iteratorNode->next == NULL) {
            break;
        }

        if(self->head == iteratorNode) {
            iteratorNode->next = NULL;
        }

        previousNode = iteratorNode;
        iteratorNode = nextNode;

    }

    XLinkedListNode* tmp = self->head;
    self->head = self->tail;
    self->tail = tmp;
}

static void _clear(XLinkedList* self) {
    if (self->head == NULL || self->tail == NULL) { // List is still empty
        return;
    }

    XLinkedListNode *tmp;
    XLinkedListNode *head = self->head;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    self->head = self->tail = NULL;
}

static void _destroy(XLinkedList **self) {
    XLinkedListNode *tmp;
    XLinkedListNode *head = (*self)->head;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    (*self)->head = (*self)->tail = NULL;

    free(*self);

    *self = NULL;
}


XLinkedList* xInitLinkedList() {
    XLinkedList* linkedList = malloc(sizeof *linkedList);

    // Setup function pointers
    linkedList->add = &_add;
    linkedList->contains = &_contains;
    linkedList->prepend = &_prepend;
    linkedList->remove = &_remove;
    linkedList->destroy = &_destroy;
    linkedList->reverse = &_reverse;
    linkedList->clear = &_clear;

    // Setup sentinel values
    linkedList->head = NULL;
    linkedList->tail = NULL;

    return linkedList;
}
