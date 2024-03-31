// BOJ-02609 / 최대공약수와 최소공배수
// devgeon, 2024.03.31, C++17
// https://www.acmicpc.net/problem/2609

#include <iostream>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);
void swap(int &a, int &b);

int main() {
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;

    cout << gcd(num1, num2) << "\n";
    cout << lcm(num1, num2) << endl;

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
