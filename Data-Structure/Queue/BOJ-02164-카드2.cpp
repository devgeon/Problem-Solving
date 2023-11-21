// BOJ-02164 / 카드2
// devgeon, 2023.11.21, C++17
// https://www.acmicpc.net/problem/2164

#include <iostream>

using namespace std;

class Node {
  public:
    int data = 0;
    Node *next = nullptr;

    Node(int data) { this->data = data; }
};

class Queue {
  public:
    int size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;

    void push(int data) {
        if (size == 0) {
            this->head = new Node(data);
            this->tail = this->head;
        } else {
            Node *newNode = new Node(data);
            this->tail->next = newNode;
            this->tail = newNode;
        }
        size++;
    }
    int pop() {
        if (size == 0) {
            return -1;
        } else {
            int data = this->head->data;
            Node *next = this->head->next;
            delete this->head;
            this->head = next;
            size--;
            return data;
        }
    }
};

int main() {
    int n = 0;
    bool drop = true;
    Queue queue;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        queue.push(i);
    }
    while (queue.size > 1) {
        if (drop) {
            queue.pop();
        } else {
            queue.push(queue.pop());
        }
        drop = !drop;
    }

    cout << queue.pop();
    return 0;
}
