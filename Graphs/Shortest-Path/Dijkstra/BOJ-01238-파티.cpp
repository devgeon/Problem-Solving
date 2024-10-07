// BOJ-01238 / 파티
// devgeon, 2024.10.07, C++17
// https://www.acmicpc.net/problem/1238

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Road {
  public:
    int dest = 0;
    int time = 0;

    Road(int dest, int time) {
        this->dest = dest;
        this->time = time;
    }
};

class Element {
  public:
    int pos = 0;
    int time = 0;

    Element(int pos, int time) {
        this->pos = pos;
        this->time = time;
    }

    bool operator<(const Element &element) const {
        return this->time > element.time;
    }
};

void dijkstra(vector<vector<Road>> &adj_list, vector<int> &result, int start) {
    vector<bool> visited(adj_list.size(), false);
    priority_queue<Element> min_heap;
    min_heap.emplace(start, 0);
    result[start] = 0;

    while (min_heap.size()) {
        int pos = min_heap.top().pos;
        min_heap.pop();
        if (visited[pos]) {
            continue;
        }

        for (const Road &road : adj_list[pos]) {
            if (result[road.dest] > result[pos] + road.time) {
                result[road.dest] = result[pos] + road.time;
                min_heap.emplace(road.dest, result[road.dest]);
            }
        }
        visited[pos] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = 10'000 * 100 + 1;
    int num_of_villages = 0, num_of_roads = 0, party_place = 0;
    int from = 0, to = 0, time = 0, answer = 0;
    cin >> num_of_villages >> num_of_roads >> party_place;
    party_place--;

    vector<vector<Road>> adj_list_forward(num_of_villages, vector<Road>());
    vector<vector<Road>> adj_list_backward(num_of_villages, vector<Road>());
    for (int i = 0; i < num_of_roads; i++) {
        cin >> from >> to >> time;
        from--, to--;
        adj_list_forward[from].emplace_back(to, time);
        adj_list_backward[to].emplace_back(from, time);
    }

    vector<int> result_forward(num_of_villages, INF);
    vector<int> result_backward(num_of_villages, INF);
    dijkstra(adj_list_forward, result_forward, party_place);
    dijkstra(adj_list_backward, result_backward, party_place);

    for (int i = 0; i < num_of_villages; i++) {
        answer = max(answer, result_forward[i] + result_backward[i]);
    }
    cout << answer << endl;

    return 0;
}
