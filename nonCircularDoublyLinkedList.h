#ifndef NONCIRCULARDOUBLYLINKEDLIST_H
#define NONCIRCULARDOUBLYLINKEDLIST_H

#include <string>
using namespace std;

struct DoublyNode {
    string info;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode() : next(nullptr), prev(nullptr) {}
    DoublyNode(string val) : info(val), next(nullptr), prev(nullptr) {}
};

class nonCircularDoublyLinkedList {
private:
    DoublyNode* head;

public:
    nonCircularDoublyLinkedList();
    bool addNode(string n);
    bool deleteNode(string n);
    void printList();
    bool searchList(string n);
    void deleteList();
    ~nonCircularDoublyLinkedList();
};

#endif // NONCIRCULARDOUBLYLINKEDLIST_H