// BOJ-29994 / Investigating Zeroes and Ones
// devgeon, 2024.07.06, C++17
// https://www.acmicpc.net/problem/29994

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int len = 0;
    long long answer = 0;
    int cur = 0, prev = 0, zeros = 0, ones = 0;
    cin >> len;

    for (int i = 0; i < len; i++) {
        cin >> cur;
        cur += prev;
        answer += (cur & 1 ? zeros : ones);
        cur & 1 ? ones++ : zeros++;
        prev = cur;
    }
    answer += ones;
    cout << answer << endl;

    return 0;
}
