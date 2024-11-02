// BOJ-11725 / 트리의 부모 찾기
// devgeon, 2024.11.02, C++17
// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    queue<int> queue;
    vector<int> parent(num, -1);
    vector<vector<int>> adj_list(num, vector<int>());

    for (int i = 1, u = 0, v = 0; i < num; i++) {
        cin >> u >> v;
        u--, v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    queue.push(0);

    while (queue.size()) {
        for (int v : adj_list[queue.front()]) {
            if (parent[v] > -1) {
                continue;
            }
            parent[v] = queue.front();
            queue.push(v);
        }
        queue.pop();
    }

    for (int i = 1; i < num; i++) {
        cout << parent[i] + 1 << '\n';
    }

    return 0;
}
