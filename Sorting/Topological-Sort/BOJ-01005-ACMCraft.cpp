// BOJ-01005 / ACM Craft
// devgeon, 2024.11.23, C++17
// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
    int cost;
    int indegree;
    int total_cost;
    vector<int> out_edges;

    Node(const int cost = 0, const int indegree = 0)
        : cost(cost), indegree(indegree), total_cost(-1) {}

    friend istream &operator>>(istream &in, Node &node) {
        in >> node.cost;
        return in;
    }
};

int _solve(vector<Node> &nodes, const int current, const int target) {
    if (current == target) {
        return nodes[current].total_cost;
    }
    for (int to : nodes[current].out_edges) {
        if (nodes[to].total_cost < nodes[current].total_cost + nodes[to].cost) {
            nodes[to].total_cost = nodes[current].total_cost + nodes[to].cost;
        }
        nodes[to].indegree--;
        if (nodes[to].indegree == 0) {
            int result = _solve(nodes, to, target);
            if (result >= 0) {
                return result;
            }
        }
    }
    return -1;
}

int solve() {
    int num_nodes = 0, num_edges = 0, target = 0;
    int answer = 0;
    cin >> num_nodes >> num_edges;

    vector<Node> nodes(num_nodes);
    for (Node &node : nodes) {
        cin >> node;
    }
    for (int i = 0, from = 0, to = 0; i < num_edges; i++) {
        cin >> from >> to;
        from--, to--;
        nodes[from].out_edges.push_back(to);
        nodes[to].indegree++;
    }

    cin >> target;
    target--;

    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].indegree > 0 || nodes[i].total_cost >= 0) {
            continue;
        }
        nodes[i].total_cost = nodes[i].cost;
        if ((answer = _solve(nodes, i, target)) >= 0) {
            break;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0;
    cin >> cases;

    while (cases--) {
        cout << solve() << '\n';
    }

    return 0;
}
