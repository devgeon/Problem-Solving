// BOJ-10157 / 자리배정
// devgeon, 2024.08.23, C++17
// https://www.acmicpc.net/problem/10157

#include <iostream>

using namespace std;

int main() {
    int row = 0, col = 0, num = 0, x = 0, y = 0;
    cin >> col >> row >> num;

    if (row * col < num) {
        cout << 0 << endl;
        return 0;
    } else if (num <= row) {
        cout << 1 << ' ' << num << endl;
        return 0;
    }

    x = 1, y = row;
    num -= row - 1;
    for (int i = 1; row > i || col > i; i++) {
        if (col - i < num) {
            num -= col - i;
            x += (i & 1 ? col - i : -col + i);
        } else {
            x += (i & 1 ? num - 1 : -num + 1);
            break;
        }
        if (row - i < num) {
            num -= row - i;
            y += (i & 1 ? -row + i : row - i);
        } else {
            y += (i & 1 ? -num + 1 : num - 1);
            break;
        }
    }
    cout << x << ' ' << y << endl;

    return 0;
}
