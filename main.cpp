#include "LinkedList.h"

int main() {
    LinkedList list;

    list.SERVER_buildCircularLinkedList(); // Step 1
    list.SERVER_printLinkedList();          // Step 2
    list.CLIENT_printLinkedList();          // Step 3

    list.SERVER_deleteCircularLinkedList(); // Step 4
    list.CLIENT_printLinkedList();           // Step 5

    return 0;
}
