#include <iostream>

const int MAX_SIZE = 100; // Ð?t kích thu?c t?i da cho hàng d?i

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        int current = front;
        while (current != rear) {
            std::cout << arr[current] << " ";
            current = (current + 1) % MAX_SIZE;
        }
        std::cout << arr[rear] << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    Queue q;

    for (int i = 0; i < n; ++i) {
        std::string operation;
        std::cin >> operation;

        if (operation == "enqueue") {
            int x;
            std::cin >> x;
            q.enqueue(x);
        } else if (operation == "dequeue") {
            q.dequeue();
        }
    }

    q.display();

    return 0;
}

