// BOJ-01753 / 최단경로
// devgeon, 2024.06.01, C++17
// https://www.acmicpc.net/problem/1753

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 300'000 * 10 + 1;

class AdjListElement {
  public:
    int to = 0, weight = 0;
    AdjListElement(const int to, const int weight);
    bool operator>(const AdjListElement &element) const;
};

using Graph = vector<vector<AdjListElement>>;

void dijkstra(const Graph &graph, vector<int> &distance, const int start);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices = 0, num_edges = 0, start = 0;
    cin >> num_vertices >> num_edges >> start;
    start--;

    Graph graph(num_vertices, vector<AdjListElement>());
    for (int i = 0, from = 0, to = 0, weight = 0; i < num_edges; i++) {
        cin >> from >> to >> weight;
        graph[from - 1].emplace_back(to - 1, weight);
    }

    vector<int> distance(num_vertices);
    dijkstra(graph, distance, start);
    for (int d : distance) {
        if (d == MAX) {
            cout << "INF\n";
            continue;
        }
        cout << d << '\n';
    }

    return 0;
}

AdjListElement::AdjListElement(const int to, const int weight) {
    this->to = to;
    this->weight = weight;
}

bool AdjListElement::operator>(const AdjListElement &element) const {
    return this->weight > element.weight;
}

void dijkstra(const Graph &graph, vector<int> &distance, const int start) {
    priority_queue<AdjListElement, vector<AdjListElement>,
                   greater<AdjListElement>> priority_queue;
    vector<bool> visited(distance.size(), false);
    for (int &d : distance) {
        d = MAX;
    }
    distance[start] = 0;
    priority_queue.push(AdjListElement(start, 0));
    while (priority_queue.size()) {
        int current = priority_queue.top().to;
        priority_queue.pop();
        if (visited[current]) {
            continue;
        }
        visited[current] = true;
        for (auto [next, weight] : graph[current]) {
            if (distance[next] <= distance[current] + weight) {
                continue;
            }
            distance[next] = distance[current] + weight;
            priority_queue.emplace(next, distance[next]);
        }
    }
}
