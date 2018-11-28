#include "LinkedListNode.cpp"

class LinkedList {
    LinkedListNode* head;
    LinkedListNode* tail;

    public: 
    void append(int val);
    void prepend(int val);
    LinkedListNode* find(int val);
};

void LinkedList::append(int val) {
    LinkedListNode* node = new LinkedListNode(val);
    if(!this->head) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->setNext(node);
        this->tail = node;
    }
}

void LinkedList::prepend(int val) {
    LinkedListNode* node = new LinkedListNode(val);

    if(!this->head) {
        this->head = node;
        this->tail = node;
    } else {
        node->setNext(this->head);
        this->head = node;
    }
}

LinkedListNode* LinkedList::find(int val) {
    LinkedListNode* current = this->head;
    while(current) {
        if(current->getValue() == val) {
            return current;
        }

        current = current->getNext();
    }

    return nullptr;
}
