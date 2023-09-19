#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int count_triplets() {
        int count = 0;
        Node* current = head;

        while (current != NULL && current->next != NULL && current->next->next != NULL) {
            int sum = current->data + current->next->data + current->next->next->data;
            if (sum == 0) {
                count++;
            }
            current = current->next;
        }

        return count;
    }
};

int main() {
    int n;
    std::cin >> n;

    DoublyLinkedList linkedList;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        linkedList.insert(value);
    }

    int result = linkedList.count_triplets();
    std::cout << result << std::endl;

    return 0;
}

