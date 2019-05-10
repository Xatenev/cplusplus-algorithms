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
    bool (*remove)(XLinkedList* self, int value);
    void (*reverse)(XLinkedList* self);
    void (*destroy)(XLinkedList* self);
    void (*clear)(XLinkedList* self);

};

XLinkedList* xInitLinkedList();
