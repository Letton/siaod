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

    void add_node(const int &key);

    void print_list() const;
};


#endif //SIAOD_LIST_H
