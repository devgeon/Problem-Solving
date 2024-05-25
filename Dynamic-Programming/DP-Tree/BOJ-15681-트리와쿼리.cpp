// BOJ-15681 / 트리와 쿼리
// devgeon, 2024.05.25, C++17
// https://www.acmicpc.net/problem/15681

#include <iostream>
#include <vector>

using namespace std;

int count_nodes(vector<vector<int>> &tree, vector<int> &count, int current, int parent = -1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, root = 0, query = 0;
    cin >> num >> root >> query;

    vector<int> count(num + 1, 0);
    vector<vector<int>> tree(num + 1, vector<int>());
    for (int i = 0, u = 0, v = 0; i < num - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    count_nodes(tree, count, root);

    for (int i = 0, v = 0; i < query; i++) {
        cin >> v;
        cout << count[v] << '\n';
    }

    return 0;
}

int count_nodes(vector<vector<int>> &tree, vector<int> &count, int current, int parent) {
    int result = 1;
    for (int v : tree[current]) {
        if (v == parent) {
            continue;
        }
        result += count_nodes(tree, count, v, current);
    }
    count[current] = result;
    return result;
};
