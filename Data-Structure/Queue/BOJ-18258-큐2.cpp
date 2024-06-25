// BOJ-18258 / 큐 2
// devgeon, 2024.06.25, C++17
// https://www.acmicpc.net/problem/18258

#include <iostream>

using namespace std;

template <typename Type>
class Node {
  private:
    Type data = 0;
    Node<Type> *next = nullptr;

  public:
    Node(Type data = 0, Node<Type> *next = nullptr);
    Type get_data();
    Node<Type> *get_next();
    void set_next(Node<Type> *next);
};

template <typename Type>
class Queue {
  private:
    Type _size = 0;
    Node<Type> *_front = nullptr;
    Node<Type> *_back = nullptr;

  public:
    void push(Type data);
    Type pop();
    Type front();
    Type back();
    int size();
    bool empty();
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0, num = 0;
    string command = "";
    Queue<int> queue;

    cin >> cases;
    while (cases--) {
        cin >> command;
        if (command == "push") {
            cin >> num;
            queue.push(num);
        } else if (command == "pop") {
            cout << queue.pop() << '\n';
        } else if (command == "size") {
            cout << queue.size() << '\n';
        } else if (command == "empty") {
            cout << (queue.empty() ? 1 : 0) << '\n';
        } else if (command == "front") {
            cout << queue.front() << '\n';
        } else if (command == "back") {
            cout << queue.back() << '\n';
        }
    }

    return 0;
}

template <typename Type>
Node<Type>::Node(Type data, Node<Type> *next) {
    this->data = data;
    this->next = next;
}

template <typename Type>
Type Node<Type>::get_data() {
    return this->data;
}

template <typename Type>
Node<Type> *Node<Type>::get_next() {
    return this->next;
}

template <typename Type>
void Node<Type>::set_next(Node<Type> *next) {
    this->next = next;
}

template <typename Type>
void Queue<Type>::push(Type data) {
    Node<Type> *new_node = new Node<Type>(data);
    if (_size == 0) {
        _front = new_node;
        _back = _front;
    } else {
        _back->set_next(new_node);
        _back = new_node;
    }
    _size++;
}

template <typename Type>
Type Queue<Type>::pop() {
    if (_size == 0) {
        // throw runtime_error("Queue is empty.");
        return -1;
    }
    Type data = _front->get_data();
    Node<Type> *temp = _front;
    if (_front == _back) {
        _back = nullptr;
    }
    _front = _front->get_next();
    _size--;
    delete temp;
    return data;
}

template <typename Type>
Type Queue<Type>::front() {
    if (_size == 0) {
        // throw runtime_error("Queue is empty.");
        return -1;
    }
    return _front->get_data();
}

template <typename Type>
Type Queue<Type>::back() {
    if (_size == 0) {
        // throw runtime_error("Queue is empty.");
        return -1;
    }
    return _back->get_data();
}

template <typename Type>
int Queue<Type>::size() {
    return this->_size;
}

template <typename Type>
bool Queue<Type>::empty() {
    return this->_size == 0;
}
