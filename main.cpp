#include "List.h"
#include <iostream>

using namespace std;

void insert_key(auto &lists, int key, const size_t &size) {
    size_t i = key % size;
    lists[i].add_node(key);
}

void print_lists(auto &lists, const size_t &size) {
    cout << "Lists:\n";
    for (size_t i = 0; i < size; ++i) {
        cout << i << ": ";
        lists[i].print_list();
    }
}

bool delete_key(auto &lists, const size_t &size, const int &key) {
    bool flag = false;
    for (size_t i = 0; i < size; ++i) {
        if (lists[i].delete_key(key)) {
            flag = true;
        }
    }
    return flag;
}

Node* find_key(auto &lists, const size_t &size, const int &key) {
    for (size_t i = 0; i < size; ++i) {
        Node* node = lists[i].find_key(key);
        if (node != nullptr) {
            return node;
        }
    }
    return nullptr;
}

int main() {
    size_t lists_size;
    List lists[1000];
    int n;
    cout << "Input the size of the array of lists (max size = 1000):\n";
    cin >> lists_size;
    cout << "Select task: \n"
          "1 - Inserting the key a passed as a parameter into the i-th list of the array.\n"
          "    Index i is determined by the rule: i = key % n.\n"
          "2 - Remove key value from list\n"
          "3 - Find a node with a key value and return a pointer to the found node.\n"
          "0 - Exit\n";
    cin >> n;
    while (n != 0) {
        if (n == 1) {
            int key;
            cout << "Input key:\n";
            cin >> key;
            insert_key(lists, key, lists_size);
            print_lists(lists, lists_size);
        } else if (n == 2) {
            int key;
            cout << "Input enter the value of the key to delete:\n";
            cin >> key;
            if (!delete_key(lists, lists_size, key)) {
                cout << "Key not found in any list\n";
            }
            print_lists(lists, lists_size);
        } else if (n == 3) {
            int key;
            cout << "Input enter the value of the key to find:\n";
            cin >> key;
            Node* node = find_key(lists, lists_size, key);
            if (node == nullptr) {
                cout << "Key not found in any list\n";
            } else {
                cout << "Address of the first occurrence of the key " << node->key << " is " << node << "\n";
            }
        }
        cout << "Select task: \n"
                "1 - Inserting the key a passed as a parameter into the i-th list of the array.\n"
                "    Index i is determined by the rule: i = key % n.\n"
                "2 - Remove key value from list\n"
                "3 - Find a node with a key value and return a pointer to the found node.\n"
                "0 - Exit\n";
        cin >> n;
    }
    return 0;
}