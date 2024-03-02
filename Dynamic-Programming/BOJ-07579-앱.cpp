// BOJ-07579 / 앱
// devgeon, 2024.03.02, C++17
// https://www.acmicpc.net/problem/7579

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int total_apps = 0, total_costs = 0, required_memory = 0;
    cin >> total_apps >> required_memory;

    vector<int> used_memory(total_apps, 0);
    for (int &m : used_memory) {
        cin >> m;
    }
    vector<int> costs(total_apps, 0);
    for (int &c : costs) {
        cin >> c;
        total_costs += c;
    }
    vector<int> cache(total_costs + 1, 0);

    for (int i = 0; i < total_apps; i++) {
        for (int c = total_costs; c >= 0; c--) {
            if (c < costs[i]) {
                continue;
            }
            cache[c] = max(cache[c], cache[c - costs[i]] + used_memory[i]);
        }
    }

    for (int c = 0; c <= total_costs; c++) {
        if (cache[c] >= required_memory) {
            cout << c << endl;
            break;
        }
    }

    return 0;
}
