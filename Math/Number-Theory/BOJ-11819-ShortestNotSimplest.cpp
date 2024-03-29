// BOJ-11819 / The Shortest does not Mean the Simplest
// devgeon, 2024.03.29, C++17
// https://www.acmicpc.net/problem/11819

#include <iostream>

using namespace std;

long long power(long long num, long long exp, long long div);
long long multiply(long long num1, long long num2, long long div);

int main() {
    long long num = 0, exp = 0, div = 0;
    cin >> num >> exp >> div;

    cout << power(num, exp, div) << endl;

    return 0;
}

long long power(long long num, long long exp, long long div) {
    long long answer = 1LL;
    if (exp == 1LL) {
        return num % div;
    }
    while (exp) {
        if (exp & 1LL) {
            answer = multiply(answer, num, div);
        }
        num = multiply(num, num, div);
        exp >>= 1;
    }
    return answer;
}

long long multiply(long long num1, long long num2, long long div) {
    long long answer = 0LL;
    if (num2 == 1LL) {
        return num1 % div;
    }
    while (num2) {
        if (num2 & 1LL) {
            answer = (answer + num1) % div;
        }
        num1 = (num1 + num1) % div;
        num2 >>= 1;
    }
    return answer;
}
