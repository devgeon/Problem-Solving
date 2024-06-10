// BOJ-19564 / 반복
// devgeon, 2024.06.10, C++17
// https://www.acmicpc.net/problem/19564

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int answer = 1;
    char curr = 0, prev = 0;
    cin >> prev;

    while (true) {
        cin >> curr;
        if (cin.eof()) {
            break;
        }
        if (curr <= prev) {
            answer++;
        }
        prev = curr;
    }
    cout << answer << endl;

    return 0;
}
