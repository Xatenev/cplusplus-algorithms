#include <stdbool.h>
#include <assert.h>

typedef struct XLinkedListNode XLinkedListNode;
typedef struct XLinkedList XLinkedList;

struct XLinkedListNode {
    int value;
    XLinkedListNode* next;
};

struct XLinkedList {
    XLinkedListNode* head;
    XLinkedListNode* tail;

    void (*add)(XLinkedList* self, int value);
    void (*prepend)(XLinkedList* self, int value);
    bool (*contains)(XLinkedList* self, int value);
    void (*remove)(XLinkedList* self, XLinkedListNode node);
    void (*reverse)(XLinkedList* self, XLinkedListNode node);
    void (*destroy)(XLinkedList* self);

};

void xInitLinkedList(XLinkedList* linkedList);
