// BOJ-28360 / 양동이 게임
// devgeon, 2024.05.27, C++17
// https://www.acmicpc.net/problem/28360

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0, edges = 0;
    double answer = 0;
    cin >> num >> edges;

    vector<double> water(num, 0);
    water[0] = 100;
    vector<vector<int>> graph(num, vector<int>());
    for (int i = 0, u = 0, v = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
    }

    for (int i = 0; i < num; i++) {
        if (graph[i].empty()) {
            answer = max(water[i], answer);
            continue;
        }
        for (int v : graph[i]) {
            water[v] += water[i] / graph[i].size();
        }
    }
    cout << answer << endl;

    return 0;
}
