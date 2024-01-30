// BOJ-30009 / 포지션 제로
// devgeon, 2024.01.30, C++17
// https://www.acmicpc.net/problem/30009

#include <iostream>

using namespace std;

int main() {
    int x = 0, r = 0, num = 0, line = 0;
    int inside = 0, boundary = 0;
    cin >> num >> x >> r >> r;

    while (num) {
        cin >> line;
        if (x - r < line && line < x + r) {
            inside++;
        } else if (line == x - r || line == x + r) {
            boundary++;
        }
        num--;
    }

    cout << inside << ' ' << boundary << endl;
    return 0;
}
