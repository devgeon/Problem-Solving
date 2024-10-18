// BOJ-18132 / 내 이진트리를 돌려줘!!!
// devgeon, 2024.10.18, C++17
// https://www.acmicpc.net/problem/18132

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 5000, DIVISOR = 1'000'000'007;
    int cases = 0, num = 0;
    cin >> cases;

    vector<int> cache(MAX + 1, 0);
    cache[0] = 1, cache[1] = 2;
    for (int i = 2; i <= MAX; i++) {
        cache[i] = (cache[i - 1] * 2) % DIVISOR;
        for (int j = 1; j < i; j++) {
            cache[i] += ((long long)cache[j - 1] * cache[i - j - 1]) % DIVISOR;
            cache[i] %= DIVISOR;
        }
    }

    while (cases--) {
        cin >> num;
        cout << cache[num] << '\n';
    }

    return 0;
}
