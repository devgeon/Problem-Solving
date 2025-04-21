// BOJ-21919 / 소수 최소 공배수
// devgeon, 2024.04.21, C++17
// https://www.acmicpc.net/problem/21919

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int len = 0, num = 0;
    cin >> len;

    long long answer = 1;
    for (int i = 0; i < len; i++) {
        cin >> num;
        if (num != 2 && (num & 1) == 0) {
            continue;
        }
        for (int j = 3; j * j <= num; j += 2) {
            if (num % j == 0) {
                num = 1;
                break;
            }
        }
        if (num != 1 && answer % num != 0) {
            answer *= num;
        }
    }
    cout << (answer != 1 ? answer : -1) << endl;

    return 0;
}
