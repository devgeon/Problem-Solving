// BOJ-02606 / 바이러스
// devgeon, 2024.02.21, C++17
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int total_computers = 0, total_connections = 0;
    int computer1 = 0, computer2 = 0, answer = 0;
    cin >> total_computers >> total_connections;

    vector<vector<int>> connection_info(total_computers, vector<int>());
    vector<bool> is_infected(total_computers, false);
    queue<int> queue;

    for (int i = 0; i < total_connections; i++) {
        cin >> computer1 >> computer2;
        connection_info[computer1 - 1].push_back(computer2 - 1);
        connection_info[computer2 - 1].push_back(computer1 - 1);
    }

    queue.push(0);
    is_infected[0] = true;
    while (!queue.empty()) {
        for (int i : connection_info[queue.front()]) {
            if (!is_infected[i]) {
                answer++;
                queue.push(i);
                is_infected[i] = true;
            }
        }
        queue.pop();
    }

    cout << answer << endl;

    return 0;
}
