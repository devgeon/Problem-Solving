// BOJ-26021 / K.O. Kids
// devgeon, 2024.06.28, C++17
// https://www.acmicpc.net/problem/26021

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char cur = 'L', input = 0;
    int len = 0, kids = 0, splash = 0;
    cin >> len >> kids;

    for (int i = 0; i < len; i++) {
        cin >> input;
        if (input != cur) {
            splash++;
            continue;
        }
        cur = (cur == 'L' ? 'R' : 'L');
    }
    cout << max(0, kids - splash) << endl;

    return 0;
}
