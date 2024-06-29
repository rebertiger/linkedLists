#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include <string>
using namespace std;

struct CircularDoublyNode {
    string info;
    CircularDoublyNode* next;
    CircularDoublyNode* prev;

    CircularDoublyNode() : next(nullptr), prev(nullptr) {}
    CircularDoublyNode(string val) : info(val), next(nullptr), prev(nullptr) {}
};

class circularDoublyLinkedList {
private:
    CircularDoublyNode* head;

public:
    circularDoublyLinkedList();
    bool addNode(string n);
    bool deleteNode(string n);
    void printList();
    bool searchList(string n);
    void deleteList();
    ~circularDoublyLinkedList();
};

#endif // CIRCULARDOUBLYLINKEDLIST_H