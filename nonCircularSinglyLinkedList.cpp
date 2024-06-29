#include "nonCircularSinglyLinkedList.h";
#include <iostream>
using namespace std;

nonCircularSinglyLinkedList::nonCircularSinglyLinkedList() : head(nullptr) {}

bool nonCircularSinglyLinkedList::addNode(string n) {
    if (searchList(n)) return false;

    SinglyNode* newNode = new SinglyNode(n);
    if (!head || head->info > n) {
        newNode->next = head;
        head = newNode;
        return true;
    }

    SinglyNode* current = head;
    while (current->next &&  current->next->info < n) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

bool nonCircularSinglyLinkedList::deleteNode(string n) {
    if (!head) return false;

    if (head->info == n) {
        SinglyNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    SinglyNode* current = head;
    while (current->next && current->next->info != n) {
        current = current->next;
    }

    if (current->next) {
        SinglyNode* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }

    return false;
}

void nonCircularSinglyLinkedList::printList() {
    SinglyNode* current = head;
    while (current) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

bool nonCircularSinglyLinkedList::searchList(string n) {
    SinglyNode* current = head;
    while (current ) {
        if (current->info == n) return true;
        current = current->next;
    }
    return false;
}

void nonCircularSinglyLinkedList::deleteList() {
    SinglyNode* current = head;
    while (current) {
        SinglyNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

nonCircularSinglyLinkedList::~nonCircularSinglyLinkedList() {
    deleteList();
}