// BOJ-02252 / 줄 세우기
// devgeon, 2024.05.26, C++17
// https://www.acmicpc.net/problem/2252

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, comparison = 0;
    cin >> num >> comparison;

    vector<int> in_degree(num, 0);
    vector<vector<int>> graph(num, vector<int>());
    for (int i = 0, u = 0, v = 0; i < comparison; i++) {
        cin >> u >> v;
        in_degree[v - 1]++;
        graph[u - 1].push_back(v - 1);
    }

    queue<int> queue;
    for (int i = 0; i < num; i++) {
        if (in_degree[i] != 0) {
            continue;
        }
        queue.push(i);
    }

    while (queue.size()) {
        for (int i = 0, size = queue.size(); i < size; i++) {
            for (int v : graph[queue.front()]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue.push(v);
                }
            }
            cout << queue.front() + 1 << ' ';
            queue.pop();
        }
    }
    cout << endl;

    return 0;
}
