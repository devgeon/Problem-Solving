// BOJ-01949 / 우수 마을
// devgeon, 2024.05.28, C++17
// https://www.acmicpc.net/problem/1949

#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<vector<int>> &tree, const vector<int> &population,
          vector<vector<int>> &cache, int current, int parent = -1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<int> population(num, 0);
    for (int &n : population) {
        cin >> n;
    }
    vector<vector<int>> tree(num, vector<int>());
    for (int i = 0, u = 0, v = 0; i < num - 1; i++) {
        cin >> u >> v;
        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    vector<vector<int>> cache(2, vector<int>(num, 0));
    cout << solve(tree, population, cache, 0) << endl;

    return 0;
}

int solve(const vector<vector<int>> &tree, const vector<int> &population,
          vector<vector<int>> &cache, int current, int parent) {
    for (int v : tree[current]) {
        if (v == parent) {
            continue;
        }
        solve(tree, population, cache, v, current);
        cache[0][current] += max(cache[0][v], cache[1][v]);
        cache[1][current] += cache[0][v];
    }
    cache[1][current] += population[current];

    return max(cache[0][current], cache[1][current]);
}
