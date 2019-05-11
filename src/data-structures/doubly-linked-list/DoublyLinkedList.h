#include <stdbool.h>
#include <assert.h>

typedef struct XDLinkedListNode XDLinkedListNode;
typedef struct XDLinkedList XDLinkedList;

struct XDLinkedListNode {
    int value;
    XDLinkedListNode *next;
    XDLinkedListNode *prev;
};

struct XDLinkedList {
    XDLinkedListNode *head;
    XDLinkedListNode *tail;

    void (*add)(XDLinkedList *self, int value);

    void (*prepend)(XDLinkedList *self, int value);

    bool (*contains)(XDLinkedList *self, int value);

    bool (*remove)(XDLinkedList *self, int value);

    void (*reverse)(XDLinkedList *self);

    void (*destroy)(XDLinkedList **self);

    void (*clear)(XDLinkedList *self);

};

XDLinkedList *xInitDoublyLinkedList();
