// BOJ-01912 / 연속합
// devgeon, 2024.05.06, C++17
// https://www.acmicpc.net/problem/1912

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, answer = 0;
    cin >> num;

    vector<int> cache(2, 0);

    cin >> cache[0];
    answer = cache[0];
    for (int i = 1; i < num; i++) {
        cin >> cache[i % 2];
        cache[i % 2] += max(0, cache[(i + 1) % 2]);
        answer = max(cache[i % 2], answer);
    }

    cout << answer << endl;
    return 0;
}
