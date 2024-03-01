// BOJ-19699 / 소-난다!
// devgeon, 2024.03.01, C++17
// https://www.acmicpc.net/problem/19699

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve(vector<int> &weight, set<int> &selected, int limit,
           int index = 0, int count = 0, int sum = 0);

int main() {
    int num = 0, limit = 0;
    cin >> num >> limit;

    vector<int> weight(num, 0);
    set<int> selected;
    for (int &n : weight) {
        cin >> n;
    }

    solve(weight, selected, limit);

    if (selected.empty()) {
        cout << -1 << endl;
    } else {
        for (int n : selected) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}

void solve(vector<int> &weight, set<int> &selected, int limit,
           int index, int count, int sum) {
    if (count == limit) {
        for (int i = 2; i * i <= sum; i++) {
            if (sum % i == 0) {
                return;
            }
        }
        selected.insert(sum);
        return;
    }

    for (int i = index; i < weight.size(); i++) {
        solve(weight, selected, limit, i + 1, count + 1, sum + weight[i]);
    }
}
