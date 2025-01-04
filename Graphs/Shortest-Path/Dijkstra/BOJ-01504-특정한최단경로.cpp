// BOJ-01504 / 특정한 최단 경로
// devgeon, 2025.01.04, C++17
// https://www.acmicpc.net/problem/1504

#include <iostream>
#include <queue>
#include <vector>

#define INT_MAX (int)((1U << 31) - 1)

using namespace std;

class Edge {
  public:
    int dest = 0, cost = 0;

    Edge(int dest, int cost) : dest(dest), cost(cost) {}

    bool operator>(const Edge &edge) const { return (this->cost > edge.cost); }
};

void dijkstra(const vector<vector<Edge>> &adj_list, const int start,
              vector<int> &costs) {
    vector<int> temp(adj_list.size() + 1, INT_MAX);
    temp[start] = 0;
    costs.swap(temp);

    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;
    heap.emplace(start, 0);

    while (heap.size()) {
        const Edge top = heap.top();
        heap.pop();

        for (const Edge &edge : adj_list[top.dest]) {
            if (costs[edge.dest] <= costs[top.dest] + edge.cost) {
                continue;
            }
            costs[edge.dest] = costs[top.dest] + edge.cost;
            heap.emplace(edge.dest, costs[edge.dest]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_nodes = 0, total_edges = 0;
    int v1 = 0, v2 = 0;
    long long answer = INT_MAX;

    cin >> total_nodes >> total_edges;

    vector<vector<Edge>> adj_list(total_nodes + 1, vector<Edge>());
    for (int i = 1, u = 0, v = 0, cost = 0; i <= total_edges; i++) {
        cin >> u >> v >> cost;
        adj_list[u].emplace_back(v, cost);
        adj_list[v].emplace_back(u, cost);
    }
    cin >> v1 >> v2;

    vector<int> costs_v1, costs_v2;
    dijkstra(adj_list, v1, costs_v1);
    dijkstra(adj_list, v2, costs_v2);

    answer = min((long long)costs_v1[1] + costs_v1[v2] + costs_v2[total_nodes],
                 (long long)costs_v2[1] + costs_v1[v2] + costs_v1[total_nodes]);
    answer = (answer < INT_MAX ? answer : -1);
    cout << answer << endl;

    return 0;
}
