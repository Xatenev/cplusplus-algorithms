class LinkedList {
    LinkedListNode* head,
        LinkedListNode* tail;

    public: 
    void append(int val);
    void prepend(int val);
};

LinkedList::append(int val) {
    LinkedListNode* node = new LinkedListNode(value);
    if(!this->head) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->next = node;
        this->tail = node;
    }
}

LinkedList::prepend(int val) {
    LinkedListNode* node = new LinkedListNode(value);

    if(!this->head) {
        this->head = node;
        this->tail = node;
    } else {
        node->next = this->head;
        self->head = node;
    }
}
