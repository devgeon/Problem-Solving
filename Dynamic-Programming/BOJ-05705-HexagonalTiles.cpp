// BOJ-05705 / Hexagonal Tiles
// devgeon, 2024.12.28, C++17
// https://www.acmicpc.net/problem/5705

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 40;

    int num = 1;
    int cache[MAX + 1] = {1, 1};
    for (int i = 2; i <= MAX; i++) {
        cache[i] = cache[i - 2] + cache[i - 1];
    }

    while (cin >> num && num != 0) {
        cout << cache[num] << '\n';
    }

    return 0;
}
