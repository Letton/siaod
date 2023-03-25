#include "List.h"
#include <iostream>

void List::addNode(int key) {
    Node *node = new Node;
    node->key = key;
    node->next = nullptr;
    if(head == nullptr) {
        head = node;
        return;
    }
    Node *current = head;

    while(current->next != nullptr)
        current = current->next;

    current->next = node;
}

void List::printList() const {
    Node *current = head;
    while(current != nullptr) {
        std::cout << current->key << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}

List::List():head(nullptr){}

List::~List() {
    Node *current = head;
    while(current != nullptr) {
        std::cout << current->key << '\n';
        current = current->next;
    }
};
