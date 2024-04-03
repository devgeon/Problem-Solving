// BOJ-02748 / 피보나치 수 2
// devgeon, 2024.04.03, C++17
// https://www.acmicpc.net/problem/2748

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0;
    vector<long long> cache(3, 1LL);

    cin >> num;

    for (int i = 2; i < num; i++) {
        cache[i % 3] = cache[(i + 1) % 3] + cache[(i + 2) % 3];
    }
    cout << cache[(num - 1) % 3] << endl;

    return 0;
}
