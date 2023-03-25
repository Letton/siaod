#include "struct.h"
#include "List.h"

void insert_key(auto &lists, int key, size_t size) {
    size_t i = key % size;
    lists[i].addNode(key);
}

int main() {
    size_t lists_size;
    List lists[1000];
    int n;
    cout << "Input the size of the array of lists (max size = 1000)\n";
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
            cout << "Input key\n";
            cin >> key;
            insert_key(lists, key, lists_size);
            cout << "Lists:\n";
            for (size_t i = 0; i < lists_size; ++i) {
                lists[i].printList();
            }
        }
    }
    return 0;
}