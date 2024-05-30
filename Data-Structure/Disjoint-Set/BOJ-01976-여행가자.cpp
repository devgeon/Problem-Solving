// BOJ-01976 / 여행 가자
// devgeon, 2024.05.30, C++17
// https://www.acmicpc.net/problem/1976

#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
  private:
    vector<int> roots;

  public:
    DisjointSet(const int num) {
        roots.reserve(num);
        for (int i = 0; i < num; i++) {
            roots.push_back(i);
        }
    }

    int find(const int vertex) {
        if (vertex == roots[vertex]) {
            return vertex;
        }
        return roots[vertex] = find(roots[vertex]);
    }

    void union_(const int vertex1, const int vertex2) {
        int root1 = find(vertex1), root2 = find(vertex2);
        if (root1 == root2) {
            return;
        }
        roots[root1] = root2;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, travel = 0;
    bool answer = true;
    cin >> num >> travel;

    DisjointSet disjoint_set(num);
    for (int i = 0, input = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> input;
            if (j < i || input == 0) {
                continue;
            }
            disjoint_set.union_(i, j);
        }
    }

    for (int i = 0, prev = 0, curr = 0; i < travel; i++) {
        if (i == 0) {
            cin >> prev;
            continue;
        }
        cin >> curr;
        if (disjoint_set.find(curr - 1) != disjoint_set.find(prev - 1)) {
            answer = false;
            break;
        }
        prev = curr;
    }
    cout << (answer ? "YES" : "NO") << endl;

    return 0;
}
