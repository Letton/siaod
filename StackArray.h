#ifndef SIAOD_STACKARRAY_H
#define SIAOD_STACKARRAY_H

#include <iostream>

using namespace std;

template <typename T, int capacity>
class StackArray {
private:
    T data[capacity];
    int topIndex;
public:
    StackArray() {
        topIndex = -1;
    }

    ~StackArray() = default;

    void push(T value) {
        if (topIndex < capacity - 1) {
            topIndex++;
            data[topIndex] = value;
        }
        else {
            cout << "Error: Stack overflow\n";
        }
    }

    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        }
    }

    T top() const {
        if (topIndex >= 0) {
            return data[topIndex];
        }
        return T();
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    void clear() {
        topIndex = -1;
    }

    void print() const {
        if (isEmpty())
            cout << "Stack is empty\n";
        else {
            cout << "Stack (From top to bottom):\n";
            for (size_t i = topIndex; i > 0; --i) {
                cout << data[i] << "\n|\n";
            }
            cout << data[0] << "\n";
        }
    }
};

#endif //SIAOD_STACKARRAY_H
