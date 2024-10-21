// BOJ-01789 / 수들의 합
// devgeon, 2024.10.21, C++17
// https://www.acmicpc.net/problem/1789

#include <iostream>

using namespace std;

int main() {
    long long target = 0, num = 1, sum = 0;
    cin >> target;

    while (sum <= target) {
        sum += num;
        num++;
    }
    num -= 2;

    cout << num << endl;

    return 0;
}
