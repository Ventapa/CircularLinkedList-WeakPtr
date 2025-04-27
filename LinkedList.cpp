#include "LinkedList.h"

LinkedList::LinkedList() : root(nullptr) {}

LinkedList::~LinkedList() {}

void LinkedList::SERVER_buildCircularLinkedList() {
    vector<string> names = { "zero", "one", "two", "three", "four", "five" };
    int numberOfNodes = names.size();

    shared_nodes.reserve(numberOfNodes);

    // Create all nodes first
    for (const auto& name : names) {
        shared_nodes.push_back(make_shared<Node>(name));
    }

    // Link them in a circular way
    for (int i = 0; i < numberOfNodes; i++) {
        shared_nodes[i]->next = shared_nodes[(i + 1) % numberOfNodes];
    }

    // Prepare weak_refs for CLIENT
    for (auto& node : shared_nodes) {
        weak_refs.push_back(node);
    }

    root = shared_nodes[0];
}

void LinkedList::SERVER_printLinkedList() {
    cout << "Server (Step 2):" << endl;
    if (!root) return;
    shared_ptr<Node> current = root;
    do {
        auto next_shared = current->next.lock();
        cout << "[" << current->name << "] : use_count: " << current.use_count()
             << " address: " << current.get()
             << " next (from weak_ptr): " << (next_shared ? next_shared.get() : nullptr)
             << endl;
        current = next_shared;
    } while (current && current != root);
}

void LinkedList::SERVER_deleteCircularLinkedList() {
    cout << "Server is deleting the shared_ptrs (Step 4)" << endl;
    shared_nodes.clear(); // Clear all shared_ptrs!
    root = nullptr;
}

void LinkedList::CLIENT_printLinkedList() {
    cout << "Client (Step 3 or 5):" << endl;
    for (auto& weak_node : weak_refs) {
        shared_ptr<Node> node = weak_node.lock();
        if (node) {
            auto next_node = node->next.lock();
            cout << "[" << node->name << "] : use_count: " << node.use_count()
                 << " address: " << node.get()
                 << " next (from weak_ptr): "
                 << (next_node ? next_node.get() : 0) << endl;
        } else {
            cout << "Yipes! shared_ptr not available" << endl;
        }
    }
}
