// BOJ-16563 / 어려운 소인수분해
// devgeon, 2024.04.01, C++17
// https://www.acmicpc.net/problem/16563

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 2'237;
    int num = 0, input = 0;
    vector<bool> is_checked(MAX / 2, false);
    vector<int> primes = {2};

    for (int i = 3; i <= MAX; i += 2) {
        if (is_checked[i / 2]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i * 3; j <= MAX; j += i * 2) {
            is_checked[j / 2] = true;
        }
    }

    cin >> num;
    while (num--) {
        cin >> input;
        for (int p : primes) {
            if (p * p > input) {
                break;
            }
            while (input % p == 0) {
                cout << p << " ";
                input /= p;
            }
        }
        if (input != 1) {
            cout << input << " ";
        }
        cout << "\n";
    }

    return 0;
}
