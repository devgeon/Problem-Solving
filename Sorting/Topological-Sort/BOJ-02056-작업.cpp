// BOJ-02056 / 작업
// devgeon, 2024.10.22, C++17
// https://www.acmicpc.net/problem/2056

#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &adj_list, vector<int> &est_time,
        vector<bool> &visited, int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, total_time = 0;
    cin >> num;

    vector<vector<int>> adj_list(num, vector<int>());
    vector<bool> visited(num, false);
    vector<int> est_time(num, 0);

    for (int i = 0, time = 0, pre_cnt = 0, task = 0; i < num; i++) {
        cin >> time >> pre_cnt;
        est_time[i] = time;
        while (pre_cnt--) {
            cin >> task;
            adj_list[task - 1].push_back(i);
        }
    }

    for (int node = 0, time = 0; node < num; node++) {
        if (visited[node]) {
            continue;
        }
        time = dfs(adj_list, est_time, visited, node);
        total_time = max(time, total_time);
    }
    cout << total_time << endl;

    return 0;
}

int dfs(vector<vector<int>> &adj_list, vector<int> &est_time,
        vector<bool> &visited, int node) {
    int total_time = 0, time = 0;
    visited[node] = true;

    for (int post_node : adj_list[node]) {
        if (visited[post_node]) {
            time = est_time[post_node];
        } else {
            time = dfs(adj_list, est_time, visited, post_node);
        }
        total_time = max(time, total_time);
    }
    est_time[node] += total_time;

    return est_time[node];
}
