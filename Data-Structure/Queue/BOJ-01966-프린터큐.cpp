// BOJ-01966 / 프린터 큐
// devgeon, 2024.01.25, C++17
// https://www.acmicpc.net/problem/1966

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
    int front = -1;
    int back = -1;
    Node *front_ptr = nullptr;
    Node *back_ptr = nullptr;

    ~Queue() { clear(); }

    void push(int data) {
        Node *new_node = new Node(data);
        if (front_ptr == nullptr) {
            front_ptr = new_node;
            front = data;
        } else {
            back_ptr->next = new_node;
        }
        back_ptr = new_node;
        back = data;
    }

    void pop() {
        Node *node = front_ptr->next;
        delete front_ptr;
        front_ptr = node;
        if (front_ptr != nullptr) {
            front = front_ptr->data;
        } else {
            back_ptr = nullptr;
            front = -1;
            back = -1;
        }
    }

    void clear() {
        Node *next = front_ptr;
        while (next != nullptr) {
            next = front_ptr->next;
            pop();
        }
    }
};

int solve() {
    int total_paper = 0, input = 0, count = 1;
    int target_index = 0, target_priority = 0;
    int counter[9] = {0};
    Queue queue;

    cin >> total_paper >> target_index;
    for (int i = 0; i < total_paper; i++) {
        cin >> input;
        counter[input - 1]++;
        if (i == target_index) {
            target_priority = input;
            input = -1;
        }
        queue.push(input);
    }

    for (int priority = 9; priority > 0; priority--) {
        while (counter[priority - 1] > 0) {
            if (queue.front == -1 && target_priority == priority) {
                return count;
            }
            if (queue.front == priority) {
                queue.pop();
                counter[priority - 1]--;
                count++;
            } else {
                queue.push(queue.front);
                queue.pop();
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_case = 0;
    cin >> total_case;

    while (total_case) {
        cout << solve() << "\n";
        total_case--;
    }

    return 0;
}
