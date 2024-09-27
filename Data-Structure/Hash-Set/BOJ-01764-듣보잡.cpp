// BOJ-01764 / 듣보잡
// devgeon, 2024.09.27, C++17
// https://www.acmicpc.net/problem/1764

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_of_first_heard = 0, num_of_first_seen = 0;
    string name = "";
    cin >> num_of_first_heard >> num_of_first_seen;

    vector<string> list;
    unordered_set<string> set;
    for (int i = 0; i < num_of_first_heard; i++) {
        cin >> name;
        set.insert(name);
    }

    for (int i = 0; i < num_of_first_seen; i++) {
        cin >> name;
        if (set.find(name) != set.end()) {
            list.push_back(name);
        }
    }
    sort(list.begin(), list.end());

    cout << list.size() << '\n';
    for (string name : list) {
        cout << name << '\n';
    }

    return 0;
}
