#include "circularSinglyLinkedList.h";
#include <iostream>
using namespace std;

circularSinglyLinkedList::circularSinglyLinkedList() : head(nullptr) {}

bool circularSinglyLinkedList::addNode(string n) {
    if (searchList(n)) {
        return false;
    }
    CircularSinglyNode* newNode = new CircularSinglyNode(n);
    if (!head) {
        head = newNode;
        head->next = head;
        return true;
    }

    if (head->info > n) {
        CircularSinglyNode* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
        return true;
    }

    CircularSinglyNode* current = head;
    while (current->next != head && current->next->info < n) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

bool circularSinglyLinkedList::deleteNode(string n) {
    if (!head) return false;

    if (head->info == n) {
        if (head->next == head) {
            delete head;
            head = nullptr;
            return true;
        }
        else {
            CircularSinglyNode* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            CircularSinglyNode* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return true;
        }
    }

    CircularSinglyNode* current = head;
    while (current->next != head && current->next->info != n) {
        current = current->next;
    }

    if (current->next !=  head) {
        CircularSinglyNode* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }

    return false;
}

void circularSinglyLinkedList::printList() {
    if (!head) return;

    CircularSinglyNode* current = head;
    do {
        cout << current->info << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

bool circularSinglyLinkedList::searchList(string n) {
    if (!head) return false;

    CircularSinglyNode* current = head;
    do {
        if (current->info == n) return true;
        current = current->next;
    } while (current != head);
    return false;
}

void circularSinglyLinkedList::deleteList() {
    if (!head) return;

    CircularSinglyNode* current = head;
    do {
        CircularSinglyNode* temp = current;
        current = current->next;
        delete temp;
    } while (current != head);

    head = nullptr;
}

circularSinglyLinkedList::~circularSinglyLinkedList() {
    deleteList();
}