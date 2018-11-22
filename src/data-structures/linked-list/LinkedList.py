import LinkedListNode

class LinkedList:
    head = None
    tail = None

    def append(self, value):
        node = LinkedListNode.LinkedListNode(value)

        if not self.head:
            self.head = node
            self.tail = node
        else: 
            self.tail.next = node
            self.tail = node

    def prepend(self, value):
        node = LinkedListNode.LinkedListNode(value)
        
        if not self.head:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node
