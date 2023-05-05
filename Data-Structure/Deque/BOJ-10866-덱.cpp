// BOJ-10866 / 덱
// devgeon, 2023.05.05, C++17
// https://www.acmicpc.net/problem/10866

#include <iostream>
#include <limits>

using namespace std;

template <typename T> class Node {
  private:
    T data_ = T();
    Node *prev_ = nullptr;
    Node *next_ = nullptr;

  public:
    Node(T data, Node *prev = nullptr, Node *next = nullptr) {
        this->data_ = data;
        this->prev_ = prev;
        this->next_ = next;
    }
    T get_data() { return this->data_; }
    void set_data(T data = NULL) { this->data_ = data; }
    Node *get_prev() { return this->prev_; }
    void set_prev(Node *prev) { this->prev_ = prev; }
    Node *get_next() { return this->next_; }
    void set_next(Node *next) { this->next_ = next; }
};

template <typename T> class Deque {
  private:
    Node<T> *front_ = nullptr;
    Node<T> *back_ = nullptr;
    int size_ = 0;

  public:
    void push_front(T data) {
        if (this->full()) {
            throw "full";
        }
        Node<T> *node = new Node(data);
        if (this->empty()) {
            this->back_ = node;
        } else {
            this->front_->set_prev(node);
            node->set_next(this->front_);
        }
        this->front_ = node;
        this->size_++;
    }

    void push_back(T data) {
        if (this->full()) {
            throw "full";
        }
        Node<T> *node = new Node(data);
        if (this->empty()) {
            this->front_ = node;
        } else {
            this->back_->set_next(node);
            node->set_prev(this->back_);
        }
        this->back_ = node;
        this->size_++;
    }

    T pop_front() {
        Node<T> *new_front = nullptr;
        if (this->empty()) {
            throw "empty";
        }
        T data = this->front_->get_data();
        if (this->front_->get_next() == nullptr) {
            delete this->front_;
            this->front_ = nullptr;
            this->back_ = nullptr;
        } else {
            new_front = this->front_->get_next();
            new_front->set_prev(nullptr);
            delete this->front_;
            this->front_ = new_front;
        }
        this->size_--;
        return data;
    }

    T pop_back() {
        Node<T> *new_back = nullptr;
        if (this->empty()) {
            throw "empty";
        }
        T data = this->back_->get_data();
        if (this->back_->get_prev() == nullptr) {
            delete this->back_;
            this->back_ = nullptr;
            this->front_ = nullptr;
        } else {
            new_back = this->back_->get_prev();
            new_back->set_next(nullptr);
            delete this->back_;
            this->back_ = new_back;
        }
        this->size_--;
        return data;
    }

    int size() { return this->size_; }

    bool empty() {
        if (this->size_ == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool full() {
        if (this->size() == numeric_limits<int>::max()) {
            return true;
        } else {
            return false;
        }
    }

    T front() {
        if (!this->empty()) {
            return this->front_->get_data();
        } else {
            throw "empty";
        }
    }

    T back() {
        if (!this->empty()) {
            return this->back_->get_data();
        } else {
            throw "empty";
        }
    }
};

int main() {
    int command_count = 0;
    string command = "";
    int parameter = -1;
    int return_value = 100001;
    Deque<int> deque;

    cin >> command_count;

    for (int i = 0; i < command_count; i++) {
        cin >> command;
        cin.ignore();

        try {
            if (command == "push_front") {
                cin >> parameter;
                cin.ignore();
                deque.push_front(parameter);
            } else if (command == "push_back") {
                cin >> parameter;
                cin.ignore();
                deque.push_back(parameter);
            } else if (command == "pop_front") {
                return_value = deque.pop_front();
            } else if (command == "pop_back") {
                return_value = deque.pop_back();
            } else if (command == "size") {
                return_value = deque.size();
            } else if (command == "empty") {
                return_value = deque.empty() ? 1 : 0;
            } else if (command == "front") {
                return_value = deque.front();
            } else if (command == "back") {
                return_value = deque.back();
            }
        } catch (char const *exception) {
            if (exception == "empty") {
                return_value = -1;
            }
        }

        if (return_value != 100001) {
            cout << return_value << endl;
        }
        parameter = -1;
        return_value = 100001;
    }

    return 0;
}
