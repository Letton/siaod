#include <iostream>
#include <vector>
#include <string>

using namespace std;

void arrayInputHandler(int arr[], size_t arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cin >> arr[i];
    }
}

void arrayInputHandler(vector <int> &arr) {
    for (int &el : arr) {
        cin >> el;
    }
}

void printArray(int arr[], size_t arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void printArray(vector <int>& arr) {
    for (int& el : arr) {
        cout << el << "  ";
    }
    cout << "\n";
}

int findMax(const int arr[], size_t arraySize) {
    int max = arr[0];
    for (int i = 0; i < arraySize; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMax(vector <int>& arr) {
    int max = arr[0];
    for (int &el : arr) {
        if (el > max) {
            max = el;
        }
    }
    return max;
}

void arrayInsertMax(int arr[], size_t &arraySize) {
    int insertIndex = -1;
    for (int i = 0; i < arraySize; ++i) {
        string n = to_string(arr[i]);
        if (n[0] == n[n.size() - 1]) {
            insertIndex = i;
            break;
        }
    }
    insertIndex++;
    if (insertIndex != -1) {
        int max = findMax(arr, arraySize);
        arraySize += 1;
        for (int i = arraySize - 1; i > insertIndex; --i) {
            arr[i] = arr[i - 1];
        }
        arr[insertIndex] = max;
    }
    else {
        cout << "Such element not found\n";
    }
}

void arrayInsertMax(vector <int> &arr) {
    int insertIndex = -1;
    for (int i = 0; i < arr.size(); ++i) {
        string n = to_string(arr[i]);
        if (n[0] == n[n.size() - 1]) {
            insertIndex = i;
            break;
        }
    }
    insertIndex++;
    if (insertIndex != -1) {
        int max = findMax(arr);
        arr.push_back(0);
        for (int i = arr.size() - 1; i > insertIndex ; --i) {
            arr[i] = arr[i - 1];
        }
        arr[insertIndex] = max;
    }
    else {
        cout << "Such element not found\n";
    }
}

//void deleteFibonacciElements(int* arr, size_t &arraySize) {
//    size_t oldArraySize = arraySize;
//    for (int i = 0; i < array_size; ++i) {
//        if (arr[i] > max) {
//            max = arr[i];
//        }
//    }
//    return max;
//}
//
//void deleteFibonacciElements(vector <int>& arr) {
//    int max = arr[0];
//    for (int& el : arr) {
//        if (el > max) {
//            max = el;
//        }
//    }
//    return max;
//}

int main() {
    int n;
    cout << "Select a program work option: \n"
            "1 - Static array (max array size = 1000)\n"
            "2 - Dynamic array\n"
            "3 - Vector\n";
    cin >> n;
    if (n == 1) {
        int taskType = 0;
        int arr[1000] = { 0 };
        size_t arraySize = 0;
        cout << "Input array size (max 100)\n";
        cin >> arraySize;
        cout << "Input array, use \"space\" as delimiter\n";
        arrayInputHandler(arr, arraySize);
        while (taskType != -1) {
            cout << "Select task: \n"
                    "1 - Find max element\n"
                    "2 - Insert max element after element whose first and last digits are equal\n"
                    "3 - Remove elements whose digits form a sequence of Fibonacci numbers in which the first and second numbers are 1\n";
            cin >> taskType;
            if (taskType == 1) {
                cout << "Max element is " << findMax(arr, arraySize) << "\n";
            }
            else if (taskType == 2) {
                arrayInsertMax(arr, arraySize);
                printArray(arr, arraySize);
            }
        }

    }
    else if (n == 2) {
        int taskType = 0;
        size_t arraySize = 0;
        cout << "Input array size\n";
        cin >> arraySize;
        int* arr = new int[arraySize];
        cout << "Input array, use \"space\" as delimiter\n";
        arrayInputHandler(arr, arraySize);
        while (taskType != -1) {
            cout << "Select task: \n"
                    "1 - Find max element\n"
                    "2 - Insert max element after element whose first and last digits are equal\n"
                    "3 - Remove elements whose digits form a sequence of Fibonacci numbers in which the first and second numbers are 1\n";
            cin >> taskType;
            if (taskType == 1) {
                cout << "Max element is " << findMax(arr, arraySize) << "\n";
            }
            else if (taskType == 2) {
                arrayInsertMax(arr, arraySize);
                printArray(arr, arraySize);
            }
        }
        delete[] arr;
    }
    else if (n == 3) {
        int taskType = 0;
        size_t arraySize = 0;
        cout << "Input array size\n";
        cin >> arraySize;
        vector <int> arr(arraySize);
        cout << "Input array, use \"space\" as delimiter\n";
        arrayInputHandler(arr);
        while (taskType != -1) {
            cout << "Select task: \n"
                    "1 - Find max element\n"
                    "2 - Insert max element after element whose first and last digits are equal\n"
                    "3 - Remove elements whose digits form a sequence of Fibonacci numbers in which the first and second numbers are 1\n";
            cin >> taskType;
            if (taskType == 1) {
                cout << "Max element is " << findMax(arr) << "\n";
            }
            else if (taskType == 2) {
                arrayInsertMax(arr);
                printArray(arr);
            }
        }
    }
    else {
        cout << "Incorrect input\n";
        return -1;
    }
    return 0;
}