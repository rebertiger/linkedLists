#ifndef NONCIRCULARSINGLYLINKEDLIST_H
#define NONCIRCULARSINGLYLINKEDLIST_H

#include <string>
using namespace std;

struct SinglyNode {
    string info;
    SinglyNode* next;

    SinglyNode() : next(nullptr) {}
    SinglyNode(string val) : info(val), next(nullptr) {}
};

class nonCircularSinglyLinkedList {
private:
    SinglyNode* head;

public:
    nonCircularSinglyLinkedList();
    bool addNode(string n);
    bool deleteNode(string n);
    void printList();
    bool searchList(string n);
    void deleteList();
    ~nonCircularSinglyLinkedList();
};

#endif // NONCIRCULARSINGLYLINKEDLIST_H