// BOJ-16953 / A → B
// devgeon, 2025.01.08, C++17
// https://www.acmicpc.net/problem/16953

#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0, count = 1;
    cin >> a >> b;

    while (true) {
        if (a == b) {
            break;
        } else if (a > b) {
            count = -1;
            break;
        }

        if ((b & 1) == 0) {
            b >>= 1;
        } else if (b % 10 == 1) {
            b /= 10;
        } else {
            count = -1;
            break;
        }
        count++;
    }
    cout << count << endl;

    return 0;
}
