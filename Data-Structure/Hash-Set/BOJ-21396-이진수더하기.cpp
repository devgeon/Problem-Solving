// BOJ-21396 / 이진수 더하기
// devgeon, 2024.12.11, C++17
// https://www.acmicpc.net/problem/21396

#include <iostream>
#include <unordered_map>

using namespace std;

void solve() {
    int num = 0, sum = 0;
    long long result = 0;
    cin >> num >> sum;

    unordered_map<int, int> counter;
    unordered_map<int, int>::iterator it;
    for (int i = 0, n = 0; i < num; i++) {
        cin >> n;
        counter[n]++;
    }

    for (const auto [n, cnt] : counter) {
        if (sum && (it = counter.find(n ^ sum)) == counter.end()) {
            continue;
        }
        result += (long long)cnt * (sum ? it->second : cnt - 1);
    }
    cout << (result >>= 1) << '\n';

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0;
    cin >> cases;

    while (cases--) {
        solve();
    }

    return 0;
}
