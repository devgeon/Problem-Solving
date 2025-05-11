// BOJ-02824 / 최대공약수
// devgeon, 2025.05.11, C++17
// https://www.acmicpc.net/problem/2824

#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    const int MAX = 31'623;
    const int MOD = 1'000'000'000;

    int num = 0, input = 0;
    long long answer = 1LL;
    bool trimmed = false;

    map<int, int> primes;
    vector<bool> checked(MAX >> 1, false);
    primes[2] = 0;

    for (int i = 3; i <= MAX; i += 2) {
        if (checked[(i >> 1) - 1])
            continue;
        primes[i] = 0;
        for (int j = i * 3; j <= MAX; j += i << 1)
            checked[(j >> 1) - 1] = true;
    }

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> input;
        for (auto &elem : primes) {
            if (input < elem.first)
                break;
            while (!(input % elem.first)) {
                input /= elem.first;
                elem.second++;
            }
        }
        if (input > 1)
            primes[input]++;
    }

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> input;
        for (auto &elem : primes) {
            if (input < elem.first)
                break;
            while (!(input % elem.first)) {
                input /= elem.first;
                if (!elem.second)
                    continue;
                elem.second--;
                answer = answer * elem.first;
                if (answer >= MOD) {
                    trimmed = true;
                    answer %= MOD;
                };
            }
        }
    }

    if (trimmed)
        cout << setw(9) << setfill('0');
    cout << answer << endl;

    return 0;
}
