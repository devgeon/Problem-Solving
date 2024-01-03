// BOJ-14675 / 단절점과 단절선
// devgeon, 2024.01.03, C++17
// https://www.acmicpc.net/problem/14675

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total = 0, input = 0, type = 0;
    cin >> total;
    vector<int> count_degree(total, 0);

    for (int i = 0; i < 2 * (total - 1); i++) {
        cin >> input;
        count_degree[input - 1]++;
    }

    cin >> total;
    for (int i = 0; i < total; i++) {
        cin >> type >> input;
        if (type == 1 && count_degree[input - 1] < 2) {
            cout << "no\n";
            continue;
        }
        cout << "yes\n";
    }

    return 0;
}
