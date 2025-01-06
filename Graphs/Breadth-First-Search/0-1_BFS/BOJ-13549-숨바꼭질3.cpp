// BOJ-13549 / 숨바꼭질 3
// devgeon, 2025.01.06, C++17
// https://www.acmicpc.net/problem/13549

#include <deque>
#include <iostream>
#include <vector>

#define INT_MAX (int)((1U << 31) - 1)

using namespace std;

int main() {
    const int MAX = 100'000;
    int from = 0, to = 0, time = 0;
    cin >> from >> to;

    deque<int> deque = {from, -1};
    vector<int> times(MAX * 2 + 1, INT_MAX);

    while (deque.size() > 1) {
        int curr = deque.front();
        deque.pop_front();

        if (curr < 0) {
            time++;
            deque.push_back(-1);
            continue;
        }
        times[curr] = min(time, times[curr]);

        for (int add : {1, -1}) {
            int next = curr + add;
            if (next < 0 || next > MAX * 2 || times[next] <= time + 1) {
                continue;
            }
            deque.push_back(next);
        }
        for (int mul : {2}) {
            int next = curr * mul;
            if (next > MAX * 2 || times[next] <= time) {
                continue;
            }
            deque.push_front(next);
        }
    }

    cout << times[to] << endl;
    return 0;
}
