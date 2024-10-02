// BOJ-01149 / RGB거리
// devgeon, 2024.10.02, C++17
// https://www.acmicpc.net/problem/1149

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int R = 0, G = 1, B = 2;
    int num = 0, answer = 0;
    cin >> num;

    vector<int> cost(3, 0);
    vector<vector<int>> cache(2, vector<int>(3, 0));

    for (int i = 0; i < num; i++) {
        cin >> cost[R] >> cost[G] >> cost[B];
        cache[i % 2][R] = cost[R] + min(cache[(i + 1) % 2][G], cache[(i + 1) % 2][B]);
        cache[i % 2][G] = cost[G] + min(cache[(i + 1) % 2][R], cache[(i + 1) % 2][B]);
        cache[i % 2][B] = cost[B] + min(cache[(i + 1) % 2][R], cache[(i + 1) % 2][G]);
    }

    answer = min({cache[(num + 1) % 2][R], cache[(num + 1) % 2][G], cache[(num + 1) % 2][B]});
    cout << answer << endl;

    return 0;
}
