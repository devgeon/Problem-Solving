// BOJ-02161 / 카드1
// devgeon, 2024.04.19, C++17
// https://www.acmicpc.net/problem/2161

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    queue<int> queue;
    for (int i = 1; i <= num; i++) {
        queue.push(i);
    }

    while (!queue.empty()) {
        cout << queue.front() << ' ';
        queue.pop();
        if (!queue.empty()) {
            queue.push(queue.front());
            queue.pop();
        }
    }
    cout << endl;

    return 0;
}
