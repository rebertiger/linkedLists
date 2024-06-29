#include <iostream>
#include <string.h> 
#include <stdlib.h>

#include "nonCircularSinglyLinkedList.h";

#include "circularSinglyLinkedList.h";

#include "nonCircularDoublyLinkedList.h";

#include "circularDoublyLinkedList.h";
using namespace std;

int main() {
    //non cýrcular sýngly
    cout << "non circular singly linked:" << endl;
    nonCircularSinglyLinkedList ncsl;
    ncsl.addNode("ahmet");
    ncsl.addNode("cansu");
    ncsl.printList();

    ncsl.deleteNode("ahmet");
    ncsl.printList();

    cout << (ncsl.searchList("ahmet") ? "Found" : "Not Found") << endl; 


    ncsl.deleteList();
    ncsl.printList();

    // circular sýngly
    cout << "circular singly linked:" << endl;
    circularSinglyLinkedList csl;
    csl.addNode("ahmet");
    csl.addNode("cansu");
    csl.addNode("sude");
    csl.printList();

    csl.deleteNode("cansu");
    csl.printList();

    cout << (csl.searchList("ahmet") ? "Found" : "Not Found") << endl;
    cout << (csl.searchList("cansu") ? "Found" : "Not Found") << endl;

    csl.deleteList();
    csl.printList();

    // non circular doubly
    cout << "non circular doubly linked:" << endl;
    nonCircularDoublyLinkedList ncdl;
    ncdl.addNode("ahmet");
    ncdl.addNode("cansu");
    ncdl.addNode("sude");
    ncdl.printList();

    ncdl.deleteNode("sude");
    ncdl.printList();

    cout << (ncdl.searchList("cansu") ? "Found" : "Not Found") << endl;
    cout << (ncdl.searchList("sude") ? "Found" : "Not Found") << endl;

    ncdl.deleteList();
    ncdl.printList();

    //circular dobuly linked
    cout << "circular doubly linked:" << endl;
    circularDoublyLinkedList cdl;
    cdl.addNode("ahmet");
    cdl.addNode("cansu");
    cdl.addNode("sude");
    cdl.printList();
    cdl.deleteNode("sude");
    cdl.printList();
    cout << (cdl.searchList("ahmet") ? "Found" : "Not Found") << endl; 
    cout << (cdl.searchList("sude") ? "Found" : "Not Found") << endl;
    cdl.deleteList();
    cdl.printList(); 
    return 0;
}