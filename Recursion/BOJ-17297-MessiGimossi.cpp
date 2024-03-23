// BOJ-17297 / Messi Gimossi
// devgeon, 2024.03.23, C++17
// https://www.acmicpc.net/problem/17297

#include <iostream>
#include <vector>

using namespace std;

void solve(int num);

int main() {
    int num = 0;
    cin >> num;

    solve(num - 1);

    return 0;
}

void solve(int num) {
    vector<int> cache(3, 0);

    if (num < 13) {
        if (num == 5 || num == -1) {
            cout << "Messi Messi Gimossi" << endl;
        } else {
            cout << "Messi Gimossi"[num] << endl;
        }
        return;
    }

    cache[0] = 5;
    cache[1] = 13;
    for (int i = 2;; i++) {
        cache[i % 3] = cache[(i + 1) % 3] + cache[(i + 2) % 3] + 1;
        if (cache[i % 3] >= num) {
            solve(num - cache[(i + 2) % 3] - 1);
            break;
        }
    }
}
