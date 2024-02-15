// BOJ-01697 / 숨바꼭질
// devgeon, 2024.02.15, C++17
// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    const int MAX = 100'000;
    int start = 0, finish = 0, current = 0;
    queue<int> queue;
    vector<int> map(MAX + 1, 0);
    cin >> start >> finish;
    queue.push(start);

    while (true) {
        current = queue.front();
        queue.pop();
        if (current == finish) {
            break;
        }
        if (current > 0 && !map[current - 1]) {
            queue.push(current - 1);
            map[current - 1] = map[current] + 1;
        }
        if (current && current * 2 <= MAX && !map[current * 2]) {
            queue.push(current * 2);
            map[current * 2] = map[current] + 1;
        }
        if (current < MAX && !map[current + 1]) {
            queue.push(current + 1);
            map[current + 1] = map[current] + 1;
        }
    }

    cout << map[current] << endl;
    return 0;
}
