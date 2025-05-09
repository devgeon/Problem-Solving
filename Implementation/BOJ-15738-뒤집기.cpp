// BOJ-15738 / 뒤집기
// devgeon, 2025.05.09, C++17
// https://www.acmicpc.net/problem/15738

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int len = 0, pos = 0, cnt = 0, oper = 0;

    cin >> len >> pos >> cnt;
    for (int i = 0; i < len; i++) {
        cin >> oper;
    }

    for (int i = 0; i < cnt; i++) {
        cin >> oper;
        if (pos <= oper) {
            pos = oper - pos + 1;
        } else if (len + oper + 1 <= pos) {
            pos = (len << 1) + oper - pos + 1;
        }
    }
    cout << pos << endl;

    return 0;
}
