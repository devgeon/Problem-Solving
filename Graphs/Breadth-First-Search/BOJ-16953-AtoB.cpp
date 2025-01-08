// BOJ-16953 / A → B
// devgeon, 2025.01.08, C++17
// https://www.acmicpc.net/problem/16953

#include <iostream>
#include <queue>

using namespace std;

int main() {
    const int MAX = 1'000'000'000;

    int a = 0, b = 0;
    int count = 0, answer = 0;
    long long curr = 0, next = 0;

    queue<int> queue;
    vector<bool> visited(MAX + 1);

    cin >> a >> b;
    queue.push(a);
    visited[a] = true;
    queue.push(-1);

    while (queue.size() > 1) {
        curr = queue.front();
        queue.pop();

        if (curr == b) {
            break;
        }
        if (curr < 0) {
            count++;
            queue.push(-1);
            continue;
        }

        next = curr * 2;
        if (next <= MAX && !visited[next]) {
            queue.push(next);
            visited[next] = true;
        }
        next = curr * 10 + 1;
        if (next <= MAX && !visited[next]) {
            queue.push(next);
            visited[next] = true;
        }
    }

    answer = visited[b] ? count + 1 : -1;
    cout << answer << endl;

    return 0;
}
