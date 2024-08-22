// BOJ-02776 / 암기왕
// devgeon, 2024.06.19, C++17
// https://www.acmicpc.net/problem/2776

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0;
    unordered_set<int> set;
    cin >> cases;

    for (int t = 0, num = 0; t < cases; t++) {
        set.clear();
        cin >> num;
        for (int i = 0, input = 0; i < num; i++) {
            cin >> input;
            set.insert(input);
        }
        cin >> num;
        for (int i = 0, input = 0; i < num; i++) {
            cin >> input;
            if (set.find(input) != set.end()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}
