// BOJ-01197 / 최소 스패닝 트리
// devgeon, 2024.05.31, C++17
// https://www.acmicpc.net/problem/1197

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
  private:
    vector<int> roots;

  public:
    DisjointSet(const int num);
    int find(const int vertex);
    bool union_(const int vertex1, const int vertex2);
};

class Edge {
  public:
    int vertex1 = -1, vertex2 = -1, weight = 1;

    Edge(const int vertex1, const int vertex2, const int weight = 1);
    bool operator<(const Edge &element);
};

istream &operator>>(istream &in, Edge &edge) {
    in >> edge.vertex1 >> edge.vertex2 >> edge.weight;
    edge.vertex1--, edge.vertex2--;
    return in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices = 0, num_edges = 0, answer = 0;
    cin >> num_vertices >> num_edges;

    vector<Edge> edges(num_edges, Edge(0, 0));
    for (Edge &edge : edges) {
        cin >> edge;
    }
    sort(edges.begin(), edges.end());

    DisjointSet disjoint_set(num_vertices);
    for (Edge edge : edges) {
        if (!disjoint_set.union_(edge.vertex1, edge.vertex2)) {
            continue;
        }
        answer += edge.weight;
    }
    cout << answer << endl;

    return 0;
}

DisjointSet::DisjointSet(const int num) {
    roots.reserve(num);
    for (int i = 0; i < num; i++) {
        roots.push_back(i);
    }
}

int DisjointSet::find(const int vertex) {
    if (vertex == roots[vertex]) {
        return vertex;
    }
    return roots[vertex] = find(roots[vertex]);
}

bool DisjointSet::union_(const int vertex1, const int vertex2) {
    int root1 = find(vertex1), root2 = find(vertex2);
    if (root1 == root2) {
        return false;
    }
    roots[root1] = root2;
    return true;
}

Edge::Edge(const int vertex1, const int vertex2, const int weight) {
    this->vertex1 = vertex1;
    this->vertex2 = vertex2;
    this->weight = weight;
}

bool Edge::operator<(const Edge &element) {
    return this->weight < element.weight;
}
