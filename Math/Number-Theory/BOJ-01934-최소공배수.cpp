// BOJ-01934 / 최소공배수
// devgeon, 2024.04.20, C++17
// https://www.acmicpc.net/problem/1934

#include <iostream>

using namespace std;

int gcd(int a, int b);
void swap(int &a, int &b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, a = 0, b = 0;
    cin >> num;

    while (num--) {
        cin >> a >> b;
        cout << a * b / gcd(a, b) << '\n';
    }

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

void swap(int &a, int &b) {
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}
