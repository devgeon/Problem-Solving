// BOJ-01167 / 트리의 지름
// devgeon, 2024.11.01, C++17
// https://www.acmicpc.net/problem/1167

#include <iostream>
#include <vector>

using namespace std;

class DistToNode {
  public:
    int node, dist;

    DistToNode(int node = 0, int dist = 0) {
        this->node = node, this->dist = dist;
    }
};

DistToNode find_farthest(const vector<vector<DistToNode>> &tree,
                         const int start = 0);

DistToNode _find_farthest(const vector<vector<DistToNode>> &tree,
                          vector<bool> &visited, const int start);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, base_node = 0, diameter = 0;
    cin >> num;

    vector<vector<DistToNode>> adj_list(num);
    for (int i = 0, from = 0, to = 0, dist = 0; i < num; i++) {
        cin >> from;
        from--;
        while (cin >> to && to != -1) {
            cin >> dist;
            to--;
            adj_list[from].emplace_back(to, dist);
        }
    }

    base_node = find_farthest(adj_list).node;
    diameter = find_farthest(adj_list, base_node).dist;
    cout << diameter << endl;

    return 0;
}

DistToNode find_farthest(const vector<vector<DistToNode>> &tree,
                         const int start) {
    vector<bool> visited(tree.size(), false);
    return _find_farthest(tree, visited, start);
}

DistToNode _find_farthest(const vector<vector<DistToNode>> &tree,
                          vector<bool> &visited, const int start) {
    DistToNode result(start), temp;
    visited[start] = true;

    for (const auto &edge : tree[start]) {
        if (visited[edge.node]) {
            continue;
        }
        temp = _find_farthest(tree, visited, edge.node);
        temp.dist += edge.dist;
        if (result.dist < temp.dist) {
            result = temp;
        }
    }

    return result;
}
