// BOJ-15965 / K번째 소수
// devgeon, 2024.03.31, C++17
// https://www.acmicpc.net/problem/15965

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 8'000'000;
    int k = 0;
    vector<bool> is_checked(MAX / 2, false);
    vector<int> primes = {2};

    cin >> k;
    primes.reserve(k);

    for (int i = 3; i < MAX; i += 2) {
        if (is_checked[i / 2]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i * 3; j < MAX; j += i * 2) {
            is_checked[j / 2] = true;
        }
    }

    cout << primes[k - 1] << endl;

    return 0;
}
