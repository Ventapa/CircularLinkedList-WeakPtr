#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <vector>

class LinkedList {
private:
    vector<shared_ptr<Node>> shared_nodes; // SERVER side shared_ptrs
    vector<weak_ptr<Node>> weak_refs;       // CLIENT side weak_ptrs
    shared_ptr<Node> root;

public:
    LinkedList();
    ~LinkedList();

    void SERVER_buildCircularLinkedList();
    void SERVER_printLinkedList();
    void SERVER_deleteCircularLinkedList();
    void CLIENT_printLinkedList();
};

#endif // LINKEDLIST_H
