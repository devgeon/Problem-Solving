// BOJ-11051 / 이항 계수 2
// devgeon, 2024.03.28, C++17
// https://www.acmicpc.net/problem/11051

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0, k = 0;
    cin >> n >> k;

    vector<vector<int>> cache(n + 1, vector<int>(k + 1, 1));
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < min(i, k + 1); j++) {
            cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % 10007;
        }
    }

    cout << cache[n][k] << endl;
    return 0;
}
