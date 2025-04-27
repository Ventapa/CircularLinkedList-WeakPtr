# NodeCyclesWeakPtrs

## Lab Assignment
**Lab Title:** Node Cycles and `weak_ptrs`  

This project demonstrates the use of `std::weak_ptr` in C++ to manage a circular linked list, avoid memory leaks, and safely break node cycles.

---

## Project Structure
- `Node.h` — Definition of the `Node` structure with `weak_ptr` to the next node.
- `LinkedList.h` — Declaration of the `LinkedList` class.
- `LinkedList.cpp` — Implementation of the `LinkedList` class methods.
- `main.cpp` — Main program to demonstrate the server-client behavior.
- `LinkedList_test.cpp` — Unit tests to verify correct linked list behavior.
- `README.md` — Project overview and build instructions.

---

## Behavior Demonstrated
1. **Server** creates a circular linked list using `shared_ptr` and `weak_ptr`.
2. **Server** prints the list using `shared_ptr`.
3. **Client** prints the list using `weak_ptr`.
4. **Server** deletes the list (clearing all `shared_ptr`s).
5. **Client** detects expired `weak_ptr`s and shows safe memory cleanup.

---

## Build and Run Instructions

### Requirements
- C++11 or higher
- g++ compiler or any standard C++ compiler

---

### Compile and Run Main Program
```bash
g++ main.cpp LinkedList.cpp -o nodecycles
./nodecycles


Compile and Run Unit Tests

g++ LinkedList.cpp LinkedList_test.cpp -o linkedlist_test
./linkedlist_test

Expected Output Highlights
Before deletion: List nodes are printed successfully by both server and client.
After deletion: Client prints "Yipes! shared_ptr not available" for each node.
Node destructors are called safely after deletion, avoiding memory leaks.

Important Concepts
shared_ptr — Shared ownership of dynamic memory.
weak_ptr — Non-owning reference to break cycles and prevent memory leaks.
Circular Linked List — Nodes link back to the root node, forming a cycle.
Memory Safety — Correct use of smart pointers ensures no leaks even with cycles.

