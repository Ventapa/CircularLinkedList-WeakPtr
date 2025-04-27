#include "LinkedList.h"
#include <cassert>
#include <iostream>

void test_build_and_traverse() {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    
    std::cout << "\nRunning SERVER_printLinkedList()...\n";
    list.SERVER_printLinkedList();

    std::cout << "\nRunning CLIENT_printLinkedList()...\n";
    list.CLIENT_printLinkedList();
}

void test_after_deletion() {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    list.SERVER_deleteCircularLinkedList();

    std::cout << "\nRunning CLIENT_printLinkedList() after deletion...\n";
    list.CLIENT_printLinkedList();
}

int main() {
    std::cout << "=== Unit Test: Build and Traverse ===\n";
    test_build_and_traverse();

    std::cout << "\n=== Unit Test: After Deletion ===\n";
    test_after_deletion();

    std::cout << "\nAll unit tests completed.\n";

    return 0;
}
