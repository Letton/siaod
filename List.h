#ifndef SIAOD_LIST_H
#define SIAOD_LIST_H

struct Node {
    int key;
    Node *next;
};


class List {
public:
    Node *head;

    List();

    ~List();

    void addNode(int key);

    void printList() const;

};


#endif //SIAOD_LIST_H
