#include <iostream>

#include "LinkedList.cpp"

int main() {

    LinkedList* list = new LinkedList();

    for(int i = 0; i < 50; i++) {
        list->append(i);
    }

    std::cout << list->find(7)->getValue() << std::endl;

    std::cout << list->contains(10) << std::endl;
    std::cout << list->contains(52) << std::endl;
    


}
