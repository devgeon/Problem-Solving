// BOJ-02180 / 소방서의 고민
// devgeon, 2024.05.12, C++17
// https://www.acmicpc.net/problem/2180

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool fire_compare(const pair<int, int> &fire1, const pair<int, int> &fire2);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int divisor = 40'000;
    int num = 0, time = 0;
    cin >> num;

    vector<pair<int, int>> status;
    status.reserve(num);
    for (int i = 0, a = 0, b = 0; i < num; i++) {
        cin >> a >> b;
        if (b > 0) {
            status.emplace_back(a, b);
        }
    }
    sort(status.begin(), status.end(), fire_compare);

    for (auto fire : status) {
        time = ((fire.first + 1) * time + fire.second) % divisor;
    }
    cout << time << endl;

    return 0;
}

bool fire_compare(const pair<int, int> &fire1, const pair<int, int> &fire2) {
    return (fire1.second * fire2.first < fire1.first * fire2.second);
}
