#include "circularDoublyLinkedList.h";
#include <iostream>
using namespace std;

circularDoublyLinkedList::circularDoublyLinkedList() : head(nullptr) {}

bool circularDoublyLinkedList::addNode(string n) {
    if (searchList(n)) {
        return false;
    }
    CircularDoublyNode* newNode = new CircularDoublyNode(n);
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return true;
    }

    if (head->info > n) {
        CircularDoublyNode* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
        return true;
    }

    CircularDoublyNode* current = head;
    while (current->next != head && current->next->info < n) {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    return true;
}

bool circularDoublyLinkedList::deleteNode(string n) {
    if (!head) {
        return false;
    }
    if (head->info == n) {
        if (head->next == head) {
            delete head;
            head = nullptr;
            return true;
        }
        else {
            CircularDoublyNode* tail = head->prev;
            CircularDoublyNode* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
            return true;
        }
    }

    CircularDoublyNode* current = head;
    while (current->next != head && current->next->info != n) {
        current = current->next;
    }

    if (current->next != head) {
        CircularDoublyNode* temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;
        delete temp;
        return true;
    }

    return false;
}

void circularDoublyLinkedList::printList() {
    if (!head) {
        return;
    }
    CircularDoublyNode* current = head;
    do {
        cout << current->info << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

bool circularDoublyLinkedList::searchList(string n) {
    if (!head) return false;

    CircularDoublyNode* current = head;
    do {
        if (current->info == n) return true;
        current = current->next;
    } while (current != head);
    return false;
}

void circularDoublyLinkedList::deleteList() {
    if (!head) {
        return;
    }
    CircularDoublyNode* current = head;
    do {
        CircularDoublyNode* temp = current;
        current = current->next;
        delete temp;
    } while (current != head);

    head = nullptr;
}

circularDoublyLinkedList::~circularDoublyLinkedList() {
    deleteList();
}