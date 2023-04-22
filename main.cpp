#include "StackList.h"
#include "StackArray.h"
#include <iostream>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

char* infixToPostfix(const char* infix) {
    StackList<char> stack;
    int length = 0;
    for (size_t i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isOperand(c)) {
            length++;
        } else if (isOperator(c)) {
            length += 2;
            stack.push(c);
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                length++;
                stack.pop();
            }
            if (!stack.isEmpty()) {
                stack.pop();
            }
        }
    }
    while (!stack.isEmpty()) {
        length++;
        stack.pop();
    }
    char* postfix = new char[length + 1];
    int index = 0;
    for (size_t i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isOperand(c)) {
            postfix[index++] = c;
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && stack.top() != '(' && precedence(c) <= precedence(stack.top())) {
                postfix[index++] = stack.top();
                stack.pop();
            }
            stack.push(c);
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                postfix[index++] = stack.top();
                stack.pop();
            }
            if (!stack.isEmpty()) {
                stack.pop();
            }
        }
    }
    while (!stack.isEmpty()) {
        postfix[index++] = stack.top();
        stack.pop();
    }
    postfix[index] = '\0';
    return postfix;
}


int main() {
    int n;
    cout << "Select task: \n"
            "1 - Convert infix form of bracket expression to postfix\n"
            "2 - Perform operations on the stack (singly-directed list)\n"
            "3 - Perform operations on the stack (static array)\n";
    cin >> n;
    if (n == 1) {
        cout << "Input infix expression without spaces (allowed operators: +, -, *, /)\n";
        char s[100];
        cin >> s;
        cout << "Postfix form is:\n" << infixToPostfix(s);
    } else if (n == 2) {
        cout << "Stack stores int values\n";
        StackList<int> stack;
        int a = -1;
        while (a != 0) {
            cout << "Select action: \n"
                    "1 - Push element to stack\n"
                    "2 - Pop element from stack\n"
                    "3 - Print top element\n"
                    "4 - Clear stack\n"
                    "5 - Is stack empty\n"
                    "0 - Exit\n";
            cin >> a;
            if (a == 1) {
                int value;
                cout << "Input element\n";
                cin >> value;
                stack.push(value);
                stack.print();
            }
            if (a == 2) {
                stack.pop();
                stack.print();
            }
            if (a == 3) {
                if (!stack.isEmpty())
                    cout << "Top elemnt is " << stack.top() << "\n";
                else
                    stack.print();
            }
            if (a == 4) {
                stack.clear();
                stack.print();
            }
            if (a == 5) {
                if (stack.isEmpty())
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not empty\n";
            }
        }

    } else if (n == 3) {
        cout << "Stack stores int values (max size = 100)\n";
        StackArray<int, 100> stack;
        int a = -1;
        while (a != 0) {
            cout << "Select action: \n"
                    "1 - Push element to stack\n"
                    "2 - Pop element from stack\n"
                    "3 - Print top element\n"
                    "4 - Clear stack\n"
                    "5 - Is stack empty\n"
                    "0 - Exit\n";
            cin >> a;
            if (a == 1) {
                int value;
                cout << "Input element\n";
                cin >> value;
                stack.push(value);
                stack.print();
            }
            if (a == 2) {
                stack.pop();
                stack.print();
            }
            if (a == 3) {
                if (!stack.isEmpty())
                    cout << "Top element is " << stack.top() << "\n";
                else
                    stack.print();
            }
            if (a == 4) {
                stack.clear();
                stack.print();
            }
            if (a == 5) {
                if (stack.isEmpty())
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not empty\n";
            }
        }
    }
    return 0;
}