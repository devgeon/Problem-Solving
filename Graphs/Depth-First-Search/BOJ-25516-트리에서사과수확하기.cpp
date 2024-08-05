// BOJ-25516 / 거리가 k이하인 트리 노드에서 사과 수확하기
// devgeon, 2024.08.05, C++17
// https://www.acmicpc.net/problem/25516

#include <iostream>
#include <vector>

using namespace std;

int search(const vector<vector<int>> &graph, const vector<bool> &apple,
           const int position, const int limit);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, limit = 0, answer = 0;
    cin >> num >> limit;

    vector<vector<int>> graph(num, vector<int>());
    for (int i = 0, v = 0, u = 0; i < num - 1; i++) {
        cin >> v >> u;
        graph[v].push_back(u);
    }
    vector<bool> apple(num, false);
    for (int i = 0, b = 0; i < num; i++) {
        cin >> b;
        apple[i] = (bool)b;
    }

    answer = search(graph, apple, 0, limit);
    cout << answer << endl;

    return 0;
}

int search(const vector<vector<int>> &graph, const vector<bool> &apple,
           const int position, const int limit) {
    if (limit < 0) {
        return 0;
    }

    int result = (int)apple[position];
    for (int to : graph[position]) {
        result += search(graph, apple, to, limit - 1);
    }
    return result;
}
