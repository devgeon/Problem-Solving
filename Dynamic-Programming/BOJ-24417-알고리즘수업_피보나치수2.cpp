// BOJ-24417 / 알고리즘 수업 - 피보나치 수 2
// devgeon, 2024.05.24, C++17
// https://www.acmicpc.net/problem/24417

#include <iostream>

using namespace std;

int count(int num);

int main() {
    int num = 0;
    cin >> num;
    cout << count(num) << ' ' << num - 2 << endl;
    return 0;
}

int count(int num) {
    const int DIVISOR = 1'000'000'007;
    int cache1 = 1, cache2 = 1, cache3 = 0;
    for (int i = 2; i < num; i++) {
        cache3 = (cache1 + cache2) % DIVISOR;
        cache1 = cache2;
        cache2 = cache3;
    }
    return cache3;
}
