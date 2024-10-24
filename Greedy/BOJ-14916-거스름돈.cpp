// BOJ-14916 / 거스름돈
// devgeon, 2024.10.24, C++17
// https://www.acmicpc.net/problem/14916

#include <iostream>

using namespace std;

int main() {
    int num = 0, count = 0;
    cin >> num;

    if (num == 1 || num == 3) {
        num = 0;
    }
    while (num % 5) {
        num -= 2;
        count++;
    }
    count += num / 5;
    cout << (count > 0 ? count : -1) << endl;

    return 0;
}
