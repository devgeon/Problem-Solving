// BOJ-01106 / 호텔
// devgeon, 2025.09.07, C++17
// https://www.acmicpc.net/problem/1106

#include <bits/stdc++.h>

using namespace std;

int main() {
    int target, total_cities;
    vector<pair<int, int>> advertises;

    cin >> target >> total_cities;
    for (int i = 0; i < total_cities; i++) {
        int cost, customers;
        cin >> cost >> customers;
        advertises.emplace_back(cost, customers);
    }

    vector<int> cache(target + 1, INT_MAX);
    cache[0] = 0;

    for (const pair<int, int> &ad : advertises) {
        for (int i = 1; i <= target; i++) {
            if (cache[max(0, i - ad.second)] == INT_MAX)
                continue;
            cache[i] = min(cache[i], cache[max(0, i - ad.second)] + ad.first);
        }
    }

    cout << cache[target] << endl;

    return 0;
}
