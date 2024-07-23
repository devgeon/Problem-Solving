// BOJ-01717 / 집합의 표현
// devgeon, 2024.07.23, C++17
// https://www.acmicpc.net/problem/1717

#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
  private:
    vector<int> roots;

  public:
    DisjointSet(const int num) {
        this->roots = vector<int>(num, 0);
        for (int i = 0; i < num; i++) {
            this->roots[i] = i;
        }
    }

    int find(const int v) {
        if (this->roots[v] == v) {
            return v;
        }
        return this->roots[v] = find(this->roots[v]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            this->roots[u] = v;
        }
    }

    bool is_in_same_set(const int u, const int v) {
        return find(u) == find(v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, total_cmds = 0;
    cin >> num >> total_cmds;

    DisjointSet disjoint_set(num + 1);
    for (int i = 0, cmd = 0, u = 0, v = 0; i < total_cmds; i++) {
        cin >> cmd >> u >> v;
        if (cmd == 0) {
            disjoint_set.merge(u, v);
            continue;
        }
        if (cmd == 1) {
            cout << (disjoint_set.is_in_same_set(u, v) ? "YES" : "NO") << '\n';
            continue;
        }
    }

    return 0;
}
