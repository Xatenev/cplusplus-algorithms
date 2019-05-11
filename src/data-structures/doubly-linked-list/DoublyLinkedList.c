#include <stdio.h>
#include <stdlib.h>

#include "DoublyLinkedList.h"

static void _add(XDLinkedList *self, int value) {
    XDLinkedListNode *node = malloc(sizeof *node);
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    if (self->head == NULL) {
        self->head = node;
        self->tail = node;
    } else {
        node->prev = self->tail;
        self->tail->next = node;
        self->tail = node;
    }
}

static void _prepend(XDLinkedList *self, int value) {
    XDLinkedListNode *node = malloc(sizeof *node);
    node->value = value;
    node->next = self->head;
    node->prev = NULL;

    self->head = node;

    if (self->tail == NULL) {
        self->tail = node;
    }
}

static bool _contains(XDLinkedList *self, int value) {
    XDLinkedListNode *n = self->head;
    while (n != NULL && n->value != value) {
        n = n->next;
    }

    return n != NULL;
}

static bool _remove(XDLinkedList *self, int value) {
    XDLinkedListNode **head = &self->head;
    XDLinkedListNode **tail = &self->tail;

    if (*head == NULL || *tail == NULL) { // List is still empty
        return false;
    }

    // Value found on head, constant lookup time
    if ((*head)->value == value) {
        if (*head == *tail) { // Only one entry, clear head and tail
            free(*head);
            *head = NULL;
            *tail = NULL;
        } else { // Entry is at head, multiple entries though
            XDLinkedListNode *tmp = (*head)->next;
            free(*head);

            tmp->prev = NULL; // We just removed the previous node
            *head = tmp;
        }

        return true;
    }

    // (n) lookup time
    XDLinkedListNode *tmp = (*head);
    while (tmp->next != NULL && tmp->next->value != value) {
        tmp = tmp->next;
    }

    if (tmp->next != NULL) {
        if (tmp->next == *tail) {
            *tail = tmp;
        }

        XDLinkedListNode *tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        free(tmp2);

        tmp->next->prev = tmp;

        return true;
    }

    return false;
}

static void _reverse(XDLinkedList *self) {
    XDLinkedListNode *iteratorNode = self->head;

    while (iteratorNode != NULL) {
        XDLinkedListNode *tmp = iteratorNode->prev;
        iteratorNode->prev = iteratorNode->next;
        iteratorNode->next = tmp;

        iteratorNode = iteratorNode->prev;
    }

    XDLinkedListNode *tmp = self->head;
    self->head = self->tail;
    self->tail = tmp;
}

static void _clear(XDLinkedList *self) {
    if (self->head == NULL || self->tail == NULL) { // List is still empty
        return;
    }

    XDLinkedListNode *tmp;
    XDLinkedListNode *head = self->head;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    self->head = self->tail = NULL;
}

static void _destroy(XDLinkedList **self) {
    XDLinkedListNode *tmp;
    XDLinkedListNode *head = (*self)->head;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    (*self)->head = (*self)->tail = NULL;

    free(*self);

    *self = NULL;
}


XDLinkedList *xInitDoublyLinkedList() {
    XDLinkedList *linkedList = malloc(sizeof *linkedList);

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
