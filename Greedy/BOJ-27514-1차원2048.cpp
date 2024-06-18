// BOJ-27514 / 1차원 2048
// devgeon, 2024.06.18, C++17
// https://www.acmicpc.net/problem/27514

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_POWER = 62;
    int num = 0;
    long long input = 0LL, total = 0LL;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> input;
        total += input;
    }

    for (long long power = 1LL << MAX_POWER; power > -1; power >>= 1) {
        if (total & power) {
            cout << power << endl;
            break;
        }
    }

    return 0;
}
