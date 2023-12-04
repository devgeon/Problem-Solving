// BOJ-01463 / 1로 만들기
// devgeon, 2023.12.04, C++17
// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    const int MAX = 1000001;
    cin >> n;
    vector<int> cache(n, MAX);

    cache[0] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 3 == 0) {
            cache[i - 1] = min(cache[i - 1], cache[i / 3 - 1] + 1);
        }
        if (i % 2 == 0) {
            cache[i - 1] = min(cache[i - 1], cache[i / 2 - 1] + 1);
        }
        cache[i - 1] = min(cache[i - 1], cache[i - 2] + 1);
    }

    cout << cache[n - 1];

    return 0;
}
