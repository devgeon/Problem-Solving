// BOJ-14567 / 선수과목 (Prerequisite)
// devgeon, 2024.03.20, C++17
// https://www.acmicpc.net/problem/14567

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_of_courses = 0, num_of_edges = 0, semester = 1;
    cin >> num_of_courses >> num_of_edges;

    vector<vector<int>> graph(num_of_courses, vector<int>());
    vector<int> incoming_edges(num_of_courses, 0);
    for (int i = 0, from = 0, to = 0; i < num_of_edges; i++) {
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        incoming_edges[to - 1]++;
    }

    vector<int> answer(num_of_courses, 0);
    queue<int> queue;

    do {
        for (int i = 0; i < num_of_courses; i++) {
            if (incoming_edges[i] == 0) {
                queue.push(i);
                incoming_edges[i] = -1;
            }
        }
        for (int i = 0, size = queue.size(); i < size; i++) {
            for (int to : graph[queue.front()]) {
                incoming_edges[to]--;
                if (incoming_edges[to] == 0) {
                    answer[to] = semester;
                    queue.push(to);
                    incoming_edges[to] = -1;
                }
            }
            graph[queue.front()].clear();
            queue.pop();
        }
        semester++;
    } while (!queue.empty());

    for (int n : answer) {
        cout << n + 1 << ' ';
    }
    cout << endl;

    return 0;
}
