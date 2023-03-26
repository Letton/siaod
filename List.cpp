#include "List.h"
#include <iostream>

void List::add_node(const int &key) {
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

void List::print_list() const {
    Node *current = head;
    while(current != nullptr) {
        std::cout << current->key << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}

bool List::delete_key(const int &key) {
    bool flag = false;
    Node *current = head;
    Node *prev = current;
    while(current != nullptr) {
        if (current->key == key && current == head) {
            current = head->next;
            delete head;
            head = current;
            prev = current;
        } else if (current->key == key) {
            prev->next = current->next;
            delete current;
            current = prev->next;
            flag = true;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return flag;
}

List::List():head(nullptr){}

List::~List() {
    Node *current = head;
    while(current != nullptr) {
        std::cout << current->key << '\n';
        current = current->next;
    }
}

Node *List::find_key(const int &key) const {
    Node *current = head;
    while(current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
};
