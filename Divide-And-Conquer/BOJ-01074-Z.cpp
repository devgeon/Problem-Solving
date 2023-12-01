// BOJ-01074 / Z
// devgeon, 2023.12.01, C++17
// https://www.acmicpc.net/problem/1074

#include <iostream>

using namespace std;

int main() {
    int pow = 0, row = 0, col = 0;
    cin >> pow >> row >> col;
    int result = 0, max = 0;

    while (row + col != 0) {
        pow = 1;
        max = row > col ? row : col;
        while (pow <= max) {
            pow <<= 1;
        }
        pow >>= 1;

        result += (2 * (row / pow) + (col / pow)) * pow * pow;
        row %= pow;
        col %= pow;
    }

    cout << result << endl;

    return 0;
}
