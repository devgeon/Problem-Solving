// BOJ-01766 / 문제집
// devgeon, 2025.01.02, C++17
// https://www.acmicpc.net/problem/1766

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int total_nodes = 0, total_edges = 0;
    cin >> total_nodes >> total_edges;

    vector<int> indegree(total_nodes + 1);
    vector<vector<int>> adj_list(total_nodes + 1, vector<int>());
    for (int i = 1, u = 0, v = 0; i <= total_edges; i++) {
        cin >> u >> v;
        adj_list[u].push_back(v);
        indegree[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 1; i <= total_nodes; i++) {
        if (indegree[i] == 0) {
            minheap.push(i);
        }
    }

    while (minheap.size()) {
        int top = minheap.top();
        minheap.pop();

        for (const int n : adj_list[top]) {
            indegree[n]--;
            if (indegree[n] == 0) {
                minheap.push(n);
            }
        }
        cout << top << ' ';
    }

    return 0;
}
