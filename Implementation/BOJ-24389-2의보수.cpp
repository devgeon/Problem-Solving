// BOJ-24389 / 2의 보수
// devgeon, 2023.11.28, C++17
// https://www.acmicpc.net/problem/24389

#include <iostream>

using namespace std;

int main() {
    int n = 0, count = 2;
    cin >> n;
    int bit_not_n = ~n;
    if (n & 1) {
        count = 1;
    } else {
        for (int mask = 2; mask > 0; mask <<= 1) {
            if (!(bit_not_n & mask)) {
                break;
            }
            count++;
        }
    }
    cout << 32 - count << endl;

    return 0;
}
