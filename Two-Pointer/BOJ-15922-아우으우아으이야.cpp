// BOJ-15922 / 아우으 우아으이야!!
// devgeon, 2024.02.13, C++17
// https://www.acmicpc.net/problem/15922

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MIN = -1'000'000'000;
    int num = 0, length = 0, begin = MIN, end = MIN, x = 0, y = 0;

    cin >> num;
    while (num) {
        cin >> x >> y;
        if (end < x) {
            length += end - begin;
            begin = x;
        }
        end = max(y, end);
        num--;
    }
    length += end - begin;

    cout << length << endl;
    return 0;
}
