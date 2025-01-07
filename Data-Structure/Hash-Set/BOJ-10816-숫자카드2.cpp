// BOJ-10816 / 숫자 카드 2
// devgeon, 2025.01.07, C++17
// https://www.acmicpc.net/problem/10816

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    unordered_map<int, int> counter;
    for (int i = 0, n = 0; i < num; i++) {
        cin >> n;
        counter[n]++;
    }

    cin >> num;
    for (int i = 0, n = 0; i < num; i++) {
        cin >> n;
        cout << counter[n] << ' ';
    }

    return 0;
}
