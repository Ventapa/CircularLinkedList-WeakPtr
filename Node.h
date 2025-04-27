#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct Node {
    string name;
    weak_ptr<Node> next;  // NOW using weak_ptr to avoid cycle

    Node(string name) : name{name} {}

    ~Node() {
        cout << "Node [" << name << "] destructor" << endl;
    }
};

#endif // NODE_H
