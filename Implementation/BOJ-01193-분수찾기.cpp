// BOJ-01193 / 분수찾기
// devgeon, 2025.07.25, C++17
// https://www.acmicpc.net/problem/1193

#include <iostream>

using namespace std;

int main() {
    int cnt = 0, num = 0;
    int row = 0, col = 0;
    cin >> num;

    for (cnt = 1; cnt < num; cnt++) {
        num -= cnt;
    }
    row = (cnt & 1 ? cnt - num + 1 : num);
    col = (cnt & 1 ? num : cnt - num + 1);

    cout << row << "/" << col << endl;
    return 0;
}
