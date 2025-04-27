# CircularLinkedList-WeakPtr
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
- `README.md` — Project overview and build instructions.

---

## Behavior Demonstrated
1. **Server** creates a circular linked list using `shared_ptr` and `weak_ptr`.
2. **Server** prints the list using `shared_ptr`.
3. **Client** prints the list using `weak_ptr`.
4. **Server** deletes the list (clearing all `shared_ptr`s).
5. **Client** detects expired `weak_ptr`s and shows safe memory cleanup.

---

## Build Instructions

### Requirements
- C++11 or higher
- g++ compiler or any standard C++ compiler

### Compile
```bash
g++ main.cpp LinkedList.cpp -o nodecycles
Run


./nodecycles


Expected Output Highlights
Before deletion: List nodes printed successfully.

After deletion: Client prints "Yipes! shared_ptr not available" for each node.

Node destructors called safely (no memory leaks).

Important Concepts
shared_ptr — Shared ownership of dynamic memory.

weak_ptr — Non-owning reference to break cycles and prevent memory leaks.

Circular Linked List — Nodes link back to the root, forming a cycle.
