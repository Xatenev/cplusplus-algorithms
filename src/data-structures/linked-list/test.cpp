#include <iostream>

#include "LinkedList.cpp"

int main() {

    LinkedList* list = new LinkedList();

    for(int i = 0; i < 50; i++) {
        list->append(i);
    }

    std::cout << list->find(7)->getValue();


}
