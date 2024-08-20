// BOJ-30012 / 개구리 매칭
// devgeon, 2024.08.20, C++17
// https://www.acmicpc.net/problem/30012

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int start_pos = 0, num_of_frogs = 0, max_jump_dist = 0, cost_per_unit_dist = 0;
    int min_cost = 1'000'000'000, min_frog = 0;
    vector<int> frogs;

    cin >> start_pos >> num_of_frogs;
    frogs.reserve(num_of_frogs);
    for (int i = 0, pos = 0; i < num_of_frogs; i++) {
        cin >> pos;
        frogs.push_back(pos);
    }
    cin >> max_jump_dist >> cost_per_unit_dist;

    for (int i = 0, dist = 0, cost = 0; i < num_of_frogs; i++) {
        dist = abs(start_pos - frogs[i]);
        if (dist > max_jump_dist * 2) {
            cost = (dist - max_jump_dist * 2) * cost_per_unit_dist;
        } else {
            cost = max_jump_dist * 2 - dist;
        }
        if (cost < min_cost) {
            min_cost = cost;
            min_frog = i + 1;
        }
    }
    cout << min_cost << ' ' << min_frog << endl;

    return 0;
}
