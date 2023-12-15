// BOJ-11653 / 소인수분해
// devgeon, 2023.12.12, C++17
// https://www.acmicpc.net/problem/11653

#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    for (int i = 2; i <= n;) {
        if (n % i == 0) {
            cout << i << "\n";
            n /= i;
        } else {
            i++;
        }
    }

    return 0;
}
