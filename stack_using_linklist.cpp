#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push(int value) {
    Node* newNode = new Node(value); 
    newNode->next = top;
    top = newNode;

    cout << value << " pushed into the stack.\n";
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!\n";
    } else {
        Node* temp = top;
        cout << top->data << " popped from the stack.\n";
        top = top->next;
        delete temp;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element is: " << top->data << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        Node* temp = top;
        cout << "Stack elements (Top to Bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n===== Stack Using Linked List (Constructor) =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
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
                display();
                break;

            case 5:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}