// BOJ-01260 / DFS와 BFS
// devgeon, 2024.02.07, C++17
// https://www.acmicpc.net/problem/1260

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void DepthFirstSearch(vector<vector<int>> &graph, int start);
void BreadthFirstSearch(vector<vector<int>> &graph, int start);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertex = 0, edge = 0, start = 0;
    cin >> vertex >> edge >> start;
    start--;
    vector<vector<int>> graph(vertex, vector<int>());
    for (int i = 0, a = 0, b = 0; i < edge; i++) {
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (auto &e : graph) {
        sort(e.begin(), e.end());
    }

    DepthFirstSearch(graph, start);
    BreadthFirstSearch(graph, start);

    return 0;
}

void DepthFirstSearch(vector<vector<int>> &graph, int start) {
    int top = 0;
    stack<int> stack;
    vector<bool> visited(graph.size(), false);
    stack.push(start);
    while (!stack.empty()) {
        top = stack.top();
        stack.pop();
        if (visited[top]) {
            continue;
        }
        visited[top] = true;
        cout << top + 1 << " ";
        for (int i = graph[top].size() - 1; i >= 0; i--) {
            if (visited[graph[top][i]]) {
                continue;
            }
            stack.push(graph[top][i]);
        }
    }
    cout << endl;
}

void BreadthFirstSearch(vector<vector<int>> &graph, int start) {
    int front = 0;
    queue<int> queue;
    vector<bool> visited(graph.size(), false);
    queue.push(start);
    visited[start] = true;
    while (!queue.empty()) {
        front = queue.front();
        queue.pop();
        cout << front + 1 << " ";
        for (int i = 0; i < graph[front].size(); i++) {
            if (visited[graph[front][i]]) {
                continue;
            }
            queue.push(graph[front][i]);
            visited[graph[front][i]] = true;
        }
    }
    cout << endl;
}
