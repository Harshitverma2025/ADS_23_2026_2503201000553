#include <iostream>
using namespace std;

const int MAX = 10;
int stack[MAX];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX - 1);
}

void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow!\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed into the stack.\n";
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!\n";
    } else {
        cout << stack[top] << " popped from the stack.\n";
        top--;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

void displayStack() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements (Top to Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n===== Stack Using Array =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Show Top (Peek)\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                displayStack();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}