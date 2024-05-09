// BOJ-01927 / 최소 힙
// devgeon, 2024.02.11, C++17
// https://www.acmicpc.net/problem/1927

#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
  private:
    const int ROOT = 1;
    int size_ = 0;
    vector<int> heap_;

  public:
    MinHeap() { heap_.push_back(0); }
    void push(int num) {
        int child = heap_.size(), parent = child / 2;
        heap_.push_back(num);
        size_++;
        while (child > ROOT && heap_[child] < heap_[parent]) {
            heap_[child] ^= heap_[parent] ^= heap_[child] ^= heap_[parent];
            child = parent;
            parent = child / 2;
        }
    }
    void pop() {
        if (size_ == 0) {
            return;
        }
        int parent = ROOT, child = parent * 2, min_index = -1, min_value = -1;
        heap_[ROOT] = heap_[heap_.size() - 1];
        heap_.pop_back();
        size_--;
        while (child < heap_.size()) {
            min_index = -1;
            min_value = heap_[parent];
            for (; child < (parent + 1) * 2; child++) {
                if (child == heap_.size()) {
                    break;
                }
                if (heap_[child] < min_value) {
                    min_value = heap_[child];
                    min_index = child;
                }
            }
            if (min_index != -1) {
                heap_[parent] ^= heap_[min_index] ^= heap_[parent] ^=
                    heap_[min_index];
            }
            parent = min_index;
            child = parent * 2;
        }
    }
    // int top() {
    //     if (empty()) {
    //         throw out_of_range("The heap is empty.");
    //     }
    //     return heap_[ROOT];
    // }
    int top() { return (size_ ? heap_[ROOT] : 0); }
    int size() { return size_; }
    bool empty() { return (size_ ? true : false); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, input = 0;
    MinHeap minheap;

    cin >> num;
    while (num) {
        cin >> input;
        if (input) {
            minheap.push(input);
        } else {
            // try {
            //     cout << minheap.top() << "\n";
            // } catch (out_of_range) {
            //     cout << 0 << "\n";
            // }
            cout << minheap.top() << "\n";
            minheap.pop();
        }
        num--;
    }

    return 0;
}
