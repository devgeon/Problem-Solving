// BOJ-01158 / 요세푸스 문제
// devgeon, 2024.08.08, C++17
// https://www.acmicpc.net/problem/1158

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int num = 0, dist = 0;
    cin >> num >> dist;

    queue<int> queue;
    for (int i = 1; i <= num; i++) {
        queue.push(i);
    }

    cout << '<';
    while (queue.size() > 1) {
        for (int i = 0; i < dist - 1; i++) {
            queue.push(queue.front());
            queue.pop();
        }
        cout << queue.front() << ", ";
        queue.pop();
    }
    cout << queue.front() << '>' << endl;
    queue.pop();

    return 0;
}
