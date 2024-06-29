#ifndef CIRCULARSINGLYLINKEDLIST_H
#define CIRCULARSINGLYLINKEDLIST_H

#include <string>
using namespace std;

struct CircularSinglyNode {
    string info;
    CircularSinglyNode* next;

    CircularSinglyNode() : next(nullptr) {}
    CircularSinglyNode(string val) : info(val), next(nullptr) {}
};

class circularSinglyLinkedList {
private:
    CircularSinglyNode* head;

public:
    circularSinglyLinkedList();
    bool addNode(string n);
    bool deleteNode(string n);
    void printList();
    bool searchList(string n);
    void deleteList();
    ~circularSinglyLinkedList();
};

#endif // CIRCULARSINGLYLINKEDLIST_H