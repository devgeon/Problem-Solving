// BOJ-01629 / 곱셈
// devgeon, 2024.03.04, C++17
// https://www.acmicpc.net/problem/1629

#include <iostream>

using namespace std;

int solve(int num, int exp, int div);

int main() {
    int num = 0, exp = 0, div = 0;
    cin >> num >> exp >> div;

    cout << solve(num, exp, div) << endl;

    return 0;
}

int solve(int num, int exp, int div) {
    long long answer = 1;

    if (exp == 1) {
        return num % div;
    }

    answer = solve(num, exp / 2, div);
    if (exp % 2 == 1) {
        return (answer * answer % div) * num % div;
    } else {
        return answer * answer % div;
    }
}
