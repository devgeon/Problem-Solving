// BOJ-02075 / N번째 큰 수
// devgeon, 2024.05.16, C++17
// https://www.acmicpc.net/problem/2075

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    priority_queue<int, vector<int>, greater<>> p_queue;
    cin >> num;

    for (int i = 0, input = 0; i < num * num; i++) {
        cin >> input;
        if (p_queue.size() == num && input < p_queue.top()) {
            continue;
        }
        p_queue.push(input);
        if (p_queue.size() > num) {
            p_queue.pop();
        }
    }
    cout << p_queue.top() << endl;

    return 0;
}
