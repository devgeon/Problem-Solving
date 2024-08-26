// BOJ-08983 / 사냥꾼
// devgeon, 2024.08.26, C++17
// https://www.acmicpc.net/problem/8983

#include <iostream>
#include <set>

using namespace std;

bool check_range(set<int> &positions, int from, int to);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_positions = 0, num_animals = 0, maximum_range = 0, answer = 0;
    set<int> positions;

    cin >> num_positions >> num_animals >> maximum_range;
    for (int i = 0, pos = 0; i < num_positions; i++) {
        cin >> pos;
        positions.insert(pos);
    }

    for (int i = 0, x = 0, y = 0, range = 0; i < num_animals; i++) {
        cin >> x >> y;
        range = maximum_range - y;
        if (range < 0) {
            continue;
        }
        if (check_range(positions, x - range, x + range)) {
            answer++;
        }
    }
    cout << answer << endl;

    return 0;
}

bool check_range(set<int> &positions, int from, int to) {
    auto left = positions.lower_bound(from);
    auto right = positions.upper_bound(to);
    return left != right;
}
