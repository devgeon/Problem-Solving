// BOJ-16936 / 나3곱2
// devgeon, 2024.10.14, C++17
// https://www.acmicpc.net/problem/16936

#include <deque>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int len = 0;
    long long num = 0;
    cin >> len;

    deque<long long> seq_a;
    unordered_set<long long> seq_b;

    for (int i = 0; i < len; i++) {
        cin >> num;
        seq_b.insert(num);
    }
    num = *seq_b.begin();
    seq_a.push_back(num);
    seq_b.erase(num);

    while (seq_b.size()) {
        num = seq_a.front();
        if (seq_b.find(num * 3) != seq_b.end()) {
            seq_a.push_front(num * 3);
            seq_b.erase(num * 3);
        } else if (num % 2 == 0 && seq_b.find(num / 2) != seq_b.end()) {
            seq_a.push_front(num / 2);
            seq_b.erase(num / 2);
        }
        num = seq_a.back();
        if (seq_b.find(num * 2) != seq_b.end()) {
            seq_a.push_back(num * 2);
            seq_b.erase(num * 2);
        } else if (num % 3 == 0 && seq_b.find(num / 3) != seq_b.end()) {
            seq_a.push_back(num / 3);
            seq_b.erase(num / 3);
        }
    }

    for (long long n : seq_a) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
