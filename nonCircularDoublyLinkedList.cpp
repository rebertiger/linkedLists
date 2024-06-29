#include "nonCircularDoublyLinkedList.h";
#include <iostream>
using namespace std;

nonCircularDoublyLinkedList::nonCircularDoublyLinkedList() : head(nullptr) {}

bool nonCircularDoublyLinkedList::addNode(string n) {
    if (searchList(n)) return false;

    DoublyNode* newNode = new DoublyNode(n);
    if (!head || head->info > n) {
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
        return true;
    }

    DoublyNode* current = head;
    while (current->next && current->next->info < n) {
        current = current->next;
    }
    newNode->next = current->next;
    if (current->next) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    return true;
}

bool nonCircularDoublyLinkedList::deleteNode(string n) {
    if (!head) return false;

    if (head->info == n) {
        DoublyNode* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
        return true;
    }

    DoublyNode* current = head;
    while (current->next && current->next->info != n) {
        current = current->next;
    }

    if (current->next) {
        DoublyNode* temp = current->next;
        current->next = temp->next;
        if (temp->next) {
            temp->next->prev = current;
        }
        delete temp;
        return true;
    }

    return false;
}

void nonCircularDoublyLinkedList::printList() {
    DoublyNode* current = head;
    while (current) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

bool nonCircularDoublyLinkedList::searchList(string n) {
    DoublyNode* current = head;
    while (current) {
        if (current->info == n) return true;
        current = current->next;
    }
    return false;
}

void nonCircularDoublyLinkedList::deleteList() {
    DoublyNode* current = head;
    while (current) {
        DoublyNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

nonCircularDoublyLinkedList::~nonCircularDoublyLinkedList() {
    deleteList();
}