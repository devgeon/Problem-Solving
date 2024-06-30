// BOJ-27920 / 카드 뒤집기
// devgeon, 2024.06.30, C++17
// https://www.acmicpc.net/problem/27920

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, orig = 0;
    cin >> num;
    orig = num;
    num = (num & 1 ? num : num - 1);
    cout << "YES\n";

    for (int n = num - 1; n > 1; n -= 2) {
        cout << n << ' ';
    }
    cout << orig << ' ';
    for (int n = 1; n < orig; n += 2) {
        cout << n << ' ';
    }
    cout << '\n';

    if (num != orig) {
        cout << orig << ' ';
    }
    for (int n = 1, diff = num - 1; diff != 0;) {
        cout << n << ' ';
        n += diff;
        diff = (diff > 0 ? -diff + 1 : -diff - 1);
    }
    cout << (num + 1) / 2 << '\n';

    return 0;
}
