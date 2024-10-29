// BOJ-01967 / 트리의 지름
// devgeon, 2024.10.29, C++17
// https://www.acmicpc.net/problem/1967

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Edge {
  public:
    int child = 0, cost = 0;
    Edge(const int child, const int cost) {
        this->child = child, this->cost = cost;
    }
};

class Result {
  public:
    int diameter = 0, max_cost = 0;
    Result(const int diameter, const int max_cost) {
        this->diameter = diameter, this->max_cost = max_cost;
    }
};

Result get_diameter(const vector<vector<Edge>> &tree, const int root = 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, answer = 0;
    cin >> num;

    vector<vector<Edge>> adj_list(num, vector<Edge>());
    for (int i = 1, parent = 0, child = 0, cost = 0; i < num; i++) {
        cin >> parent >> child >> cost;
        adj_list[parent - 1].emplace_back(child - 1, cost);
    }

    answer = get_diameter(adj_list).diameter;
    cout << answer << endl;

    return 0;
}

Result get_diameter(const vector<vector<Edge>> &tree, const int root) {
    int max_diameter = 0, diameter = 0, max_cost = 0;
    priority_queue<int, vector<int>, greater<>> pri_queue;

    for (const Edge &e : tree[root]) {
        Result result = get_diameter(tree, e.child);
        max_diameter = max(result.diameter, max_diameter);
        pri_queue.push(result.max_cost + e.cost);
        if (pri_queue.size() > 2) {
            pri_queue.pop();
        }
    }

    if (pri_queue.size() > 0) {
        if (pri_queue.size() == 2) {
            diameter = pri_queue.top(), pri_queue.pop();
        }
        max_cost = pri_queue.top(), pri_queue.pop();
        diameter += max_cost;
        max_diameter = max(diameter, max_diameter);
    }

    return Result(max_diameter, max_cost);
}
