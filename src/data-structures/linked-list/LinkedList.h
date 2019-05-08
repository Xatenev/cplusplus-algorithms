typedef struct {

} XLinkedListNode;

typedef struct XLinkedList {
    void (*add)(XLinkedListNode node, struct XLinkedList self);
} XLinkedList;

XLinkedList xNewLinkedList();
