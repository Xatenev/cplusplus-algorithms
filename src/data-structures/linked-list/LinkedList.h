#include <stdbool.h>
#include <assert.h>

typedef struct XLinkedListNode {
    int value;
    struct XLinkedListNode* next;
} XLinkedListNode;

typedef struct XLinkedList {
    XLinkedListNode* head;
    XLinkedListNode* tail;

    void (*add)(struct XLinkedList* self, int value);
    void (*prepend)(struct XLinkedList* self, XLinkedListNode node);
    bool (*contains)(struct XLinkedList* self, int value);
    void (*remove)(struct XLinkedList* self, XLinkedListNode node);
    void (*traverse)(struct XLinkedList* self, XLinkedListNode node);
    void (*traverseReverse)(struct XLinkedList* self, XLinkedListNode node);
    void (*destroy)(struct XLinkedList* self);

} XLinkedList;

void xInitLinkedList(XLinkedList* linkedList);
