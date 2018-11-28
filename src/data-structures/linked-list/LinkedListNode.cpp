class LinkedListNode {
    int value;
    LinkedListNode* next;

    public:
    void setNext(LinkedListNode* node);
    LinkedListNode* getNext();
    LinkedListNode(int value);
    int getValue();
};

LinkedListNode::LinkedListNode(int value) {
    this->value = value;
}

void LinkedListNode::setNext(LinkedListNode* node) {
    this->next = node;
}

LinkedListNode* LinkedListNode::getNext() {
    return this->next;
}

int LinkedListNode::getValue() {
    return this->value;
}
