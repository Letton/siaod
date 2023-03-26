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

    bool delete_key(const int &key);

    Node* find_key(const int &key) const;
};


#endif //SIAOD_LIST_H
