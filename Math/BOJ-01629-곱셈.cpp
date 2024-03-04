// BOJ-01629 / 곱셈
// devgeon, 2024.03.04, C++17
// https://www.acmicpc.net/problem/1629

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0, exp = 0, div = 0, answer = 1;
    vector<long long> cache;

    cin >> num >> exp >> div;

    cache.push_back(num % div);
    for (int i = 1; pow(2, i) < exp; i++) {
        cache.push_back((cache[i - 1] * cache[i - 1]) % div);
    }

    for (int i = 0; i < cache.size(); i++) {
        if (exp & 1 << i) {
            answer = (answer * cache[i]) % div;
        }
    }

    cout << answer << endl;

    return 0;
}
