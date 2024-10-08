// BOJ-01865 / 웜홀
// devgeon, 2024.10.08, C++17
// https://www.acmicpc.net/problem/1865

#include <iostream>
#include <vector>

using namespace std;

const int INF = 2500 * 10'000 + 1;

class Edge {
  public:
    int start = 0, end = 0, time = 0;
    bool is_road = true;
    Edge(int start, int end, int time, bool is_road);
};

void solve();

bool bellman_ford(vector<Edge> &edges, vector<int> &result);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    while (num--) {
        solve();
    }

    return 0;
}

Edge::Edge(int start, int end, int time, bool is_road) {
    this->start = start;
    this->end = end;
    this->time = time;
    this->is_road = is_road;
}

void solve() {
    int num_of_nodes = 0, num_of_roads = 0, num_of_wormholes = 0;
    int start = 0, end = 0, time = 0;
    bool answer = true;
    cin >> num_of_nodes >> num_of_roads >> num_of_wormholes;

    vector<Edge> edges;
    edges.reserve(num_of_roads + num_of_wormholes);
    for (int i = 0; i < num_of_roads; i++) {
        cin >> start >> end >> time;
        edges.emplace_back(start - 1, end - 1, time, true);
    }
    for (int i = 0; i < num_of_wormholes; i++) {
        cin >> start >> end >> time;
        edges.emplace_back(start - 1, end - 1, -time, false);
    }

    vector<int> min_time(num_of_nodes, INF);
    answer = bellman_ford(edges, min_time);

    cout << (answer ? "NO" : "YES") << '\n';
}

bool bellman_ford(vector<Edge> &edges, vector<int> &result) {
    result[0] = 0;
    for (int i = 1; i < edges.size(); i++) {
        for (const Edge &e : edges) {
            result[e.end] = min(result[e.end], result[e.start] + e.time);
            if (e.is_road) {
                result[e.start] = min(result[e.start], result[e.end] + e.time);
            }
        }
    }
    for (const Edge &e : edges) {
        if (result[e.start] + e.time < result[e.end] ||
            (e.is_road && result[e.end] + e.time < result[e.start])) {
            return false;
        }
    }
    return true;
}
