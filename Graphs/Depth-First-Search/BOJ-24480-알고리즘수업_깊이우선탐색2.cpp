// BOJ-24480 / 알고리즘 수업 - 깊이 우선 탐색 2
// devgeon, 2024.05.21, C++17
// https://www.acmicpc.net/problem/24480

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int depth_first_search(vector<vector<int>> &graph, vector<int> &visit_check,
                       int current, int count = 1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertices = 0, edges = 0, start = 0;
    cin >> vertices >> edges >> start;

    vector<vector<int>> graph(vertices, vector<int>());
    vector<int> answer(vertices);
    for (int i = 0, u = 0, v = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    depth_first_search(graph, answer, start - 1);
    for (int n : answer) {
        cout << n << '\n';
    }

    return 0;
}

int depth_first_search(vector<vector<int>> &graph, vector<int> &visit_check,
                       int current, int count) {
    visit_check[current] = count;
    sort(graph[current].begin(), graph[current].end(), greater<>());
    for (int node : graph[current]) {
        if (visit_check[node]) {
            continue;
        }
        count = depth_first_search(graph, visit_check, node, count + 1);
    }
    return count;
}
