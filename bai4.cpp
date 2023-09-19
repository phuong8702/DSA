#include <iostream>

const int MAX_SIZE = 100; // Set the maximum size for the stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int x) {
        if (isFull()) {
            std::cout << "Stack is full. Cannot push." << std::endl;
            return;
        }

        arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }

        top--;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        for (int i = 0; i <= top; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    Stack s;

    for (int i = 0; i < n; ++i) {
        std::string operation;
        std::cin >> operation;

        if (operation == "push") {
            int x;
            std::cin >> x;
            s.push(x);
        } else if (operation == "pop") {
            s.pop();
        }
    }

    s.display();

    return 0;
}

