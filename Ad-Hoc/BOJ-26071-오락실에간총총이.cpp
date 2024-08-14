// BOJ-26071 / 오락실에 간 총총이
// devgeon, 2024.08.14, C++17
// https://www.acmicpc.net/problem/26071

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, answer = 0;
    int top = 0, bottom = 0, left = 0, right = 0;
    cin >> num;
    top = num, left = num;

    for (int r = 0; r < num; r++) {
        cin.get();
        for (int c = 0; c < num; c++) {
            if (cin.get() == '.') {
                continue;
            }
            top = min(top, r);
            bottom = max(bottom, r);
            left = min(left, c);
            right = max(right, c);
        }
    }

    if (top != bottom) {
        answer += min(num - top - 1, bottom);
    }
    if (left != right) {
        answer += min(num - left - 1, right);
    }
    cout << answer << endl;

    return 0;
}
