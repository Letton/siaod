#include "List.h"
#include <iostream>

using namespace std;

void remove_zeros(Node *&node) {
    if (node == nullptr) {
        return;
    }
    if (node->key == 0) {
        Node *temp = node;
        node = node->next;
        delete temp;
        return remove_zeros(node);
    } else {
        remove_zeros(node->next);
    }
}

long long calculate_expression(int* &arr, const size_t arr_size) {
    if (arr_size == 0) {
        return 0;
    }
    long long summ = 1;
    for (size_t i = 1; i <= arr_size; ++i) {
        long long sub_summ = 0;
        for (size_t j = 0; j < i; ++j) {
            sub_summ += arr[arr_size - 1 - j];
        }
        summ *= sub_summ;
    }
    return summ;
}


long long calculate_expression_recursive(int* &arr, size_t n) {
    if (n == 0) {
        return arr[0];
    }
    long long x_n = arr[n];
    long long prev = calculate_expression_recursive(arr, n - 1);
    return x_n * (x_n + prev);
}

int main() {
    int n;
    cout << "Select task: \n"
            "1 - Given a sequence of N numbers X1,X2,....,XN. Calculate the value of the expression:\n"
            "Xn(Xn+Xn-1)(Xn+Xn-1+Xn-2)(Xn+Xn-1+Xn-2+Xn-3)... (Xn+Xn-1+Xn- 2+...+X1)\n"
            "(Iterative method)\n"
            "2 - Given a sequence of N numbers X1,X2,....,XN. Calculate the value of the expression:\n"
            "Xn(Xn+Xn-1)(Xn+Xn-1+Xn-2)(Xn+Xn-1+Xn-2+Xn-3)... (Xn+Xn-1+Xn- 2+...+X1)\n"
            "(Recursive method)\n"
            "3 - Remove zeros from singly-directed list\n"
            "(Recursive method)\n";
    cin >> n;
    if (n == 1) {
        size_t arr_size;
        cout << "Input count of numbers:\n";
        cin >> arr_size;
        int *arr = new int[arr_size];
        cout << "Input numbers, use \"space\" as delimiter:\n";
        for (size_t i = 0; i < arr_size; ++i) {
            cin >> arr[i];
        }
        cout << "Value of the expression: " << calculate_expression(arr, arr_size) << "\n";
    } else if (n == 2) {
        size_t arr_size;
        long long summ = 1;
        cout << "Input count of numbers:\n";
        cin >> arr_size;
        int *arr = new int[arr_size];
        cout << "Input numbers, use \"space\" as delimiter:\n";
        for (size_t i = 0; i < arr_size; ++i) {
            cin >> arr[i];
        }
        cout  << "Value of the expression: " << calculate_expression_recursive(arr, arr_size - 1);
    } else if (n == 3) {
        size_t list_size;
        int key;
        List list;
        cout << "Input the number of nodes in the list:\n";
        cin >> list_size;
        cout << "Input keys, use \"space\" as delimiter:\n";
        for (size_t i = 0; i < list_size; ++i) {
            cin >> key;
            list.add_node(key);
        }
        remove_zeros(list.head);
        cout << "List without zeros:\n";
        list.print_list();
    }
    return 0;
}