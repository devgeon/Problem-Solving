// BOJ-25344 / 행성 정렬
// devgeon, 2024.03.30, C++17
// https://www.acmicpc.net/problem/25344

#include <iostream>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);
void swap(int &a, int &b);

int main() {
    int num = 0, period = 0, answer = 1;
    cin >> num;

    for (int i = 0; i < num - 2; i++) {
        cin >> period;
        answer = lcm(answer, period);
    }
    cout << answer << endl;

    return 0;
}

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void swap(int &a, int &b) {
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}
