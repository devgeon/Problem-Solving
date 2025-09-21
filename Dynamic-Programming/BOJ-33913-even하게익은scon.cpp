// BOJ-33913 / even 하게 익은 SCON
// devgeon, 2025.09.21, C++17
// https://www.acmicpc.net/problem/33913

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;
    vector<vector<long long>> cache(2, vector<long long>(2, 0));
    cache[0][0] = 2;
    cache[0][1] = 24;

    for (int i = 1; i < num; i++) {
        cache[i & 1][0] = (cache[(i - 1) & 1][0] * 24 + cache[(i - 1) & 1][1] * 2) % MOD;
        cache[i & 1][1] = (cache[(i - 1) & 1][0] * 2 + cache[(i - 1) & 1][1] * 24) % MOD;
    }
    cout << cache[(num - 1) & 1][1] << endl;

    return 0;
}
